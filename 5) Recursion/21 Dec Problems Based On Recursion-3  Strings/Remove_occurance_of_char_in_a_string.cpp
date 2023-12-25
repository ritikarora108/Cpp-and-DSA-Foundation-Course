//s="abcax";
//s.substring(1) -> "bcax";
//s.substring(2) -> "cax";     //O(n)
//this facility is only available in strings.


#include<iostream>
using namespace std;
string remove_occurance(string &s,char ch,int i)
{
    string result="";
    if(i==s.length()) return "";
    if(s[i]!=ch) result=s[i]+remove_occurance(s,ch,i+1);
    else result=remove_occurance(s,ch,i+1);
    return result;
}
int main()
{
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    char ch;
    cout<<"Enter the character you want to remove: ";
    cin>>ch;
    string ans=remove_occurance(s,ch,0);
    cout<<ans;
    return 0;
}

// #include<iostream>
// using namespace std;
// string result="";
// string remove(string &s,int i,char ch)
// {
    
//     if(i==s.length()) return "";
//     if(s[i]!=ch) 
//     {
//         return result+s[i]+remove(s,i+1,ch);
//     }
//     return result+remove(s,i+1,ch);
// }
// int main()
// {
//     string s;
//     cin>>s;
//     char ch;
//     cin>>ch;
//     cout<<remove(s,0,ch)<<endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;
// string result="";
// void remove(string &s,char ch,int i)
// {
//     if(i==s.length()) return;
//     (s[i]==ch) ? (result+="") : (result+=s[i]);
//     remove(s,ch,i+1);
// }
// int main()
// {
//     string s;
//     cin>>s;
//     char ch;
//     cin>>ch;
//     remove(s,ch,0);
//     cout<<result<<endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main()
// {
//     string s;
//     cin>>s;
//     char ch;
//     cin>>ch;
//     string result="";
//     for(int i=0;i<s.length();i++)
//     {
//         if(s[i]!=ch) result+=s[i];
//     }
//     cout<<result;
//     return 0;
// }
