#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<wait.h>
void * thread_function(void *arg);
int *num[2]={1,2};
int main()
{
pthread_t a_thread;
void *result
pthread_create(&a_thread,NULL,thread_function,(void*)num);
pthread_join(a_thread,&result);//first exec all thread  code
//main code:
int i;
printf("Inside Main \n");
for(i=1; i<=5; i++)
{	sleep(1);
	printf("%d\n",i);
}
printf("Thread returned :",(char *)result);
}

void *thread_function(void *arg)
{
int *x=arg;
int sum=x[0]+x[1];

printf("Inside thread 1\n");
int j;
for(j=20; j<=25; j++)
{
sleep(1);
printf("%d\n",j);
}
printf("Sum : %d\n",sum);
//exit with message (string)
pthread_exit("Sum calculated!\n");
}
