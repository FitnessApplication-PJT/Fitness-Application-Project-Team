#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef pair<string, pair<int, int>> pd;

struct myComp {
    const bool operator()(
        pair<string, pair<int, int>> const &a,
        pair<string, pair<int, int>> const &b)
        const noexcept
    {
        return a.second.second > b.second.second;
    }
};

bool cmp(const pair<string, pair<int, int>> &a, const pair<string, pair<int, int>> &b) {
    return a.second.first < b.second.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<string, pair<int, int>>> tasks;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        string taskNo = "P" + to_string(i + 1);
        tasks.push_back({taskNo, {a, b}});
    }

    vector<pair<string, pair<int, int>>> ganttChart;
    priority_queue<pd, vector<pd>, myComp> Data;

    int timer = 0;
vector<pair<string,int >>TimeCompletion;
    while (true) {
        // Check if any tasks have arrived at the current time
        for (int i = 0; i < n; i++) {
            if (tasks[i].second.first <= timer) {
                Data.push(tasks[i]);
                tasks.erase(tasks.begin() + i);
                i--;
                n--;
            }
            
        }

        if (!Data.empty()) {
            pd ToExecute = Data.top();
            Data.pop();
            ganttChart.push_back(ToExecute);
            ToExecute.second.second -= 1;
            timer++;
            if (ToExecute.second.second != 0) {
                Data.push(ToExecute);
            }
            else{
                TimeCompletion.push_back({ToExecute.first,timer});
                
            }
        }
        else{

        timer++;
}
        if (tasks.empty() && Data.empty()) {
            break;
        }
    }
    
    int z=TimeCompletion.size();
  for(int i=0;i<z;i++){
      cout<<TimeCompletion[i].first<<" "<<TimeCompletion[i].second<<endl;
      
  }
    // Printing the values
    cout << "Printing the Gantt Chart: The Order of Instructions Executions:" << endl;
    cout << "PID" << " " << "Arrival_Time" << " " << "Burst_Time " << "  " << "Time of Completion" << endl;

    int x = ganttChart.size();
    for (int i = 0; i < x; i++) {
        cout << ganttChart[i].first << "    " << ganttChart[i].second.first << "        " << ganttChart[i].second.second << "             " << (i + 1) << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef pair<string, pair<int, int>> pd;

struct myComp {
    const bool operator()(
        pair<string, pair<int, int>> const &a,
        pair<string, pair<int, int>> const &b)
        const noexcept
    {
        return a.second.second > b.second.second;
    }
};

bool cmp(const pair<string, pair<int, int>> &a, const pair<string, pair<int, int>> &b) {
    return a.second.first < b.second.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<string, pair<int, int>>> tasks;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        string taskNo = "P" + to_string(i + 1);
        tasks.push_back({taskNo, {a, b}});
    }

    vector<pair<string, pair<int, int>>> ganttChart;
    priority_queue<pd, vector<pd>, myComp> Data;

    int timer = 0;
vector<pair<string,int >>TimeCompletion;
    while (true) {
        // Check if any tasks have arrived at the current time
        for (int i = 0; i < n; i++) {
            if (tasks[i].second.first <= timer) {
                Data.push(tasks[i]);
                tasks.erase(tasks.begin() + i);
                i--;
                n--;
            }
            
        }

        if (!Data.empty()) {
            pd ToExecute = Data.top();
            Data.pop();
            ganttChart.push_back(ToExecute);
            ToExecute.second.second -= 1;
            timer++;
            if (ToExecute.second.second != 0) {
                Data.push(ToExecute);
            }
            else{
                TimeCompletion.push_back({ToExecute.first,timer});
                
            }
        }
        else{

        timer++;
}
        if (tasks.empty() && Data.empty()) {
            break;
        }
    }
    
    int z=TimeCompletion.size();
  for(int i=0;i<z;i++){
      cout<<TimeCompletion[i].first<<" "<<TimeCompletion[i].second<<endl;
      
  }
    // Printing the values
    cout << "Printing the Gantt Chart: The Order of Instructions Executions:" << endl;
    cout << "PID" << " " << "Arrival_Time" << " " << "Burst_Time " << "  " << "Time of Completion" << endl;

    int x = ganttChart.size();
    for (int i = 0; i < x; i++) {
        cout << ganttChart[i].first << "    " << ganttChart[i].second.first << "        " << ganttChart[i].second.second << "             " << (i + 1) << endl;
    }

    return 0;
}

