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

void nread_file();
void eread_file();
void read_file();



int main(int argc,char*argv[]) {

    if(argv[2]==NULL)
    {
        read_file(argv[1]);
    }
    else if(strcmp(argv[1],"-n")==0)
    {
        //printf("%s\n", argv[2]);
        nread_file(argv[2]);
    }
    else if(strcmp(argv[1],"-E")==0)
    {
        eread_file(argv[2]);
    }
    else
    {
        for(int i=1;argv[i]!=NULL;i++)
        {
            read_file(argv[i]);
        }
    }
    

	

    return 0;
}

void nread_file(char *dir)
{

    FILE *fp;

    int c;

    fp=fopen(dir,"r");

    if(fp==NULL)
    {
        printf("No such file exist in the directory");

        exit(1);
    }

    int counter=1;

    while((c=getc(fp))!=EOF)
    {
        if(c=='\n')
        {
            counter=counter+1;
            printf("%c",c );
            printf("%d",counter);
        }
        else
        {
            printf("%c",c );
        }
        
    }

    fclose(fp);
    

}

void eread_file(char *dir)
{

    FILE *fp;

    int c;

    fp=fopen(dir,"r");

    if(fp==NULL)
    {
        printf("No such file exist in the directory");

        exit(1);
    }

    int counter=1;

    while((c=getc(fp))!=EOF)
    {
        if(c=='\n')
        {
            counter=counter+1;
            printf("$");
            printf("%c",c );
        }
        else
        {
            printf("%c",c );
        }
        
    }

    fclose(fp);
    

}

void read_file(char *dir)
{

    FILE *fp;

    int c;

    fp=fopen(dir,"r");

    if(fp==NULL)
    {
        printf("No such file exist in the directory");

        exit(1);
    }

    while((c=getc(fp))!=EOF)
    {
        printf("%c",c );
    }

    fclose(fp);
    

}

// void creat_file(char *dir)
// {
//     FILE *fp;

//     fp=fopen(dir,"w");

//     fclose(fp);
// }

// void copy(char* from, char* to)
// {
//     FILE *fp1, *fp2;

//     fp1=fopen(from,"r");

//     fp2=fopen(to,"w");

//     if(fp1==NULL)
//     {
//         printf("\n Source File does not exist");

//         exist(1);
//     }

//     int c;

//     while((c=getc(fp1))!=EOF)
//     {
//         fputs(c, fp2);
//     }

//     fclose(fp1);
//     fclose(fp2);

// }
