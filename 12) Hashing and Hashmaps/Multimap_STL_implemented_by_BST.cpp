// m.count(key) -> gives the number of occurances of key in map m
// m.find(key) -> gives an itr pointing to first occ. of key
#include<iostream>
#include<map>
using namespace std;
int main()
{
    multimap<string,int> m;
    m.insert(make_pair("sara",4200));
    m.insert(make_pair("sara",67));
    m.insert({"ritik",74654});
    //m["sara"]=49;
    //m["urvi"]=34;      Sqaure brackets are not allowed in multimaps
    for(auto i:m) cout<<i.first<<" "<<i.second<<"\n";
    cout<<m.count("sara")<<endl;
    auto itr=m.upper_bound("sara");
    if(itr==m.end()) cout<<"Itr points to m.end()"<<endl;
    else cout<<itr->first<<" "<<itr->second<<endl;

    auto itr1=m.lower_bound("sara");
    if(itr1==m.end()) cout<<"Itr1 points to m.end()";
    else cout<<itr1->first<<" "<<itr1->second<<endl;
}