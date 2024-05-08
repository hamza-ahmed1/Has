#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
pid_t p;
uid_t u;
p=fork();
u=getuid();
if(p<0){printf("error while creating the child process");}
else if(p==0){
printf("I am child process with id %d \n",getpid());
printf("My parent id is %d \n",getppid());
}
else{
printf("I am  Parent process with id %d \n",getpid());
printf("my child id is %d \n",p);
}
printf("user id is %d \n",u);

}
