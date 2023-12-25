#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
pair<int,int> pairSumIndices(vector<int> &v,int target)
{
    unordered_map<int,int> m;
    for(int i=0;i<v.size();i++)
    {
        if(m.find(target-v[i]) == m.end()) m[v[i]]=i;
        else{
            return {m[target-v[i]],i};
        }
    }
    return{-1,-1};
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int target;
    cin>>target;
    auto indexPair=pairSumIndices(v,target);
    cout<<"["<<indexPair.first<<","<<indexPair.second<<"]"<<endl;
    return 0;
}