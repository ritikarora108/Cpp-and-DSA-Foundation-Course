// Time Complexity: O(nlogn)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Item{
    int weight;
    int profit;
};
bool cmp(Item &a,Item &b)
{
    return static_cast<double>(a.profit)/a.weight > static_cast<double>(b.profit)/b.weight;
}
int main()
{
    int n;
    cin>>n;
    vector<Item> Items(n);  // {profit,weight}
    for(int i=0;i<n;i++) 
    {
        int prf;
        cin>>prf;
        int weight;
        cin>>weight;
        Items[i].weight=weight;
        Items[i].profit=prf;
    }
    int W;
    cin>>W;
    sort(Items.begin(),Items.end(),cmp);
    double maxProfit=0;
    for(int i=0;i<n;i++)
    {
        if(W>=Items[i].weight)
        {
            maxProfit+=Items[i].profit;
            W-=Items[i].weight;
        }
        else{
            double fractionalWeight= static_cast<double> (W)/Items[i].weight;
            maxProfit+=fractionalWeight*Items[i].profit;
            W=0;
        }
        if(W==0) break;
    }
    cout<<maxProfit<<endl;
}