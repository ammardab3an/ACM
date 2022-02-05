// Problem: K-th Number
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/MKTHNUM/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 1e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct node{
    
    int count;
    node *left, *right;
    
    node(int count, node *left, node *right): 
        count(count), left(left), right(right) {}
        
    node* insert(int l, int r, int w);
};

int n, m;
int arr[NMAX];
int comp[NMAX], comp_sz;
node* root[NMAX];
node* null = new node(0, nullptr, nullptr);

node* node::insert(int l, int r, int w){
        
    if(w < l || r < w){
        return this;
    }
            
    if(l == r){
        return new node(this->count+1, null, null);
    }
    
    int mid = (l+r)/2;
    
    node *left = this->left->insert(l, mid, w);
    node *right = this->right->insert(mid+1, r, w);
    return new node(this->count+1, left, right);
}
    
int query(node *a, node *b, int l, int r, int k){
    
    if(l == r){
        return l;
    }    
    
    int mid = (l+r)/2;
    int cur_count = a->left->count - b->left->count;
    
    if(cur_count >= k){
        return query(a->left, b->left, l, mid, k);
    }
    else{
        return query(a->right, b->right, mid+1, r, k-cur_count);
    }
}

void compress(){
    sort(comp, comp+comp_sz);
    comp_sz = unique(comp, comp+comp_sz) - comp;
    for(int i = 0; i < n; i++){
        arr[i] = lower_bound(comp, comp+comp_sz, arr[i]) - comp;
    }
}

int32_t main(){
    
    fastIO;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        comp[comp_sz++] = arr[i];
    }
    
    compress();
    null->left = null->right = null;
    
    for(int i = 0; i < n; i++){
        root[i] = ((i==0)?null:root[i-1])->insert(0, comp_sz-1, arr[i]);
    }
    
    while(m--){
        
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        
        int ans = query(root[r], (l==0)?null:root[l-1], 0, comp_sz-1, k);
        
        cout << comp[ans] << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
