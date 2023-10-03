#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int calc(int a,int b,char x){
    if(x=='+'){
        return a+b;
    }
    else if(x=='-'){
        return a-b;
    }
    else if(x=='*'){
        return a*b;
    }
    else if(x=='/'){
        return a/b;
    }
return -1;
}

vector<int>Data(10,-1);
int main(){
int n;
cout<<"Number of instruction\n";
cin>>n;
for(int i=0;i<n;i++){
string res,arg1,arg2,op;
cin>>res>>arg1>>arg2>>op;

if(arg1[0]=='#' && arg2[0]=='#'){

int ched1=0;
int ched2=0;
int n1=arg1.size();
int n2=arg2.size();

for(int i=1;i<n1;i++){
    ched1=ched1*10+(arg1[i]-'0');
}
for(int i=1;i<n2;i++){
    ched2=ched2*10+(arg2[i]-'0');
}

int ss=calc(ched1,ched2,op[0]);
Data[(res[0]-'0')]=ss;
cout<<ss<<endl;
}
else{
    int k=Data[(arg1[0]-'0')];
    int l=Data[(arg2[0]-'0')];
    if(k!=-1 && l!=-1){
        int zz=calc(l,k,op[0]);
        cout<<"t"<<res<<'='<<zz<<endl;
    }
    else{
        cout<<"t"<<res<<"="<<"t"<<arg1<<op<<"t"<<arg2<<endl;
    }
}
}


}