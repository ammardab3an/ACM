#include<bits/stdc++.h>
using namespace std;

const int N=5050 , inf=1e9;

int n,a,b,c;
int mem[N];

int dp(int n){
    if(n == 0)
        return 0;
    if(n < 0)
        return -inf;

    if(mem[n] != -1)
        return mem[n];

    int path1=0 , path2=0 , path3=0;

    path1=1+dp(n-a);
    path2=1+dp(n-b);
    path3=1+dp(n-c);

    return mem[n]=max({path1,path2,path3});
}

int main()
{
    cin>>n>>a>>b>>c;
    memset(mem,-1,sizeof mem);
    int ans=dp(n);

    cout<<ans<<endl;
    return 0;
}
