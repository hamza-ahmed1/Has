#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *func1();
void *func2();
int shared=1;

pthread_mutex_t l;

int main()
{

pthread_mutex_init(&l,NULL);
pthread_t th1,th2;

pthread_create(&th1,NULL,func1,NULL);
pthread_create(&th2,NULL,func2,NULL);

pthread_join(th1,NULL);
pthread_join(th2,NULL);


printf("value of shared variable is :%d",shared);
return 0;

}


void *func1()
{
pthread_mutex_lock(&l);
shared+=1;
pthread_mutex_unlock(&l);

}

void *func2()
{
pthread_mutex_lock(&l);
shared-=1;
pthread_mutex_unlock(&l);

}
