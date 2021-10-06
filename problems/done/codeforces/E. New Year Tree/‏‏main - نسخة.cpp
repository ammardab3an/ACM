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

int arr[MAX];
int par[MAX];
vi  adj[MAX];
lli tree[MAX];

void build(int nd){
    if(nd != 1){
        tree[par[nd]] |= tree[nd];
        build(par[nd]);
    }
}

void colorDown(int nd, int color){
    arr[nd] = color;
    for(int nxt : adj[nd])
        colorDown(nxt, color);
}

void foo(int n){
    for(int i = 1; i <= n; i++) tree[i] = 1LL << arr[i];
    for(int i = 1; i <= n; i++) build(i);
}

int main(){

    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        par[v] = u;
    }

    foo(n);

    while(m--){

        int fn, u; cin >> fn >> u;

        if(fn == 1){
            int c; cin >> c;
            colorDown(u, c); foo(n);
        }

        else
            cout << __builtin_popcount(tree[u]) << endl;

    }
}
