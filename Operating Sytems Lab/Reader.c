#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>


sem_t writeToken, ReadToken;
int currentReaderCount=0;
void * Reader(void * args);
void * Writer(void * args);


int main(){
    sem_t(ReadToken,0,1);
    sem_t(writeToken,0,1);

// Eenter readef coutn and write count.

int ReaderCount;
int WriterCount;

pthread_t ReaderList[ReaderCount];
pthread_t WriterList[WriterCount];

for(int i=0;i<ReaderCount;i++){
    pthread_create(ReaderList[i],NULL,Reader,NULL);
}
for(int j=0;j<WriterCount;j++){
    pthread_create(WriterList[j],NULL,Writer,NULL);

}

void * Reader(void * args){

printf("Reader is waiting\n");
sem_wait(&ReadToken);
currentReaderCount+=1;
if(currentReaderCount==1){
    printf("First reader is waiting\n");
    sem_wait(&writetoken);
    // When first reader came we stopped all the writer.
    printf("First reader is entering");
    // When reade comes check if writer has 
    // not come still and is waiting.
// First reader gets trapped.
    
}
sem_post(&reaToken);
printf("Reader is reading from the database\n");
// Now before the readign reduce the count.
// But in mutex always under the lock operatin has to be done.
// Reader is leaving
sem_wait(&readToken);

currentReaderCount-=1;
if(currentReaderCount==0){
    sem_post(&writeToken);
}
sem_post(&readtoken);

}

void * Writer_function(void * args){
printf("Writer is waiting\n");
sem_wait(&writetoken);
printf("Writer is writing to the database");
sem_post(&writetoken);

}






















}






}


void * ReaderFunction(void * args){


    printf("Reader is waiting");
    sem_wait(&readtoken);
    // Blocked the reader.
    currentReaderCount++;
    if(currentReaderCount==1){
// First reader came.
// if witer is writing block him.
printf("Reader1 IS waiting\n");
sem_wait(&writetoken);
printf("Redear 1 is netering\n");
}
// Reader i enetered.
sem_post(&readtken);
printf("Reader is reading from database\n");

// Now reader is leaving/

sem_wait(&readtoken);
currentReaderCount-=1;
if(currentReaderCount==0){
    sem_post(&writetoken);

}
if(currentReaderCount==0){

sem_post(&writetoken);
}
printf("Reader is levaing\n");
sem_post(&readtoken);



}

void * WriterFucntion(void * args){
printf("Writer is waiting\n");
sem_wait(&writetoken);
printf("Writer is writing\n");
sem_post(&writetoken);
printf("Writer is leaving;");


}

