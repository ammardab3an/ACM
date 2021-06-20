// Problem: D. Lost Tree
// Contest: Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1534/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

typedef unsigned int		uint;
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
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
set<pii> edges;

vi go(int nd){
    cout << "? " << nd << endl;
    vi ret(n);
    for(auto &i : ret) cin >> i;
    return ret;
}

void print_ans(){
    cout << "!" << endl;
    for(auto p : edges){
        cout << p.first << ' ' << p.second << endl;
    }
}

int32_t main(){

    cin >> n;

    vi que = go(1);

    vi even, odd;

    for(int i = 0; i < n; i++){

        if(que[i] == 0)
            continue;

        if(que[i] == 1){
            edges.insert({1, i+1});
        }

        if(que[i]%2==0){
            even.push_back(i+1);
        }
        else{
            odd.push_back(i+1);
        }
    }

    if(even.size() < odd.size()){

        for(auto nd : even){
            vi que = go(nd);
            for(int i = 0; i < n; i++) if(que[i] == 1){
                int u = nd, v = i+1;
                if(u > v) swap(u, v);
                if(!edges.count({u, v}))
                    edges.insert({u, v});
            }
        }
    }
    else{

        for(auto nd : odd){
            vi que = go(nd);
            for(int i = 0; i < n; i++) if(que[i] == 1){
                int u = nd, v = i+1;
                if(u > v) swap(u, v);
                if(!edges.count({u, v}))
                    edges.insert({u, v});
            }
        }
    }

    assert(edges.size() == n-1);

    print_ans();
}
