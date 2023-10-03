// Task-3


// Process Synchroniztion method usning mutex lock.

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string>
#include<pthread.h>

void * function();

pthread_mutex_t lock;

int counter=0;
pthread_t thread1,thread2;

int rc1=pthread_create(&thread1,NULL,function,NULL);
int rc2=pthread_create(&thread2,NULL,function,NULL);

pthread_join(thread1,NULL);
pthread_join(thread2,NULL);

printf("Final Value of counter:%d\n",counter)

