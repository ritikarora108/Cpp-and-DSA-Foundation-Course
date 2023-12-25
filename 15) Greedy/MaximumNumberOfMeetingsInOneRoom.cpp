#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int> &a1,vector<int> &a2)
{
    if(a1[1]==a2[1]) return a1[0]>a2[0];
    return a1[1]<a2[1];
}
int main()
{
    int n;
    cin>>n;
    vector<int> start(n);
    for(int i=0;i<start.size();i++) cin>>start[i];
    vector<int> end(n);
    for(int i=0;i<n;i++) cin>>end[i];
    vector<vector<int>> meetings(n);
    for(int i=0;i<n;i++)
    {
        meetings[i]={start[i],end[i],i+1};
    }
    sort(meetings.begin(),meetings.end(),cmp);
    int count=0;
    int lastMeetEndTime=0;
    for(int i=0;i<n;i++)
    {
        if(lastMeetEndTime<meetings[i][0])
        {
            lastMeetEndTime=meetings[i][1];
            cout<<meetings[i][2]<<" ";
            count++;
        }
    }
    cout<<endl<<"No. of meetings: "<<count<<endl;
    return 0;
}