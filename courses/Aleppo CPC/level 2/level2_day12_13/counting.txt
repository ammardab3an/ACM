#include<bits/stdc++.h>
using namespace std;

const int N=5050;

int n;
long long mem[N];

long long dp(int n){
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;

    if(mem[n] != -1)
        return mem[n];


    long long path1=dp(n-1);
    long long path2=dp(n-3);
    long long path3=dp(n-4);

    return mem[n]= path1 + path2 + path3;
}

int main()
{
    int n;
    cin>>n;
    memset(mem,-1,sizeof mem);
    long long ans=dp(n);
    cout<<ans<<endl;
    return 0;
}
