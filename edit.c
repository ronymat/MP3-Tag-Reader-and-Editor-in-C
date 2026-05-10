#include "mp3.h"

int mp3_edit(char *argv[],char *str_op)
{
    //open the orginal mp3 file
   FILE *fp=fopen(argv[4],"rb");//open the sample mp3 file in binary mode
  if(fp==NULL)//check it is open or not
  {
    printf("Error: Failed to open file\n");
    return FAILURE;
  }
  //open duplicate mp3 file in write mode
  FILE *dup_fp=fopen("duplicate.mp3","wb");//open the sample mp3 file in binary mode
  if(dup_fp==NULL)//check it is open or not
  {
    printf("Error: Failed to open file\n");
    return FAILURE;
  }
  //copy the data from orginal file to duplicate file
  //read and wwrite the first 10 bytes of headder
  char arr[10];
  fread(arr,sizeof(char),10,fp);
  fwrite(arr,1,10,dup_fp);

    //read the tag
    char tag[5];
  while(fread(tag,1,4,fp)==4)
  {
    tag[4]='\0';

    //read the size
    int size; 
    if(fread(&size, 4, 1, fp) != 1)
    break;
    //here we get size in big endian format so we need to convert it to little endian
    char *p=(char*)&size;
    char temp;
    temp=p[0];
    p[0]=p[3];
    p[3]=temp;
    temp=p[1];
    p[1]=p[2];
    p[2]=temp;
    //read the flag
    char flags[2];
    fread(flags,1,2,fp);

    //check the tag with the str_op
    if(strcmp(tag,str_op)==0)
    {
      fwrite(tag,1,4,dup_fp);//write tag
      //get size of new content
      char *new_data =argv[3];
      int new_size=strlen(new_data)+1;
      
         //convert back to little endian
         //here we get size in big endian format so we need to convert it to little endian
        int b_size=new_size; 
      char *p2=(char*)&b_size;
      char temp2;
      temp2=p2[0];
      p2[0]=p2[3];
      p2[3]=temp2;
      temp2=p2[1];
      p2[1]=p2[2];
      p2[2]=temp2;
        
        fwrite(&b_size,4,1,dup_fp);//write size
         // write flags
        fwrite(flags, 1, 2, dup_fp);
      //write the null character / encoding byte
      char encoding = 0x00;
      fwrite(&encoding, 1, 1, dup_fp);
      //write the new content to the duplicate file
      fwrite(new_data, 1, strlen(new_data), dup_fp);
      //Move the file offset to the next tag (skip old data)
      fseek(fp, size, SEEK_CUR);
      break;
    }
    else//copy case
    {
        fwrite(tag,1,4,dup_fp);//write tag
        //convert back to little endian
        int b_size=size; 
      //here we get size in big endian format so we need to convert it to little endian
      char *p2=(char*)&b_size;
      char temp2;
     temp2=p2[0];
      p2[0]=p2[3];
      p2[3]=temp2;
      temp2=p2[1];
      p2[1]=p2[2];
      p2[2]=temp2;
        
        fwrite(&b_size,4,1,dup_fp);//write size
        fwrite(flags,1,2,dup_fp);//write flags
        
        //based on size we need to read content and write it

      char ch;
      for(int i=0;i<size;i++)
      {
        fread(&ch,1,1,fp);
        fwrite(&ch,1,1,dup_fp);
      }
    }
  }
      //Read and write the remaining contents from original.mp3 to duplicate.mp3
    char ch;
    while (fread(&ch, 1, 1, fp) == 1)
    {
        fwrite(&ch, 1, 1, dup_fp);
    }

    //close both files
    fclose(fp);
    fclose(dup_fp);

    //remove the original file
    remove(argv[4]);

    //rename the duplicate file as original file
    rename("duplicate.mp3", argv[4]);
    printf("Edited successfully...\n");
    return SUCCESS;
}