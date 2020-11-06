#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair
#define mod 1000000007

using namespace std;

ll a[100100];

pair<ll,pii>ed[100100];
ll sz[100100];
int per[100100];

int getper(int x){
    if(x == per[x])
        return x;
    return per[x] = getper(per[x]);
}

void merg(int x,int y){
    x = getper(x);
    y = getper(y);
    if(sz[x] > sz[y])swap(x,y);
    per[x] = per[y];
    sz[y] += sz[x];
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=1 ; i<=n ; i++){
        scanf("%I64d",&a[i]);
        per[i] = i;
        sz[i] = 1;
    }
    int x,y;
    for(int i=0 ; i<m ; i++){
        scanf("%d%d",&x,&y);
        ed[i] = mp(min(a[x],a[y]),mp(x,y));
    }

    sort(ed,ed+m);
    ll res = 0;
    for(int i=m-1 ;i >= 0 ; i--){
        int x = ed[i].sc.fr;
        int y = ed[i].sc.sc;
        ll cost = ed[i].fr;

        if(getper(x) == getper(y))continue;
        res += sz[getper(x)]*sz[getper(y)]*cost;
        merg(x,y);
    }
    double r = res/(1.0*n*(n-1));
    r *=2;
    cout<<fixed<<setprecision(10)<<r;
    return 0;
}
