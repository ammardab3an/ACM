#include<bits/stdc++.h>
using namespace std;

const int N=2020;
int s,n;
int value[N] , weight[N];
int mem[N][N];

int dp(int i,int w){
    if(i == n) return 0;

    if(mem[i][w] != -1)
        return mem[i][w];

    int path1=0 , path2=0;
    if(weight[i] <= w) path1=value[i]+dp(i+1,w-weight[i]);
    path2=dp(i+1,w);

    return mem[i][w]=max(path1,path2);
}

int main()
{
    cin>>s>>n;
    for(int i=0 ; i<n ; i++)
        cin>>weight[i]>>value[i];

    memset(mem , -1 , sizeof mem);
    int ans=dp(0,s);
    cout<<ans;

    return 0;
}
