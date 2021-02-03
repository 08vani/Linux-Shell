#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<readline/readline.h> 
#include<readline/history.h> 
#include <inttypes.h>
#include <dirent.h>





#define MAXNAME 1000// Any user name can not have more than 1000 charecter
#define MAXARGS 100// Maximum arguments that can be passed to a function 



void display_welcome(void);
void get_command();
void command_handler();
void call_cd();
void call_pwd();
void call_echo();
void call_ls();
void call_rm();
void call_mkdir();
void call_cat();
void call_date();
void insert_history();
void call_history();

int main()
{
	char input[MAXNAME];

	display_welcome();

	int val=0;

	// FILE *fp;

	// fp= fopen("/home/vanisikka/Desktop/Assignment_2/History.txt", "a+");


	//printf("%s\n",input);

	while(val==0)
	{
		
		
		get_command(input);

		//fprintf(fp, "%s", input);

		insert_history(input);

		char*  I=strtok(input,"\n");

		*((I+strlen(I)))=' ';

		//printf("'%s'\n",I );

		char *args[MAXARGS];

		char *tok= strtok(I," ");

		int i=0;

		while(tok!=NULL)
		{
			args[i]=tok;
			tok=strtok(NULL," ");
			i=i+1;
		}

		if(strcmp(args[0],"exit")==0)
		{
			if(i==1)
			{
				val=1;
			}
			else if(i==2)
			{
				if(strcmp(args[1],"--help")==0)
				{
					printf("\n THis is used to exit the shell, it does not take any arguments");
				}
				else
				{
					printf("\nInvalid command");
				}
			}
			
			
		}
		else if(strcmp(args[0],"cd")==0)
		{
			if(i<=3)
			{
				call_cd(args,i);
			}			
			else
			{
				printf("\nInvalid Command");
			}
			
		}
		else if(strcmp(args[0],"pwd")==0)
		{
			if(i<=2)
			{
				call_pwd(args,i);
			}
			else
			{
				printf("\nInvalid Command");
			}
			
		}
		else if(strcmp(args[0],"echo")==0)
		{
			call_echo(args,i);
		}
		else if(strcmp(args[0],"ls")==0)
		{
			if(i<=3)
			{
				call_ls(args,i);
			}
			else
			{
				printf("\nInvalid Command");
			}
			
		}
		else if(strcmp(args[0],"rm")==0)
		{
			if(i>1)
			{
				call_rm(args,i);
			}
			else
			{
				printf("\nInvalid Command");
			}
			
		}
		else if(strcmp(args[0],"mkdir")==0)
		{
			if(i>1)
			{
				call_mkdir(args,i);
			}
			else
			{
				printf("\nInvalid Command");
			}
			
		}
		else if(strcmp(args[0],"cat")==0)
		{
			if(i>1)
			{
				call_cat(args,i);
			}
			else
			{
				printf("\nInvalid Command");
			}
			
		}
		else if(strcmp(args[0],"date")==0)
		{
			if(i<=3)
			{
				call_date(args,i);
			}
			else
			{
				printf("\nInvalid Command");
			}
			
		}
		else if(strcmp(args[0],"history")==0)
		{
			if(i<=2)
			{
				call_history(args,i);
			}
			else
			{
				printf("\nInvalid Command");
			}
			
		}
		else
		{
			printf("Command not recoganised");
		}

	}

	return 0;
}

void display_welcome(void)
{
	// THis function simply displays the starting messge when the shell is started
	printf("###############||Welcome To Shell||############\n");
}

void insert_history(char *input)
{

	FILE *fp;

	fp= fopen("/home/vanisikka/Desktop/Assignment_2/History.txt", "a+");

	fprintf(fp, "%s", input);

	

	fclose(fp);

}

void get_command(char * val)
{
	
    size_t bufsize = 1000;

    char cwd[1024];

   
    getcwd(cwd,sizeof(cwd));

	printf("\n%s",cwd);

    printf(">>>");

    getline(&val,&bufsize,stdin);

    //strcpy(val,buffer);
    
    //printf("You typed: %s\n",val);

}

void call_cd(char *buffer[],int i)
{
	/*THis fuction calls the chdir system call which 
	helps in changing the current directory to the directory specified
	but if the directory does not exist it should give an error saying so
	it also implements -L and -P flag.
	*/

	char *dir=buffer[1];

	int e=0;

	if(i==1)
	{
		dir="/home/vanisikka";
		if(i==3)
		{
			e=1;
		}
	}
	else if(strcmp(dir,"-P")==0 )
	{
		dir="/";

		if(i==3)
		{
			e=1;
		}

	}
	else if(strcmp(dir,"-L")==0)
	{
		if(i==2)
		{
			e=1;
		}
		else
		{
			dir=buffer[2];
		}
		
	}
	else if(strcmp(dir,"~")==0)
	{
		dir="/home/vanisikka";
		if(i==3)
		{
			e=1;
		}
	}

	int ch=0;

	if(e==0)
	{
		ch=chdir(dir);
	}

	else
	{
		printf("Invalid Command");
	}
	
	
	if(ch<0)
		perror(dir);
	

}

void call_history(char *buffer[],int i)
{
	if(i==1)
	{
		FILE *fp;

		int c;

		fp=fopen("/home/vanisikka/Desktop/Assignment_2/History.txt","r");

		while((c=getc(fp))!=EOF)
		{
		    printf("%c",c );
		}

		fclose(fp);
	}
	if(i==2)
	{
		if(strcmp(buffer[1],"--help")==0)
		{
			printf("\n I will fill it after some time");
		}
		else if(strcmp(buffer[1],"-c")==0)
		{
			FILE *fp;

			fp=fopen("/home/vanisikka/Desktop/Assignment_2/History.txt","w");

			fclose(fp);
		}
		else
		{
			printf("\n Invalid option");
		}
	}

}

