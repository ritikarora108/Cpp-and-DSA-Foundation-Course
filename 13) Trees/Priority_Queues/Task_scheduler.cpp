// https://leetcode.com/problems/task-scheduler/description/
// Time Complexity: O(n+nlogn)
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
int leastTimeCPUTakesToFinishTasks(vector<char> &tasks,int n)
{
    int size=tasks.size();
    unordered_map<char,int> m;
    for(auto i:tasks)
    {
        m[i]++;
    }
    priority_queue<int> pq;
    for(auto i:m) 
    {
        pq.push(i.second);
    }
    int leastTime=0;
    while(!pq.empty())
    {
        vector<int> temp;
        for(int i=0;i<=n;i++)
        {
            if(!pq.empty())
            {
                if(pq.top()>1) temp.push_back(pq.top()-1);
                pq.pop();
            }
            else if(temp.empty()) return leastTime;
            leastTime++; // if pq is empty(), leastTime still increased because CPU is in idle state
        }
        for(auto i:temp)
        {
            pq.push(i);
        }
    }
    return leastTime;
}
int main()
{
    int n;
    cin>>n;
    vector<char> tasks(n);
    for(int i=0;i<n;i++) cin>>tasks[i];
    int tq;
    cin>>tq;
    cout<<"Least time CPU will take to finish all tasks: "<<leastTimeCPUTakesToFinishTasks(tasks,tq)<<endl;
    return 0;
}