#include <stdio.h>
#include <inttypes.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include <string.h>
#include<readline/readline.h> 
#include<readline/history.h> 
#include<stdlib.h>
#include <dirent.h>
#include<errno.h>
#include<sys/stat.h>




int main(int argc,char*argv[]) {

    if(strcmp(argv[1],"-i")==0)
    {
     for(int i=2;argv[i]!=NULL;i++)
     {
        int ret = ret= mkdir(argv[i],S_IRUSR | S_IRGRP | S_IROTH | S_IXUSR | S_IXGRP | S_IXOTH | S_IWUSR);

        if(ret<0)
        {
            printf("\n%s Directory could not be made",argv[i]);
        }
        else
        {
            printf("\n%s Directory made",argv[i]);
        }
        
     }


    }
    else if(strcmp(argv[1],"-v")==0)
    {
     for(int i=2;argv[i]!=NULL;i++)
     {
        int ret = ret= mkdir(argv[i],S_IRUSR | S_IRGRP | S_IROTH | S_IXUSR | S_IXGRP | S_IXOTH | S_IWUSR);

        if(ret<0)
        {
            printf("\n%s Directory could not be made",argv[i]);
        }
       
     }

     printf("\nDirectory made");
        


    }

    else
    {
        for(int i=1;argv[i]!=NULL;i++)
        {
           int ret = ret= mkdir(argv[i],S_IRUSR | S_IRGRP | S_IROTH | S_IXUSR | S_IXGRP | S_IXOTH | S_IWUSR);

                     
        }
    }

        


	// int ret;
 
	// ret= mkdir(dir,S_IRUSR | S_IRGRP | S_IROTH | S_IXUSR | S_IXGRP | S_IXOTH | S_IWUSR);

	// ls();

   return 0;
}

