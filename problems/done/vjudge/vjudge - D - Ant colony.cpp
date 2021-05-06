// Problem: D - Ant colony
// Contest: Virtual Judge - Contest 2
// URL: https://vjudge.net/contest/436948#problem/D
// Memory Limit: 262 MB
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

const int NMAX = 1e5 + 10;

int n;
int arr[NMAX];
int tree_gcd[NMAX << 2];
pii tree_min[NMAX << 2];

pii merge_min(pii nd0, pii nd1){
	
	if(nd0.first != nd1.first){
		return nd0.first < nd1.first ? nd0 : nd1;
	}	
	return {nd0.first, nd0.second + nd1.second};
}

void build_min(int nd, int l, int r){
	
	if(l == r){
		tree_min[nd] = {arr[l], 1};
		return;
	}
	
	int mid = (l+r)/2;
	build_min(nd*2, l, mid);
	build_min(nd*2+1, mid+1, r);
	
	tree_min[nd] = merge_min(tree_min[nd*2], tree_min[nd*2+1]);
}

pii query_min(int nd, int l, int r, int q_l, int q_r){
	
	if(l > q_r || q_l > r) return {INF, 0};
	
	if(q_l <= l && r <= q_r){
		return tree_min[nd];
	}	
	
	int mid = (l+r)/2;
	pii stPath = query_min(nd*2, l, mid, q_l, q_r);
	pii ndPath = query_min(nd*2+1, mid+1, r, q_l, q_r);
	
	return merge_min(stPath, ndPath);
}

int merge_gcd(int nd0, int nd1){
	return __gcd(nd0, nd1);
}

void build_gcd(int nd, int l, int r){
	
	if(l == r){
		tree_gcd[nd] = arr[l];
		return;
	}
	
	int mid = (l+r)/2;
	build_gcd(nd*2, l, mid);
	build_gcd(nd*2+1, mid+1, r);
	
	tree_gcd[nd] = merge_gcd(tree_gcd[nd*2], tree_gcd[nd*2+1]);
}

int query_gcd(int nd, int l, int r, int q_l, int q_r){
	
	if(l > q_r || q_l > r) return 0;
	
	if(q_l <= l && r <= q_r){
		return tree_gcd[nd];
	}	
	
	int mid = (l+r)/2;
	int stPath = query_gcd(nd*2, l, mid, q_l, q_r);
	int ndPath = query_gcd(nd*2+1, mid+1, r, q_l, q_r);
	
	return merge_gcd(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	cin >> n;
	for(int i = 1;  i <= n; i++) cin >> arr[i];
	
	build_min(1, 1, n);
	build_gcd(1, 1, n);
	
	int q; cin >> q; while(q--){
		
		int l, r;
		cin >> l >> r;
		
		int cgcd = query_gcd(1, 1, n, l, r);
		pii cmin = query_min(1, 1, n, l, r);
		
		if(cmin.first == cgcd){
			cout << r-l+1 - cmin.second << endl;
		}
		else{
			cout << r-l+1 << endl;
		}
	}
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
