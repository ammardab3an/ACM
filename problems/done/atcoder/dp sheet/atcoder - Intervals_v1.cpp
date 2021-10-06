// Problem: W - Intervals
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_w
// Memory Limit: 1024 MB
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

vpii intervals[NMAX];

struct seg{

    lli small, lazy;

    void merge(const seg &a, const seg &b){
        small = min(a.small, b.small);
    }

    void add(lli x){
        small += x;
        lazy += x;
    }
};

vector<seg> tree;

lli rec_tmp = 0;
const int TYPE_ADD = 0, TYPE_MIN = 1;

void rec(int id, int low, int high, int q_low, int q_high, int type, lli &x = rec_tmp){

    if(high < q_low || q_high < low)
        return;

    if(q_low <= low && high <= q_high){
        if(type == TYPE_ADD){
            tree[id].add(x);
        }
        else{
            x = min(x, tree[id].small);
        }
        return;
    }
    
    for(auto b : {2 * id, 2 * id + 1})
        tree[b].add(tree[id].lazy);    
    tree[id].lazy = 0;
    
    int mid = (low + high) / 2;
    rec(2 * id, low, mid, q_low, q_high, type, x);
    rec(2 * id + 1, mid+1, high, q_low, q_high, type, x);

    tree[id].merge(tree[2 * id], tree[2 * id + 1]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n, m;
    cin >> n >> m;

    int base = 1;
    while(base <= n+1) base *= 2;

    tree.resize(2 * base, {INFLL, 0});

    lli tot_score = 0;

    for(int i = 0; i < m; i++){
        int l, r, a;
        cin >> l >> r >> a;
        tot_score += a;
        intervals[r].emplace_back(l, a);
    }

    lli answer = 0;
    
    rec(1, 0, base-1, 0, 0, TYPE_ADD, rec_tmp = 0 - INFLL);

    for(int i = 1; i <= n+1; i++){

        for(auto p : intervals[i-1]){
            rec(1, 0, base-1, 0, p.first-1, TYPE_ADD, rec_tmp = p.second);
        }
        
        lli best = INFLL;
        rec(1, 0, base-1, 0, base-1, TYPE_MIN, best);
        
        if(i == n+1) answer = best;
        
        rec(1, 0, base-1, i, i, TYPE_ADD, rec_tmp = best - INFLL);

    }

    cout << tot_score - answer;
}
