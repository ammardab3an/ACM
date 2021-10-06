// Problem: F. Ant colony
// Contest: Codeforces - Codeforces Round #271 (Div. 2)
// URL: https://codeforces.com/problemset/problem/474/F
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

const int NMAX = 1e5 + 10;

int n;
int arr[NMAX];
int tree[NMAX << 2];

void build(int nd, int l, int r){
	
	if(l == r){
		tree[nd] = arr[l];
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = __gcd(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){
	
	if(l > q_r || q_l > r) return 0;
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}	
	
	int mid = (l+r)/2;
	int stPath = query(nd*2, l, mid, q_l, q_r);
	int ndPath = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return __gcd(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	cin >> n;
	for(int i = 1;  i <= n; i++) cin >> arr[i];
	
	build(1, 1, n);
	
	vpii vec;
	for(int i = 1; i <= n; i++){
	    vec.emplace_back(arr[i], i);
	}
	
	sort(vec.begin(), vec.end());
	
	int q; cin >> q; while(q--){
		
		int l, r;
		cin >> l >> r;
		
		int cgcd = query(1, 1, n, l, r);
		int mn_cnt = upper_bound(vec.begin(), vec.end(), (pii){cgcd, r}) - lower_bound(vec.begin(), vec.end(), (pii){cgcd, l});
		cout << r-l+1 - mn_cnt << endl;
	}
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    