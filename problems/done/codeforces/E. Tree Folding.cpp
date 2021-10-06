// Problem: E. Tree Folding
// Contest: Codeforces - Codeforces Round #397 by Kaspersky Lab and Barcelona Bootcamp (Div. 1 + Div. 2 combined)
// URL: https://codeforces.com/problemset/problem/765/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

vi adj[NMAX];

int dfs(int nd, int par){

    int len = 0;
    set<int> st;

    for(int nxt : adj[nd]) if(nxt != par){

        int tmp = dfs(nxt, nd);

        st.insert(tmp);

        if((tmp == -1) || (par && st.size() > 1) || (!par && st.size() > 2)){
                len = -1;
                break;
        }
    }

    if(len != -1) for(auto i : st) len += i+1;

    return len;
}

int _u, _v, _nd, _dis;
void go(int nd, int par, int dis){

    if(adj[nd].size() == 1 && par){
        if(dis >= _dis){
            _nd = nd;
            _dis = dis;
        }
        return;
    }

    for(auto nxt : adj[nd]) if(nxt != par){
        go(nxt, nd, dis+1);
    }
}

bool go2(int nd, int par, int dis){

    if(nd == _v){
        return true;
    }

    for(auto nxt : adj[nd]) if(nxt != par){
        if(go2(nxt, nd, dis+1)){
            if(dis == (_dis+1)/2){
                _nd = nd;
            }
            return true;
        }
    }

    return false;
}

int main(){

    fastIO;

    #ifdef LOCAL
        freopenI;
        freopenO;
    #endif

    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    go(1, 0, 0);
    _u = _nd;
    go(_u, 0, 0);
    _v = _nd;
    go2(_u, 0, 0);

    int ans = dfs(_nd, 0);

    if(ans == -1)
        cout << -1;
    else{
        while(ans%2==0) ans /= 2;
        cout << ans;
    }
}