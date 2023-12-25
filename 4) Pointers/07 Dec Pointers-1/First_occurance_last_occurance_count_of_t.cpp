#include<iostream>
using namespace std;
int get_output(string name,char *p,char *q)
{
    *p=name[0];
    *q=name[name.length()-1];
    int count=0;
    for(int i=0;i<name.length();i++)
    {
        if(name[i]=='t') count++;
    }
    return count;
}
int main()
{
    string name;
    cin>>name;
    char first;
    char last;
    int count_of_t=get_output(name,&first,&last);
    cout<<first<<" "<<last<<" "<<count_of_t<<endl;
    return 0;
}