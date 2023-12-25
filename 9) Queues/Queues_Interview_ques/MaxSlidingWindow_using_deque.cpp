#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums,int k)
{
    deque<int> q;
    int n=nums.size();
    vector<int> res;
    for(int i=0;i<k;i++)
    {
        while(!q.empty() && nums[q.back()]<=nums[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    res.push_back(nums[q.front()]);
    for(int i=k;i<n;i++)
    {
        if(q.front()==i-k) q.pop_front();
        while(!q.empty() && nums[q.back()]<=nums[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        res.push_back(nums[q.front()]);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    int k;
    cin>>k;
    vector<int> ans=maxSlidingWindow(nums,k);
    for(int i:ans) cout<<i<<" ";
    return 0;
}