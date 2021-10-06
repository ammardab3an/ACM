// Problem: L. Reflection
// Contest: Codeforces - International Collegiate Programming Contest, Egyptian Collegiate Programming Contest (ECPC 2018)
// URL: https://codeforces.com/gym/101992/problem/L
// Memory Limit: 1024 MB
// Time Limit: 15000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>      iii;
typedef pair<ll, pll>      lll;
typedef vector<int>         vi;
typedef vector<ll>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
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
 
const int NMAX = 1 << int(ceil(log2(double(1e5+10))));

int tree[NMAX<<2];
int lazy[NMAX<<2];

void push(int nd, int l, int r){
    
    if(!lazy[nd]) return;
    
    tree[nd] *= -1;
    
    if(l != r){
        lazy[nd*2] ^= 1;
        lazy[nd*2+1] ^= 1;
    }    
    
    lazy[nd] = 0;
}

void build(int nd, int l, int r){
    
    if(l == r){
        tree[nd] = l==0 ? 0 : 1;
        return;
    }
    
    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);
    
    tree[nd] = tree[nd*2] + tree[nd*2+1];
}

void update(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(l > q_r || q_l > r) return;
    
    if(q_l <= l && r <= q_r){
        lazy[nd] ^= 1;
        push(nd, l, r);
        return;
    }
    
    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r);
    update(nd*2+1, mid+1, r, q_l, q_r);
    
    tree[nd] = tree[nd*2] + tree[nd*2+1];
}

int query(int nd, int l, int r, int q_l, int q_r){
    
    push(nd, l, r);
    
    if(l > q_r || q_l > r) return 0;
    
    if(q_l <= l && r <= q_r){ 
        return tree[nd];
    }
    
    int mid = (l+r)/2;
    int stPath = query(nd*2, l, mid, q_l, q_r);
    int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
    
    return stPath + ndPath;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("reflection.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        build(1, 0, NMAX-1);
        memset(lazy, 0, sizeof lazy);
        
        int q; cin >> q; while(q--){
            
            int xi;
            cin >> xi;
            
            int yi = query(1, 0, NMAX-1, 0, xi);
            
            cout << yi << endl;
            
            update(1, 0, NMAX-1, xi+1, NMAX-1);
        }        
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
