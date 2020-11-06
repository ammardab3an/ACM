// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

// Global Variables

const int MAX = 4e5 + 10;

int cnt = 1;
int clr[MAX];
vi  adj[MAX];

int rev0[MAX];
pii rev1[MAX];

lli   seg[MAX << 2];
bool lazy[MAX << 2];

void dfs(int nd, int pr){

    rev0[cnt]      = nd;
    rev1[nd].first = cnt++;

    for(auto to : adj[nd]) if(to != pr)
        dfs(to, nd);

    rev1[nd].second = cnt -1;
}

void segBuild(int nd, int l, int r){

    if(l == r){
        seg[nd] = 1LL << clr[rev0[l]];
        return;
    }

    int mid = (l + r)/2;
    segBuild(nd*2, l, mid);
    segBuild(nd*2+1, mid+1, r);

    seg[nd] = seg[nd*2] | seg[nd*2+1];
}

void push(int nd){
    seg[nd*2] = seg[nd*2+1] = seg[nd];
    lazy[nd*2] = lazy[nd*2+1] = true;
    lazy[nd] = false;
}

lli segQuery(int nd, int l, int r, int a, int b){

    if(b < l || r < a)
        return 0;

    if(a <= l && r <= b)
        return seg[nd];

    if(lazy[nd]) push(nd);

    int mid = (l + r)/2;
    lli stPath = segQuery(nd*2, l, mid, a, b);
    lli ndPath = segQuery(nd*2+1, mid+1, r, a, b);

    return stPath | ndPath;
}

void segUpdate(int nd, int l, int r, int a, int b, int c){

    if(b < l || r < a)
        return;

    if(a <= l && r <= b){
        seg[nd] = 1LL << c;
        lazy[nd] = true; // because we use lazy, we are going to break immediately.
        return;
    }

    if(lazy[nd]) push(nd);

    int mid = (l + r)/2;
    segUpdate(nd*2, l, mid, a, b, c);
    segUpdate(nd*2+1, mid+1, r, a, b, c);

    seg[nd] = seg[nd*2] | seg[nd*2+1];
}

int main(){

    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)
        scanf("%d", &clr[i]);

    for(int i = 0; i < n-1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    segBuild(1, 1, n);

    while(m--){

        int fn, u, c;
        scanf("%d%d", &fn, &u);

        if(fn == 1){
            scanf("%d", &c);
            segUpdate(1, 1, n, rev1[u].first, rev1[u].second, c);
        }
        else
            printf("%d\n", __builtin_popcountll(segQuery(1, 1, n, rev1[u].first, rev1[u].second)));

    }
}
