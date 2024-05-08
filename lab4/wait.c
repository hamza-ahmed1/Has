#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
int main()
{
pid_t p;
p=fork();
if(p<0){
printf("Error");
}
else if(p==0){
sleep(4);
printf("I am child process with id %d \n",getpid());
printf("My parent id is %d \n",getppid());
}
else {
//wait(NULL);
printf("i am parent Process with id %d \n",getpid());
printf("My child id is %d \n",p);
}
}
