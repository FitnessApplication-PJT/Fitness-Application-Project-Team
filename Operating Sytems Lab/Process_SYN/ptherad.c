// Print Your name 5 times each with different threads. with their thread id.

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

void * Print_Name(void * args);

int main(){

pthread_t Data[5];

int rc;
long t;
for(int i=0;i<5;i++){

    int rc=pthread_create(&Data[i],NULL,Print_Name,& (void * ) Data[i]);
   if(rc){
    printf("Error");
   }

}
  pthread_exit(NULL);


    return 0;
}


void * Print_Name(void * threadId){
    long tid;
    tid=(long)threadId;
    printf("Hello World! its Me Omkar with id %ld",tid);
}