#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
int main()
{
pid_t p,q;
p=fork();
if(p<0)
{
printf("Error while creating child Process\n");
}
else if(p==0)
{
printf("I am child process-1 and my id is %d\n",getpid());
q=fork();
if(q<0){
printf("error while creating child process 2\n");
}
else if(q==0)
{
printf("I am child Process-2 and my parent id is %d \n",getppid());
}
else{
wait(NULL);
}
}
else {
wait(NULL);
}

}
