#include<iostream>
using namespace std;
int f(int h[],int i,int n) // This function returns the minimum cost from ith to n-1th stone( 0-based indexing )
{
    if(i==n-1) return 0;

    int jump1 = abs(h[i]-h[i+1]);
    if(i==n-2) return jump1; 

    int jump2 = abs(h[i]-h[i+2]);
    if(i==n-3) return jump2;

    int via_jump1=f(h,i+1,n);
    int via_jump2=f(h,i+2,n);

    int ans_via1 = jump1 + via_jump1;
    int ans_via2 = jump2 + via_jump2;

    if(ans_via1 < ans_via2) return ans_via1;
    else return ans_via2;
}

// int f(int h[],int i,int n)
// {
//     if(i==n-1) return 0;
//     if(i==n-2) return f(h,i+1,n) + abs( h[i] - h[i+1] );

//     return min( f(h,i+1,n) + abs(h[i]-h[i+1]) , f(h,i+2,n) + abs(h[i]-h[i+2]));
// }

int main()
{
    int n;
    cin>>n;
    int h[n]; // Array of height of stones
    for(int i=0;i<n;i++) cin>>h[i];
    int total_cost_incurred=f(h,0,n);
    cout<<"Total cost incurred to cross the river: "<<total_cost_incurred<<endl;
    return 0;

}