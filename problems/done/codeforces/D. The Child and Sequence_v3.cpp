// Problem: D. The Child and Sequence
// Contest: Codeforces - Codeforces Round #250 (Div. 1)
// URL: https://codeforces.com/contest/438/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 1e5 + 10;

int n, m;
int arr[NMAX];

struct segtree{
	
	int sum, maxi;
	segtree *left, *right;
	
	segtree(int l, int r){
		if(l==r){
			sum = maxi = arr[l];
		}
		else{
			int mid = (l+r)/2;
			left = new segtree(l, mid);
			right = new segtree(mid+1, r);
			pull();
		}
	}
	
	pull(){
		sum = left->sum + right->sum;
		maxi = max(left->maxi, right->maxi);
	}
	
	void update(int l, int r, int q_l, int q_r, int x){
		if(l > q_r || q_l > r || maxi < x){
			return;
		}
		else if(l == r){
			maxi %= x;
			sum = maxi;
		}
		else{
			int mid = (l+r)/2;
			left->update(l, mid, q_l, q_r, x);
			right->update(mid+1, r, q_l, q_r, x);
			pull();
		}
	}
	
	void set(int l, int r, int p, int x){
		if(p < l || r < p){
			return;
		}
		else if(l == r){
			sum = maxi = x;
		}
		else{
			int mid = (l+r)/2;
			left->set(l, mid, p, x);
			right->set(mid+1, r, p, x);
			pull();
		}
	}
	
	int query(int l, int r, int q_l, int q_r){
		
		if(l > q_r || q_l > r){
			return 0;
		}
		else if(q_l <= l && r <= q_r){
			return sum;
		}
		else{
			int mid = (l+r)/2;
			int stPath = left->query(l, mid, q_l, q_r);
			int ndPath = right->query(mid+1, r, q_l, q_r);
			return stPath + ndPath;
		}
	}
};

int32_t main(){
    
    fastIO;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    segtree tree(0, n-1);
    
    while(m--){
    	
    	int q;
    	cin >> q;
    	
    	if(q == 1){
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		int que = tree.query(0, n-1, l, r);
    		cout << que << endl;
    	}
    	else if(q == 2){
    		int l, r, x;
    		cin >> l >> r >> x;
    		l--, r--;
    		tree.update(0, n-1, l, r, x);
    	}
    	else {
    		int k, x;
    		cin >> k >> x;
    		k--;
    		tree.set(0, n-1, k, x);
    	}
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
