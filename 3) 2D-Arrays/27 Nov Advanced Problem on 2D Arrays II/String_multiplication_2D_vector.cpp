#include<iostream>
#include<vector>
using namespace std;
string multiply(string num1, string num2) {
    int m=num1.length();
    int n=num2.length();
    if(m<n) return multiply(num2,num1);
    vector<vector<int>> result;
    int count_zeroes=0;
    for(int i=0;i<n;i++)
    {
        vector<int> ans(0);
        int carry=0;
        for(int j=0;j<m;j++)
        {
            int temp=(num2[n-1-i]-'0')*(num1[m-1-j]-'0')+carry;
            if(ans.size()==0) ans.push_back(temp%10);
            else ans.insert(ans.begin()+0,temp%10);
            carry=temp/10;
        }
        if(carry!=0) ans.insert(ans.begin()+0,carry);
        for(int x=1;x<=count_zeroes;x++) ans.push_back(0);
        count_zeroes++;
        result.push_back(ans);    
    }
    int size=result.size();
    int maxSize=result[size-1].size();
    for(int i=0;i<size;i++)
    {
        int tempSize=result[i].size();
        for(int j=1;j<=maxSize-tempSize;j++)
        { result[i].insert(result[i].begin()+0,0);}
    }
    int c=0;
    vector<int> final;
    int var;
    for(int j=maxSize-1;j>=0;j--)
    {
        var=c;
        for(int i=0;i<size;i++)
        {
            var+=result[i][j];
        }
        final.push_back(var%10);
        c=var/10;
    }
    if(c!=0) final.push_back(c);
    string tem="a";
    string getAns="";
    for(int i=final.size()-1;i>=0;i--) 
    {
        tem[0]=(final[i]+'0');
        getAns+=tem[0];
    }
    return getAns;
}
int main()
{
    string ans=multiply("123","456");
    cout<<ans;
}