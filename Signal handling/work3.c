#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>

#define ARRAY_SIZE 100000
#define NUM_THREADS 5
#define SECONDS_IN_CRITICAL_SECTION 5

int array[ARRAY_SIZE];
sem_t sem;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int sums[NUM_THREADS] = {0};


void timer_handler(int signum) {
    pthread_cond_signal(&cond);
    alarm(SECONDS_IN_CRITICAL_SECTION); // Reset the alarm
}


void* calculate_sum(void* arg) {
    int thread_id = *(int*)arg;
    int start = thread_id * (ARRAY_SIZE / NUM_THREADS);
    int end = (thread_id + 1) * (ARRAY_SIZE / NUM_THREADS);

    for (int i = start; i < end; ++i) {
        sums[thread_id] += array[i];
    }

    pthread_mutex_lock(&mutex);
    printf("Thread %d: Entered critical section\n", thread_id);
    alarm(SECONDS_IN_CRITICAL_SECTION); // Set alarm
    pthread_cond_wait(&cond, &mutex); // Wait for signal
    pthread_mutex_unlock(&mutex);

    printf("Thread %d: Exited critical section\n", thread_id);

    sem_wait(&sem);
    printf("Thread %d: Sum in critical section: %d\n", thread_id, sums[thread_id]);
    sem_post(&sem);

    return NULL;
}

int main() {

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = rand() % 100;
    }

  
    sem_init(&sem, 0, 1);


    signal(SIGALRM, timer_handler);


    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_sum, &thread_ids[i]);
    }


    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }


    sem_destroy(&sem);

    return 0;
}

