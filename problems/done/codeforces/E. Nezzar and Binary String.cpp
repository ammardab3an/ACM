// Problem: E. Nezzar and Binary String
// Contest: Codeforces - Codeforces Round #698 (Div. 2)
// URL: https://codeforces.com/contest/1478/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
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

struct node{
	pii cnt = {0, 0};
	int lazy = -1;
};

int n, m;
string str_f, str_t;
node tree[NMAX << 2];

pii merge(const pii &a, const pii &b){
	return {a.first+b.first, a.second+b.second};
}

void push(int nd, int l, int r){
	
	if(tree[nd].lazy != -1){
		
		tree[nd].cnt.first = (r-l+1) * (tree[nd].lazy==0);
		tree[nd].cnt.second = (r-l+1) * (tree[nd].lazy==1);
		
		if(l != r){
			tree[nd*2].lazy = tree[nd].lazy;
			tree[nd*2+1].lazy = tree[nd].lazy;
		}
		
		tree[nd].lazy = -1;
	}
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd].cnt.first = str_t[l]=='0';
		tree[nd].cnt.second = str_t[l]=='1';
		tree[nd].lazy = -1;
		return;
	}	
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd].cnt = merge(tree[nd*2].cnt, tree[nd*2+1].cnt);
	tree[nd].lazy = -1;
}

void update(int nd, int l, int r, int q_l, int q_r, int v){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}
	
	if(q_l <= l && r <= q_r){
		tree[nd].lazy = v;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, v);
	update(nd*2+1, mid+1, r, q_l, q_r, v);
	
	tree[nd].cnt = merge(tree[nd*2].cnt, tree[nd*2+1].cnt);
}

pii query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return {0, 0};
	}	
	if(q_l <= l && r <= q_r){
		return tree[nd].cnt;
	}
	
	int mid = (l+r)/2;
	pii st_path = query(nd*2, l, mid, q_l, q_r);
	pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return merge(st_path, nd_path);
}

bool check(int nd, int l, int r){
	
	push(nd, l, r);
	
	if(l==r){
		return str_f[l] == ("01"[tree[nd].cnt.second]);
	}
	
	int mid = (l+r)/2;
	bool st_path = check(nd*2, l, mid);
	bool nd_path = check(nd*2+1, mid+1, r);
	
	return st_path && nd_path;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n >> m;
		cin >> str_f >> str_t;
		
		vpii tmp(m);
		for(auto &p : tmp){
			cin >> p.first >> p.second;
			p.first--, p.second--;
		}
		
		bool ans = true;
		
		build(1, 0, n-1);
		
		for(int i = m-1; i >= 0; i--){
			
			int l = tmp[i].first;
			int r = tmp[i].second;
			
			pii q = query(1, 0, n-1, l, r);
			
			if(q.first==0 || q.second==0){
				continue;
			}
			
			if(q.first==q.second){
				ans = false;
				break;		
			}
			
			update(1, 0, n-1, l, r, q.first < q.second);
		}
		
		if(ans){		
			ans &= check(1, 0, n-1);
		}
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
