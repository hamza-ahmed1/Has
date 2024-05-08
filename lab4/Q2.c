#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()

{
pid_t p=fork();
if(p<0){printf("error while creating child process");}
else if(p==0)
{
int i;
for(i=0;i<100; i++)
{
printf("I am child process\n");
}
}
else{
int i;
for(i=0;i<100; i++)
{
printf("I am parent process\n");
}
}

}
