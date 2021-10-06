// Problem: E. Turn Off The TV
// Contest: Codeforces - Educational Codeforces Round 29
// URL: https://codeforces.com/contest/863/problem/E
// Memory Limit: 256 MB
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int tree[(NMAX*3) << 2];
int lazy[(NMAX*3) << 2];

void push(int nd, int l, int r){
	
	tree[nd] += lazy[nd] * (r-l+1);
	
	if(l != r){
		lazy[nd*2] += lazy[nd];
		lazy[nd*2+1] += lazy[nd];	
	}
	
	lazy[nd] = 0;
}

void build(int nd, int l, int r){
	
	push(nd, l, r);
	
	if(l == r){
		tree[nd] = min(tree[nd], 2 * (r-l+1));
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = tree[nd*2] + tree[nd*2+1];
	tree[nd] = min(tree[nd], 2 * (r-l+1));
}

void update(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(l > q_r || q_l > r) return;	
	
	if(q_l <= l && r <= q_r){
		
		lazy[nd] += 1;
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
	
	if(q_l <= l && r <= q_r) return tree[nd];
	
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
	
	int n;
	cin >> n;
	
	set<int> st;
	map<int, int> mp;
	
	vpii vec(n);
	for(auto &i : vec){
		cin >> i.first >> i.second;
		st.insert(i.first);
		st.insert(i.first-1);
		st.insert(i.second);
	}
	
	int sz = 0;	
	for(auto i : st) mp[i] = sz++;
	
	for(auto &i : vec){
		i.first = mp[i.first];
		i.second = mp[i.second];
		update(1, 0, sz, i.first, i.second);
	}
	
	build(1, 0, sz);
	
	int ans = -1, idx = 1;
	
	for(auto i : vec){
		
		int l = i.first;
		int r = i.second;
		
		int que = query(1, 0, sz, l, r);
		
		if(que >= (r-l+1)*2){
			ans = idx;
			break;
		}
		
		idx++;
	}
	
	cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
