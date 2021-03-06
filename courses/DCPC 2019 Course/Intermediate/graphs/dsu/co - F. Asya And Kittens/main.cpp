#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair
#define mod 1000000007

using namespace std;

int n;
int per[200200];
int in[200200];
int sz[200200];
int pr(int x){
    if(per[x] == x)return x;
    int pp = pr(per[x]);
    in[x] = in[x] + in[per[x]];
    return per[x] = pp;
}
int res[200200];

int main()  {
    int n;
    cin>>n;
    int x,y;
    for(int i=1; i <=n ;i ++){
        in[i] = 0;
        per[i] = i;
        sz[i] = 1;
    }

    for(int i=0 ;i <n-1 ;i ++){
        scanf("%d%d",&x,&y);
        x = pr(x);
        y = pr(y);
        in[y] = sz[x];
        sz[x] += sz[y];
        per[y] = x;
    }

    for(int i=1 ;i <=n ;i ++){
        pr(i);
        res[in[i]] = i;
    }
    for(int i=0 ;i <n ;i ++){
        printf("%d ",res[i]);
    }
    return 0;
}
