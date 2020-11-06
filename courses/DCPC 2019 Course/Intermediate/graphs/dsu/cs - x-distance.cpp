#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair
#define mod 1000000007

using namespace std;

const int N = 3e5+10;

pair<ll,pii>ed[N];
int per[N];
ll sz[N];

int pr(int x){
    if(x == per[x])return x;
    return per[x] = pr(per[x]);
}


int main()  {
    ll n,m,x;
    cin>>n>>m>>x;
    int a,b;
    ll w;
    for(int i=1; i <=n  ;i ++){
        per[i] = i;
        sz[i] = 1;
    }

    for(int i=0 ;i<m ;i ++){
        scanf("%d%d%lld",&a,&b,&w);
        ed[i] = {w,{a,b}};
    }
    sort(ed,ed+m);
    ll res = 0;
    for(int i=0 ;i <m; i ++){
        a = ed[i].sc.fr;
        b = ed[i].sc.sc;
        a = pr(a);
        b = pr(b);
        w = ed[i].fr;
        if(a == b)continue;
        if(w == x){
            res += sz[a]*sz[b];
        }
        if(sz[a] < sz[b])swap(a,b);
        sz[a] += sz[b];
        per[b] = a;
    }
    cout<<res<<endl;
    return 0;
}
