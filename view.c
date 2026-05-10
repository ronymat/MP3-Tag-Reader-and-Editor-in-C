#include "mp3.h"

int mp3_view(char *argv[])
{
    printf("\n-----------------VIEW SELECTED-----------------\n");
  FILE *fp=fopen(argv[2],"rb");//open the sample mp3 file
  if(fp==NULL)//check it is open or not
  {
    printf("Error: Failed to open file\n");
    return FAILURE;
  }
  //fetch the first 3 bytes from file(headder id)

  char buf[4];
  fread(buf,sizeof(char),3,fp); 
  buf[3]='\0';
  
  //compare buffer with "ID3" check it is mp3 file or not
  if(strcmp(buf,"ID3")==0)
  {
   printf("It is a MP3 file...\n");
  }else
  {
    printf("Error: It is not a MP3 File !!!\n");
    return FAILURE;
  }

   //move the filepointer 7 bytes from ID3
   fseek(fp,7,SEEK_CUR);
   for(int i=0;i<6;i++)//need to run the loop 6 tymes to print the tags
  { //read the 4 byte of tag
   char tag[5];
   fread(tag,sizeof(char),4,fp);
   tag[4]='\0';
   //read the size of content(4 byte)
   int size; 
   fread(&size,sizeof(int),1,fp);
   //here we get size in big endian format so we need to convert it to little endian
   char *p=(char*)&size;
   char temp;
   temp=p[0];
   p[0]=p[3];
   p[3]=temp;
   temp=p[1];
   p[1]=p[2];
   p[2]=temp;
   //skip 2 more bytes
   fseek(fp,2,SEEK_CUR);
   // read encoding byte 
   char encoding;
   fread(&encoding,1,1,fp);
    size--;   // remove encoding byte
   //read the frame contents
   char content[size+1];
   //read one by one byte to content
   fread(content,sizeof(char),size,fp);
   content[size]='\0';
   printf("%d.%-5s ---> %s\n",i+1,tag,content);
}
fclose(fp);
return SUCCESS;
}