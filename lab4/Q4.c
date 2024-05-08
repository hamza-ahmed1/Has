#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *args[])
{

	pid_t p,q,r;
	int sum=0;
	float avg=0;
	p=fork();
	
	if(p<0){printf("error while creating ");}
	else if(p==0)
{
		//child 1
		int i;
		for(i=1; i<argc; i++)
			{
		sum+=atoi(args[i]);
			
			}
		printf("sum : %d \n",sum);
	q=fork();
  	if(q<0){printf("error while  creating  child process");}
	else if(q==0)
	{
		//child-2
		int i;
		for( i=1; i<argc; i++)
		{

		avg+=atoi(args[i]);
		}
		printf("Avg is %f  \n",avg/(argc-1));
		r=fork();

		if(r<0){printf("error while creating the child process");}
		else if(r==0){
			int max=0;
			for( i=1; i<argc; i++)
			{
				if(atoi(args[i])>max)
					{
					max=atoi(args[i]);
					}
			}
			printf("max is %d",max);
		}
		else{
		wait(NULL);
		}
	}
	else
	{
		wait(NULL);
	}
}
	else 
	{	
		wait(NULL);
		
	}
}
