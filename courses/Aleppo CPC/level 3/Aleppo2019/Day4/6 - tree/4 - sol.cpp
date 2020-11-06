#include <bits/stdc++.h>

using namespace std;
const int mod = (int)1e9+7;
int mem[123][2];
int n , d , k ;

int dp(int x,bool f){

if( x==0 )return f;
if( x<0  )return 0;

if( mem[x][f]!= -1 )return mem[x][f];

int ret=0;

for(int i=1;i<=min(k,x);i++)
    ret= (ret+dp(x-i,f|(i>=d)))%mod;

return mem[x][f]=ret;
}

int main()
{
memset(mem,-1,sizeof mem);
cin>>n>>k>>d;
cout<<dp(n,0)<<endl;

    return 0;
}