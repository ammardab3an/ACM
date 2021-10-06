/*
 * Aur0Ra
 */
#include <bits/stdc++.h>
#define ll long long
#define sf scanf
#define pf printf
#define to(ww,u,v) for(int ww=u;ww<=v;ww++)
#define tor(ww,u,v) for(int ww=u;ww>=v;ww--)
#define B break
#define C continue
#define P push_back
#define Pb pop_back
#define E "\n"
#define F first
#define S second
//%[^\n]%*c
using namespace std;
void file()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
const unsigned int inf=4294967295,inf1=1e9+7,inf2=1e9+9;
const int N=2e5+10,M=100,mod=1e9+7;
int tc;
ll n,k,ans,org;

int main()
{
    
    sf("%lld%lld",&n,&k);
  
    if(k==1)
        ans=n;
    else {
        org=log2l(n)+1;
        ans=(1LL<<org)-1;
    }
    
    pf("%lld\n",ans);
}