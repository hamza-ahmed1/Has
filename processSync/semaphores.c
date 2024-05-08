#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t s;

void *thread()
{
printf("\nEntered......\n");
sem_wait(&s);

sleep(5);

printf("\nExiting......\n");
sem_post(&s);


}

int main()	
{


sem_init(&s,0,1);
pthread_t th1,th2;
pthread_create(&th1,NULL,thread,NULL);
pthread_create(&th2,NULL,thread,NULL);

pthread_join(th1,NULL);
pthread_join(th2,NULL);
sem_destroy(&s);
return 0;
}