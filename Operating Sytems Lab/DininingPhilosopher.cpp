#include<iostream>
#include<queue>
#include<vector>

using namespace std;


void ProcessCode(string op,string arg1,string arg2,string  res){

   cout<<"Machine code for new instruction"<<endl;
    if(arg2=="#" &&  op=="&"){
        // this is assginment statement.
        cout<<"MOV    "<<res<<","<<arg1<<endl;
        exit(0);
    }
    else{

        if(op=="+"){
        cout<<"MOV AX,"<<arg1<<endl;
        cout<<"MOV BX,"<<arg2<<endl;
        cout<<"ADD AX,BX"<<endl;
        cout<<"MOV  "<<" "<<res<<",AX"<<endl;
        }
        else if(op=="-"){
         cout<<"MOV AX,"<<arg1<<endl;
        cout<<"MOV BX,"<<arg2<<endl;
        cout<<"SUB AX,BX"<<endl;
        cout<<"MOV"<<res<<",AX"<<endl;


        }
        else if(op=="/"){
            cout<<"MOV AX,"<<arg1<<endl;
        cout<<"MOV BX,"<<arg2<<endl;
        cout<<"DIV BX"<<endl;
        cout<<"MOV"<<res<<",AX"<<endl;

        }
        else if (op=="*"){
             cout<<"MOV AX,"<<arg1<<endl;
        cout<<"MOV BX,"<<arg2<<endl;
        cout<<"MUL BX"<<endl;
        cout<<"MOV"<<res<<",AX"<<endl;


        }
        else{
            printf("Invalid output\n");
        }
    }
}


int main(){

int n;
cout<<"Enter number of lines"<<endl;
cin>>n;
cout<<"Enter operator arg1 arg2 and result"<<endl;
cout<<"if assignment opertiion give ar2=# and result=&"<<endl;

string op,arg1,arg2,res;
for(int i=0;i<n;i++){
    cin>>op>>arg1>>arg2>>res;
    ProcessCode(op,arg1,arg2,res);
}

}