
// L. Permutation Compression
// https://qoj.ac/contest/1099/problem/5466?v=1 

// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m, k;
int arr[NMAX];
int pos[NMAX];

struct node{
	int mx;
	int cnt;
} tree[NMAX << 2];

node merge(const node &a, const node &b){
	return (node) {max(a.mx, b.mx), a.cnt+b.cnt};
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = (node){arr[l], 1};
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update_del(int nd, int l, int r, int p){
	
	if(l==r){
		tree[nd] = (node){0, 0};
		return;
	}	
	
	int mid = (l+r)/2;
	
	if(p <= mid){
		update_del(nd*2, l, mid, p);	
	}
	else{	
		update_del(nd*2+1, mid+1, r, p);
	}
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

node query(int nd, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return (node){0, 0};
	}	
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	node st_path = query(nd*2, l, mid, q_l, q_r);
	node nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return merge(st_path, nd_path);
}

int query_bs(int nd, int l, int r, int q_l, int q_r, int x, bool lf_ri){
	
	if(r < q_l || q_r < l){
		return lf_ri ? n : -1;
	}
	
	if(q_l <= l && r <= q_r && tree[nd].mx <= x){
		return lf_ri ? r+1 : l-1;
	}
	
	if(l==r){
		return l;
	}
	
	int mid = (l+r)/2;
	
	if(lf_ri){
		int st_path = query_bs(nd*2, l, mid, q_l, q_r, x, lf_ri);
		if(st_path <= mid) return st_path;
		else return query_bs(nd*2+1, mid+1, r, q_l, q_r, x, lf_ri);
	}
	else{
		int st_path = query_bs(nd*2+1, mid+1, r, q_l, q_r, x, lf_ri);
		if(st_path > mid) return st_path;
		else return query_bs(nd*2, l, mid, q_l, q_r, x, lf_ri);
	}
}

int32_t main(){
    
    fastIO;
	
    int t; cin >> t; while(t--){

		cin >> n >> m >> k;
		
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			pos[arr[i]] = i;
		}
		
		vi tmp(m), del;
		for(auto &i : tmp) cin >> i;
		
		vi vec(k), need;
		for(auto &e : vec) cin >> e;
		
		bool bad = false;
		for(int i = 0, j = 0; i < n; i++){
			
			if(j==m ||  arr[i]!=tmp[j]){
				del.push_back(arr[i]);
			}
			else{
				j++;
			}
			
			if(i==n-1 && j!=m){
				bad = true;
			}
		}
		
		if(bad){
			cout << "NO" << endl;
			continue;
		}
		
		sort(del.begin(), del.end(), greater<int>());
		
		build(1, 0, n-1);
		
		for(auto e : del){
			
			int p = pos[e];
			int p_l = query_bs(1, 0, n-1, 0, p, e, false)+1;
			int p_r = query_bs(1, 0, n-1, p, n-1, e, true)-1;
			
			assert(0 <= p_l && p_l <= p && p <= p_r && p_r < n);
			
			int len = query(1, 0, n-1, p_l, p_r).cnt;
			need.push_back(len);
			
			update_del(1, 0, n-1, p);
		}
		
		sort(vec.begin(), vec.end());
		sort(need.begin(), need.end());
		
		bool ans = true;
		
		int j = 0;
		for(auto e : need){
			if(j==vec.size() || vec[j] > e){
				ans = false;
				break;
			}
			else{
				j++;
			}
		}
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
