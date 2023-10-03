// Process Syn using Semaphores.
// 1 Producer COnsumer
//2 Reader Writer
// Dining Philosophers

// Completing both the code before 


/**
 * Semaphores what has o be done.
 * 
 * #Include<sempahore.h>
 * 
 * sem_t mutex;
 * 
 * sem_intit(&mutex,0,1);
 * sem_int(&mutex,0,1) 
 *
 * 
 */


// sem_wait() sem_post()



#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

#include<pthread.h>
#include<semaphore.h>

void * function1();
#define buffSize 1000;
int counter=0;
sem_t mutex;

int main(){

sem_init(&mutex);
pthread_t thread1;
pthread_t thread2;

pthread_create(&thread1,NULL,function1,NULL);
pthread_create(&thread2,NULL,function1,NULL);

printf("Printing final value  of counter:%d \n",counter);

}

void * function1(){
    sem_wait(&mutex);
    counter++;
    sem_post(&mutex);
    
}





