void call_pwd(char *buffer[],int i)
{
	/*   THis function take the whole parameters and flags as parameters. 
	Then sile it on the basis of the space between then(this is requsite from the user)
	then depending on the flag getcwd system call is made which returns the current working directory in 
	string format*/

	char cwd[1024];

	
	if(i==1)
	{
		getcwd(cwd,sizeof(cwd));

		printf("\n%s",cwd);
	}
	else if(strcmp(buffer[1],"-L")==0)
	{
		getcwd(cwd,sizeof(cwd));

		printf("\n%s",cwd);
	}
	else if(strcmp(buffer[1],"--help")==0)
	{
		printf("I have to fill the help part \n");
	}
	else if(strcmp(buffer[1],"-P")==0)
	{
		getcwd(cwd,sizeof(cwd));

		printf("\n%s",cwd);
	}
	else
	{
		printf("\npaased input for pwd not recoganised");
	}

	// char *path;
	// char *sym_path;

	// path= getcwd(3);

	// // // sym_path=realpath(path, NULL);

	// // // free(path);

	// // sym_path = realpath(cwd, NULL);
	// // char *canon_dir = strdup(dirname(sym_path));
	// // free(sym_path);
	    
	// printf("\n actual path: %s",path );

}

void call_echo(char *buffer[],int i)
{
	int flag=0;

	printf("\n");

	if(i>=2)
	{
		if(strcmp(buffer[1],"-E")==0)
		{
			for (int k = 2; k < i; k++)
			{
				printf("%s ",buffer[k] );
			}
		}
		else if(strcmp(buffer[1],"-e")==0)
		{
			//if time permit implement it
		}
		else if(strcmp(buffer[1],"--help")==0)
		{
			printf("\n I will fill it after some time");
		}
		else
		{
			flag=1;
		}
	}

	if(flag==1)
	{
		for (int k = 1; k < i; k++)
		{
			printf("%s ",buffer[k] );
		}
	}

}

void call_ls(char *buffer[],int i)
{
	pid_t pid;
	int status;

	/* Fork a child process */
	pid=fork();

	if(pid<0){
		printf("fork failled");
	}
	else if(pid==0)/* child process code */
	{
			
			int val=0;
			
			//printf("child started");

			buffer[0]="/home/vanisikka/Desktop/Assignment_2/ls";

			buffer[i]=NULL;

			val= execv("/home/vanisikka/Desktop/Assignment_2/ls",buffer);

		    if(val==-1)
		    {
		    	printf("error at execv has occured\n");
		    }


	}
	else
	{
		wait(NULL);
		//printf("child finished");
		
	}
	
}

void call_rm(char *buffer[],int i)
{
	pid_t pid;
	int status;

	/* Fork a child process */
	pid=fork();

	if(pid<0){
		printf("fork failled");
	}
	else if(pid==0)/* child process code */
	{
			
			int val=0;

			buffer[0]="/home/vanisikka/Desktop/Assignment_2/rm";

			buffer[i]=NULL;

			val= execv("/home/vanisikka/Desktop/Assignment_2/rm",buffer);

		    if(val==-1)
		    {
		    	printf("error at execv has occured\n");
		    }


	}
	else
	{
		wait(NULL);
		//printf("child finished");
		
	}
	
}

void call_mkdir(char *buffer[],int i)
{
	pid_t pid;
	int status;

	/* Fork a child process */
	pid=fork();

	if(pid<0){
		printf("fork failled");
	}
	else if(pid==0)/* child process code */
	{
			
			int val=0;

			buffer[0]="/home/vanisikka/Desktop/Assignment_2/mkdir";

			buffer[i]=NULL;

			val= execv("/home/vanisikka/Desktop/Assignment_2/mkdir",buffer);


		    if(val==-1)
		    {
		    	printf("error at execv has occured\n");
		    }


	}
	else
	{
		wait(NULL);
		//printf("child finished");
		
	}
	
}

void call_cat(char *buffer[],int i)
{
	pid_t pid;
	int status;

	/* Fork a child process */
	pid=fork();

	if(pid<0){
		printf("fork failled");
	}
	else if(pid==0)/* child process code */
	{
			
			int val=0;

			buffer[0]="/home/vanisikka/Desktop/Assignment_2/cat";

			buffer[i]=NULL;

			val= execv("/home/vanisikka/Desktop/Assignment_2/cat",buffer);

		    if(val==-1)
		    {
		    	printf("error at execv has occured\n");
		    }


	}
	else
	{
		wait(NULL);
		//printf("child finished");
		
	}
	
}

void call_date(char *buffer[],int i)
{
	pid_t pid;
	int status;

	/* Fork a child process */
	pid=fork();

	if(pid<0){
		printf("fork failled");
	}
	else if(pid==0)/* child process code */
	{
			
			int val=0;

			buffer[0]="/home/vanisikka/Desktop/Assignment_2/date";

			buffer[i]=NULL;

			val= execv("/home/vanisikka/Desktop/Assignment_2/date",buffer);

		    if(val==-1)
		    {
		    	printf("error at execv has occured\n");
		    }


	}
	else
	{
		wait(NULL);
		//printf("child finished");
		
	}
	
}