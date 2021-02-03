#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

void display_date();
void display_date_r();
void display_date_u();

int main(int argc,char*argv[]){

	if(argv[1]==NULL)
	{
		display_date();
	}
	else if(strcmp(argv[1],"-u")==0)
	{
		if(argv[2]==NULL)
		{
			display_date_u();
		}
		else
		{
			printf("\nInvalid command");
		}
		

	}
	else if(strcmp(argv[1],"-r")==0)
	{
		
		
		if(argv[3]==NULL)
		{
			display_date_r(argv[2]);
		}
		else
		{
			printf("\nInvalid command");
		}
	
	}
	else if(strcmp(argv[1],"--help")==0)
	{
		printf("\n I will fill it after some time");
	}
	else
	{
		printf("\n Invalid Option");
	}

	return 0;

}

void display_date()
{
	time_t currentTime;
	time(&currentTime);

	printf("%s\n", ctime(&currentTime));
}

void display_date_u()
{
	time_t currentTime;
	gmtime(&currentTime);

	printf("%s\n", ctime(&currentTime));
}

void display_date_r(char *path)
{
	struct stat attr;

	stat(path,&attr);

	printf("Last Mordiffied date time: %s\n", ctime(&attr.st_mtime));

}


