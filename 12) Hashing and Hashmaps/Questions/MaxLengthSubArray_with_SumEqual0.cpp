//                 15 -2  2  7  1 -8 10 23
// Prefix Sum->    15 13 15 22 23 15 25 48

// SubArray with Sum=0       Sum[l.....r]=0   : v[l]+v[l+1]+... +v[r]=0
//                           ______________________________     -> prefixSum(r)-prefixSum(l-1)=0
//                       -> |_ prefixSum(l-1)=prefiSum(r) _|
//                          
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int maxlengthSubarrayWithSum0(vector<int> &v)
{
    int n=v.size();
    int prefixSum=0;
    int maxLength=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        prefixSum+=v[i];
        if(m.find(prefixSum)!=m.end()) 
        {
            maxLength=max(maxLength,i-m[prefixSum]);
        }
        else{
            m[prefixSum]=i;
        }
    }
    return maxLength;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int len=maxlengthSubarrayWithSum0(v);
    cout<<"Max Length: "<<len<<endl;
    return 0;
}