// Problem: E. Palindromic Doubles
// Contest: Codeforces - Kotlin Heroes: Episode 6
// URL: https://codeforces.com/problemset/problem/1488/E
// Memory Limit: 256 MB
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
 
const int NMAX = 250000 + 10;

int tree[NMAX << 2];

void build(int nd, int l, int r){
	
	if(l == r){
		tree[nd] = 0;
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = 0;
}

int query(int nd, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return 0;
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	int st_path = query(nd*2, l, mid, q_l, q_r);
	int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return max(st_path, nd_path);
}

void update(int nd, int l, int r, int p, int val){
	
	if(p < l || r < p){
		return;
	}	
	
	if(l==r){
		tree[nd] = val;
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p, val);
	update(nd*2+1, mid+1, r, p, val);
	
	tree[nd] = max(tree[nd*2], tree[nd*2+1]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i, --i;
		
		vpii pairs;
		
		{
			vector<vi> tmp(n);
			for(int i = 0; i < n; i++){
				tmp[vec[i]].push_back(i);
				if(tmp[vec[i]].size() == 2){
					pairs.push_back((pii){tmp[vec[i]][1], tmp[vec[i]][0]});
				}
			}
		}
		
		sort(pairs.begin(), pairs.end());
		
		int ans = 1;
		build(1, 0, n-1);
		
		for(auto [r, l] : pairs){
			
			int que = query(1, 0, n-1, l, r);
			int cans = que+2;
			
			if(cans==2 && l+1<r){
				cans++;
			}
			
			ans = max(ans, cans);
			update(1, 0, n-1, l, cans);
		}
		
		cout << ans << endl;
    }	
}
