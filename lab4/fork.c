#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()

{
pid_t ch_id;
printf("Before Child\n");
ch_id=fork();
if(ch_id<0)
	{
	printf("\nError while creating child process\n");

	}
	else if(ch_id==0)
	{
	printf("\nIm child Process with id %d",getpid());
	printf("\nMy parent id is %d",getppid());
	}
	else {
	printf("\nIm parent having id %d",getpid());
	printf("\nmy child's id is %d",ch_id);
	printf("\n\n");
	}

}
