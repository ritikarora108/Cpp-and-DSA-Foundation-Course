#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->val=d;
        this->left=this->right=NULL;
    }
};
bool isIdenticalBSTHelper(vector<int> &a,vector<int> &b,int p,int q,int n,int minValue,int maxValue)
{
    int i=p;
    for(i;i<n;i++)
    {
        if(a[i]>minValue && a[i]<maxValue) break;
    }
    int j=q;
    for(j;j<n;j++)
    {
        if(b[j]>minValue && b[j]<maxValue) break;
    }
    if(i>=n && j>=n) return true;
    if((i==n && j!=n) || (i!=n && j==n)) return false;
    if(a[i]!=b[j]) return false;
    
    
    return isIdenticalBSTHelper(a,b,i+1,j+1,n,minValue,a[i]) && isIdenticalBSTHelper(a,b,i+1,j+1,n,a[i],maxValue);
}
bool isIdenticalBST(vector<int> &v1,vector<int> &v2)
{
    return isIdenticalBSTHelper(v1,v2,0,0,v1.size(),INT_MIN,INT_MAX);
}
int main()
{
    vector<int> v1={4,2,5,1,3};
    vector<int> v2={4,5,3,2,1};
    if(isIdenticalBST(v1,v2)) cout<<"BST's are identical"<<endl;
    else cout<<"BST formed are not identical"<<endl;
    return 0;
}