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

void help();


int main(int argc,char*argv[]) {


    if(argv[1]==NULL)
    {
        
        char *args[]= { "ls",".","dot",NULL};

        help(args);
    }
    else if(argv[2]==NULL)
    {
        if(argv[1][0]=='-')
        {
            //check for passed options
            char *op=argv[1];

            if(strcmp(op,"-1")==0|| strcmp(op,"-i")==0)
            {
                char *args[]= { "ls",".",argv[1],NULL};

                help(args);
            }
            else
            {
                printf("Invalid option");
            }
        }
        else
        {
            char *args[]= { "ls",argv[1],"dot",NULL};

            help(args);
        }
    }
    else if(argv[3]==NULL)
    {
        if(argv[1][0]=='-')
        {
            //check for passed options
            char *op=argv[1];

            if(strcmp(op,"-1")==0|| strcmp(op,"-i")==0)
            {
                char *args[]= { "ls",argv[2],argv[1],NULL};

                help(args);
            }
            else
            {
                printf("Invalid option");
            }
        }
        else
        {
            char *op=argv[2];

            if(strcmp(op,"-1")==0|| strcmp(op,"-i")==0)
            {
                char *args[]= { "ls",argv[1],argv[2],NULL};

                help(args);
            }
            else
            {
                printf("Invalid option");
            }
        }
    }



    
   return 0;
}

void help(char*argv[])
{
        struct dirent *d;

        DIR *dh= opendir(argv[1]);

        if(!dh)
        {
            if(errno==ENOENT)
            {
                perror("Directory not Found");
            }
            else
            {
                perror("Unable to read directory");
            }
            exit(1);
        }

        if(strcmp(argv[2],"-1")==0)
        {
            while((d=readdir(dh))!=NULL)
            {
                if(d-> d_name[0]=='.')continue;
                printf("%s\n",d->d_name );
            }
        }
        else if(strcmp(argv[2],"-i")==0)
        {
            while((d=readdir(dh))!=NULL)
            {
                if(d-> d_name[0]=='.')continue;
                printf("%ld :",d->d_ino);
                printf("%s |||",d->d_name);
            }
        }
        else if(strcmp(argv[2],"dot")==0)
        {
            while((d=readdir(dh))!=NULL)
            {
                if(d-> d_name[0]=='.')continue;
                printf("%s    ",d->d_name );
            }
        }
        else
        {
            printf("Invalid option");
        }

        

        printf("\n");

}