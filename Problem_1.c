#include <stdio.h>
#include <inttypes.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include <string.h>



int main() {
	
	pid_t pid;
	int status;

	/* Fork a child process */
	pid=fork();

	if(pid<0){
		printf("fork failled");
	}
	else if(pid==0)/* child process code */
	{
		FILE *fp= fopen("csv-os.csv","r");
		if(fp==NULL)
		{
			printf("no file exist\n");
		}

		char line[100];

		int sum=0;
		float avg=0;

		fgets(line, sizeof(line),fp);

		while(fgets(line, sizeof(line),fp))
		{
			char *record;
			char *student_name;
			char *sec;
			char *a1;
			char *a2;
			char *a3;
			char *a4;

			//printf("%s\n", line );

			//record=strtok(line,",");

			student_name=strtok(line,",") ;

			sec= strtok(NULL,",");

			a1= strtok(NULL,",");

			a2= strtok(NULL,",");

			a3=strtok(NULL,",");

			a4=strtok(NULL,",");

			int num1,num2,num3,num4;

			sscanf(a1, "%d", &num1); 
			sscanf(a2, "%d", &num2); 
			sscanf(a3, "%d", &num3); 
			sscanf(a4, "%d", &num4); 

			avg=((float)(num1+num2+num3+num4)/4);


			if(strcmp(sec,"A")==0)
			{
				printf("Roll_no: %s " " Sec:%s " " A1:%s " " A2:%s " " A3:%s " " A4:%s\n", student_name,sec,a1,a2,a3,a4);
				printf("Average score: %f\n",avg);
			}
			

			
		}

		printf("######################################\n");

		fclose(fp);
		
	}
	else
	{
		pid_t cpid=waitpid(pid, &status, 0);
		if(cpid>0)
		{
			FILE *fp= fopen("csv-os.csv","r");
			if(fp==NULL)
			{
				printf("no file exist\n");
			}

			char line[100];

			int sum=0;
			float avg=0;

			fgets(line, sizeof(line),fp);

			while(fgets(line, sizeof(line),fp))
			{
				char *record;
				char *student_name;
				char *sec;
				char *a1;
				char *a2;
				char *a3;
				char *a4;

				//printf("%s\n", line );

				//record=strtok(line,",");

				student_name=strtok(line,",") ;

				sec= strtok(NULL,",");

				a1= strtok(NULL,",");

				a2= strtok(NULL,",");

				a3=strtok(NULL,",");

				a4=strtok(NULL,",");

				int num1,num2,num3,num4;

				sscanf(a1, "%d", &num1); 
				sscanf(a2, "%d", &num2); 
				sscanf(a3, "%d", &num3); 
				sscanf(a4, "%d", &num4); 

				avg=((float)(num1+num2+num3+num4)/4);


				if(strcmp(sec,"B")==0)
				{
					printf("Roll_no: %s " " Sec:%s " " A1:%s " " A2:%s " " A3:%s " " A4:%s\n", student_name,sec,a1,a2,a3,a4);
					printf("Average score: %f\n",avg);
				}
				

				
			}

			printf("######################################\n");

			fclose(fp);
		}
		
	}
	
    return 0;
}