#include "mp3.h"

int main(int argc,char *argv[])
{
  printf("===============================================\n");
  printf("            MP3 TAG READER & EDITOR           ");
  printf("\n===============================================\n");
   //to print usage if no arguments
    if(argc==1 )
    {
      invalid_print();
      return FAILURE;
    }
    //to print help
   else if(argc==2 && strcmp(argv[1],"--help")==0)
    {
        print_help();
        return SUCCESS;
    }
    //to view 
   else if(argc==3 && strcmp(argv[1],"-v")==0)
    {
        if(mp3_view(argv)==FAILURE)
        {
            printf("Error: Failed to view the contents !!!\n");
            return FAILURE;
        }else
        return SUCCESS;

    }
    //to edit
    else if (argc>=5 && strcmp(argv[1],"-e")==0)
    {
        char str[5];
        if(strcmp(argv[2],"-t")==0)
        {
           strcpy(str,"TIT2");
        }
        else if (strcmp(argv[2],"-a")==0)
        {
         strcpy(str,"TPE1");
        }
         else if (strcmp(argv[2],"-A")==0)
        {
           strcpy(str,"TALB");
        }
         else if (strcmp(argv[2],"-y")==0)
        {
           strcpy(str,"TYER");
       } 
         else if (strcmp(argv[2],"-m")==0)
        {
           strcpy(str,"TCON");
        }
         else if (strcmp(argv[2],"-c")==0)
        {
           strcpy(str,"COMM");
        }
        else
        {
            invalid_print();
            return FAILURE;
        }  
       return mp3_edit(argv, str);   
    }
    else
    invalid_print();
    return FAILURE;
}