#include <stdio.h>
#include <unistd.h>
  
int main()
{
    int p=fork();
   if(p>=1){
       printf("Parnet\n");
   }
   else if(p==0){
       printf("child\n");
       fork();
       printf("end\n");
   }
   printf("bye\n");
}