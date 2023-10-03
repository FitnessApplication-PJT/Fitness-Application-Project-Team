#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#include<string>
#include<algorithm>


// Important Thing in the code of first come first server is when process start at later time than current time,
// in the if condition do i--
// So we go back to that current process.





class TaskName{
    public:

    string Name;
    int arrivedTime;
    int Burst_Time;
    
};


bool cmp (const TaskName &a,TaskName &b){
    return a.arrivedTime<b.arrivedTime;

}


int main(){

int n;
cout<<"Enter number of process:"<<endl;

cin>>n;
vector<TaskName>Process(n);
int a,b;
cout<<"Enter th arrival time and burst time for all process"<<endl;
for(int i=0;i<n;i++){
cin>>a>>b;
string taskName="P"+to_string(i+1);

Process[i].Name=taskName;
Process[i].arrivedTime=a;
Process[i].Burst_Time=b;
}

// All tasks Ready.

vector<TaskName>GanttChart;

// First Come first serve sort on arrival time.

int TotalTurn=0;
int TotalWait=0;
sort(Process.begin(),Process.end(),cmp);
cout<<"P_ID"<<"   "<<"Arrival Time"<<"   "<<"Burst Time"<<"   "<<"Time Completion"<<"   "<<"Turn Around Time"<<"  "<<"Waiting Time"<<endl; 
vector<int>TimeCompletion;
int timer=0;
for(int i=0;i<n;i++){
    if(timer<Process[i].arrivedTime){
        i--; // We remain on same index.
        timer++;
    }
    else{
        timer+=Process[i].Burst_Time;
        TimeCompletion.push_back(timer);
        int turnaround=timer-Process[i].arrivedTime;
        int waiting=turnaround-Process[i].Burst_Time;
        TotalTurn+=turnaround;
        TotalWait+=waiting;
        // cout<<Process[i].Name<<" "<<Process[i].arrivedTime<<" "<<Process[i].Burst_Time<<" "<<time<<" "<<turnaround<<" "<<waiting<<endl;
        
        cout<<timer<<endl;
        

    }
}

cout<<"-------------------  "<<endl;

cout<<"Average Turn Around Time"<<TotalTurn/n<<endl;
cout<<"Average Waiting time"<<TotalWait/n<<endl;



    return 0;
}