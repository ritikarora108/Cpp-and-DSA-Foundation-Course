// #include<iostream>
// #include<cstring> 
// using namespace std;
// void selectionSort(char list[][10],int n)
// {
//     for(int i=0;i<=n-2;i++)
//     {
//         int min_index=i;
//         for(int j=i+1;j<n;j++)
//         {
//             if(strcmp(list[min_index],list[j]) > 0) min_index=j;
//         }
//         if(min_index!=i)
//         {
//             char temp[10];
//             strcpy(temp,list[min_index]);
//             strcpy(list[min_index],list[i]);
//             strcpy(list[i],temp);
//         }
//     }
// }
// int main()
// {
//     char list[][10]={"papaya","lemon","kiwi","apple","mango"};
//     int n = sizeof(list)/sizeof(list[0]);
//     selectionSort(list,n);
//     for(int i=0;i<n;i++) cout<<list[i]<<"\t";
//     return 0;
// } 

#include<iostream>
#include<vector>
using namespace std;
bool isGreaterThan(string s1,string s2)
{
    int m=s1.length();
    int n=s2.length();
    int temp=min(m,n);
    for(int i=0;i<temp;i++)
    {
        if(s1[i]>s2[i]) return 1;
        if(s1[i]<s2[i]) return 0;
    }
    if(temp==m) return 0;
    else return 1; 
}
void lexicographicalOrder(vector<string> &arr)
{
    int n=arr.size();
    for(int i=0;i<=n-2;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(isGreaterThan(arr[min_index],arr[j])) min_index=j;
        }
        if(min_index!=i) swap(arr[min_index],arr[i]);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    // Selection Sort
    lexicographicalOrder(v);
    cout<<"Printing in Lexico-Graphical Order: "<<endl;
    for(string i:v) cout<<i<<"\t";
    return 0;
}