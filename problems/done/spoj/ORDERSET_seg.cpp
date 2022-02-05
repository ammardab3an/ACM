// Problem: B - Order statistic set
// Contest: Virtual Judge - DS & DP #1
// URL: https://vjudge.net/contest/442197#problem/B
// Memory Limit: 1572 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int m;
pair<char, int> q[MMAX];
int comp[MMAX], comp_sz;
int tree[MMAX << 2];

void compress(){
    
    sort(comp, comp+comp_sz);
    comp_sz = unique(comp, comp+comp_sz) - comp;
    
    for(int i = 0; i < m; i++){
        
        if(q[i].first != 'K')
            q[i].second = lower_bound(comp, comp+comp_sz, q[i].second) - comp;
    }
    
}

void update(int nd, int l, int r, int p, int val){
    
    if(p < l || r < p) return;
    
    if(l == r){
        tree[nd] += val;
        tree[nd] = max(tree[nd], int(0));
        tree[nd] = min(tree[nd], int(1));
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, p, val);
    update(nd*2+1, mid+1, r, p, val);
    
    tree[nd] = tree[nd*2] + tree[nd*2+1];
}

int query_bs(int nd, int l, int r, int k){
    
    if(l == r){
        return l;
    }    
    
    int mid = (l+r)/2;
    if(tree[nd*2] >= k) return query_bs(nd*2, l, mid, k);
    else return query_bs(nd*2+1, mid+1, r, k-tree[nd*2]);
}

int query_sum(int nd, int l, int r, int q_l, int q_r){
    
    if(l > q_r || q_l > r) return 0;
    
    if(q_l <= l && r <= q_r) return tree[nd];
    
    int mid = (l+r)/2;
    int stPath = query_sum(nd*2, l, mid, q_l, q_r);
    int ndPath = query_sum(nd*2+1, mid+1, r, q_l, q_r);
    
    return stPath + ndPath;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> m;
    for(int i = 0; i < m; i++){
        
        cin >> q[i].first >> q[i].second;
        
        if(q[i].first != 'K')
            comp[comp_sz++] = q[i].second;
    }
    
    compress();
    
    for(int i = 0; i < m; i++){
        
        switch(q[i].first){
            
            case 'I':
            update(1, 0, comp_sz-1, q[i].second, +1);
            break;
            
            case 'D':
            update(1, 0, comp_sz-1, q[i].second, -1);
            break;
            
            case 'K':
            if(q[i].second > tree[1]){
                cout << "invalid" << endl;
            }
            else{
                int que = query_bs(1, 0, comp_sz-1, q[i].second);
                cout << comp[que] << endl;
            }
            break;
            
            case 'C':
            cout << query_sum(1, 0, comp_sz-1, 0, q[i].second-1) << endl;
            break;
        }
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
