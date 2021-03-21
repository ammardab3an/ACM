// Problem: E. Fib-tree
// Contest: Codeforces - Codeforces Global Round 13
// URL: https://codeforces.com/contest/1491/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int n;
int sz[NMAX];
vpii adj[NMAX];
vector<int> fib;

int getSize(int nd, int par){

    int csz = 1;
    for(auto [nxt, flag] : adj[nd]){
        if(nxt != par && !flag){
            csz += getSize(nxt, nd);
        }
    }
    return sz[nd] = csz;
}

void cutEdge(int nd, int par, int k, int &pu, int &pv, int &kd){

    for(auto [nxt, flag] : adj[nd]){
        if(nxt != par && !flag){
    
            if(sz[nxt] == fib[k-1] || sz[nxt] == fib[k-2]){
                pu = nd, pv = nxt;
                kd = sz[nxt] == fib[k-1] ? k-1 : k-2;
                break;
            }
    
            cutEdge(nxt, nd, k, pu, pv, kd);
            if(pu+1) return;
        }
    }
}

bool check(int nd, int k){

    if(k <= 1) return true;

    getSize(nd, -1);

    int pu = -1, pv = -1, kd = -1;
    cutEdge(nd, -1, k, pu, pv, kd);
    
    if(pu == -1) return false;
    
    for(auto &p : adj[pu])
        if(p.first == pv) p.second = true;
    for(auto &p : adj[pv])
        if(p.first == pu) p.second = true;

    return check(pv, kd) && check(pu, kd == k-1 ? k-2 : k-1);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;

    fib.push_back(1);
    fib.push_back(1);
    for(int i = 1; fib[i] < n; i++){
        fib.push_back(fib[i] + fib[i-1]);
    }

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v; u--, v--;
        adj[u].emplace_back(v, false);
        adj[v].emplace_back(u, false);
    }

    cout << (n == fib.back() && check(0, fib.size()-1) ? "YES" : "NO") << endl;
}