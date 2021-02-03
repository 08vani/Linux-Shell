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
        int ret = rmdir(argv[i]);

        if(ret<0)
        {
            printf("\n%s Directory does not exist",argv[i]);
        }
        else
        {
            printf("\n%s Directory got deleted",argv[i]);
        }
     }
    }
    else if(strcmp(argv[1],"-v")==0)
    {
     for(int i=2;argv[i]!=NULL;i++)
     {
        int ret = rmdir(argv[i]);

        if(ret<0)
        {
            printf("\n%s Directory does not exist",argv[i]);
        }
        
     }

     printf("\n Directory got deleted");
    }

    else
    {
        for(int i=1;argv[i]!=NULL;i++)
        {
           int ret = rmdir(argv[i]);

           if(ret<0)
           {
               printf("\n%s Directory does not exist",argv[i]);
           }
           
        }

        
    }

    
	

   return 0;
}

