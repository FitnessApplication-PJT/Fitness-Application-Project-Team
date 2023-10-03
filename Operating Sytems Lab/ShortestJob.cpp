// Code priority Non Premtive Coding of cpu schedulinh. 


#include<iostream>
using namepace std;
#include<vector>
#include<queue>
#include<algorithm>
#include<string>



class Process{
    public:
    string ProcessName;
    int arrival;
    int burst;
  
    int copyBurst;
}

struct myComp{

    bool operator()(Process & a,Process & b){
        a.burst>b.burst;
    }
}

bool cmp(Process & a,Process & b){
    return a.arrival<b.arrival;
}
int main(){
int n;
cout<<"Enter number of process"<<endl;
cin>>n;
vector<Process>ProcessList(n);
int a,b,p;
cout<<"Enter the arrival burst of each process"<<endl;

for(int i=0;i<n;i++){
    cin>>a>>b;
    string name="P"+to_string(i+1);
    ProcessList[i].ProcessName=name;
    ProcessList[i].arrival=a;
    ProcessList[i].burst=b;
    ProcessList[i].copyBurst=b;
    ProcessList[i].priority=p;
}
sort(ProcessList.begin(),ProcessList.end(),cmp);

priority_queue<Process,vector<Process>,myComp>Data;


int timer=0;
int lastprocess=-1;
while(lastprocess<n-1 || ! Data.empty()){
    for(int i=lastprocess+1;i<n;i++){
        if(ProcessList[i].arrival<=timer){
            Data.push(ProcessList[i]);
            lastprocess=i;
        }
    }

if(!Data.empty()){
    Process todo=Data.top();
    // this is priority non premtive.
    Data.pop();
   timer++;
   todo.burst-=timer;
   if(todo.burst!=0){
    Data.push(todo);
   }
   else{
    cout<<todo.ProcessName<<" "<<todo.arrival<<" "<<todo.burst<<" "<<timer<<endl;
    // printed the arriaval time burst time and time of commpletion.
    

   }
   

}
else{
    timer++;
}

}


}