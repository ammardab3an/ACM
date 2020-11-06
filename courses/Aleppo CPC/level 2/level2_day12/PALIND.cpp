#include<bits/stdc++.h>
using namespace std;

const int N=5050;

int n;
char a[N];
int mem[N][N];

int dp(int l,int r){
    if(l >= r)
        return 0;

    if(mem[l][r] != -1)
        return mem[l][r];

    if(a[l] != a[r])
        return mem[l][r]=min(1+dp(l+1,r) , 1+dp(l,r-1));

    return mem[l][r]=dp(l+1,r-1);
}

int main()
{
    scanf("%d",&n);
    scanf("%s",&a);

    memset(mem,-1,sizeof mem);
    printf("%d\n",dp(0,n-1));

    return 0;
}
