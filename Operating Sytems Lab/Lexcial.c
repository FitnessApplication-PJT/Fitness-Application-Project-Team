#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<ctype.h>


int isOperator(char c){


if(c=='+' || c=='-' || c=='/' || c=='*' ||

c==')' || c=='=' || c=='=='
){

return 1;
}
return 0;
}

int isKeyWord(char * value){
    const char * keyword[]={"while","for","if"
    ,"main","void","printf"};
    int n=sizeof(keyword);
    for(int i=0;i<n;i++)
{
    if(keyword[i]==value){
        return 1;
    }
}
return 0;
}

int isSeperator(char x){

if(x=='[' || x==']' || x=='(' || x==')' || x=='{' || x=='}'){
    return 1;
}
return 0;
}



int main(){

char b[100];
printf("Enter string\n");
fgets(b,sizeof(b),stdin);

int len=strlen(b);
for(int i=0;i<len;i++){

if(isspace(b[i])){
    continue;;
}
else if(isalpha(b[i])){
    char identifier[100]="";
    int j=0;
    while(isalpha(b[i]) || isdigit(b[i])){
        identifier[j++]=b[i++];

    }
    identifier[j]='\0';
if(isKeyWord(identifier)){
    printf("IS is keyword");
}
else{
    printf("Is an identifier\n");
}
i--;
}
else if(isdigit(b[i]){
    int m=(b[i]-'-0');
    i+i+1;
    while (isdigit[b[i]])

    {
      m=m*10 + (b[i]-'0');
      i++;
    }
    i--;   
}
else if(isSeperator(b[i])){
    printf("is A Seperartor\n");
}
// Is isalpa() 
/*

create a tring of that and keep checking till something.

if it a dgit in first instance. 
store till the last didigti exampe 1000 

store 1000 as 1000 not as 1,0,0,0

// Importatn remianie dis reasy .


*/

}





}