#include<iostream>
#include<cmath>
using namespace std;
int canSurvive(int S,int N,int M)
{
    // For S days, S/7 sundays would be there 
    //  Means we can buy food on 6*S/7 days, but have to survive for S days
    if(S<7)
    {
        if(N<M) return -1;
        else return ceil(static_cast<double>(S*M)/N);
    }
    if(static_cast<double>(6*S)/7*N < S*M) return -1;
    return ceil(static_cast<double>(S*M)/N);
}
int main()
{
    int S,N,M;
    // S: Number of days you are required to survive
    // N: Maximum unit of Food You Can Buy Each day
    // m: Unit of food required each day to survive
    cin>>S>>N>>M;
    cout<<canSurvive(S,N,M);
    
}