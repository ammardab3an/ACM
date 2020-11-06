
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >

typedef unsigned long long ull;
typedef long double ldbl;
typedef long long ll;
typedef double dbl;

const ldbl E = 2.71828182845904523536;
const ldbl pi = acos(-1);
const dbl eps = 1e-9;
const ll mod = 1e9+7;
const ll inf = 1LL<<30;

/** /////////// ** Code ** /////////// **/

const int N=1010;

int mem[N][N];
int a[N];
int n;

int dp(int i,int last){
    if(i > n)
        return 0;

    if(mem[i][last] != -1)
        return mem[i][last];

    int path1=0 , path2=0;
    if(a[i] > a[last] ) path1=1+dp(i+1,i);
    path2=dp(i+1,last);

    return mem[i][last]=max(path1,path2);
}

int main()
{
    cin>>n;
    for(int i=1 ; i<=n ; i++)
        cin>>a[i];

    memset(mem,-1,sizeof mem);
    int ans=dp(1,0);
    cout<<ans<<endl;

    return 0;
}