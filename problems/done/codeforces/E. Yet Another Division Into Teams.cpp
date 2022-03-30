// Problem: E. Yet Another Division Into Teams
// Contest: Codeforces - Codeforces Round #598 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1256/E
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

pii tree[NMAX << 2];

pii query(int nd, int l, int r, int q_l, int q_r){
	
	if(q_r < l || r < q_l){
		return {INFLL, -1};
	}	
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	pii st_path = query(nd*2, l, mid, q_l, q_r);
	pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return min(st_path, nd_path);
}

void update(int nd, int l, int r, int p, int val){
	
	if(p < l || r < p){
		return;
	}
	
	if(l==r){
		tree[nd] = {val, l};
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, p, val);
	update(nd*2+1, mid+1, r, p, val);
	
	tree[nd] = min(tree[nd*2], tree[nd*2+1]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	int n;
	cin >> n;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	vi pos(n);
	iota(pos.begin(), pos.end(), 0);
	sort(pos.begin(), pos.end(), [&](int i, int j){
		return vec[i] < vec[j];
	});
	
	vi dp(n);
	vi par(n);	
	
	for(int i = 2; i < n; i++){
		
		int p = pos[i];
		int v = vec[pos[i]];
		
		int cans = INFLL;
		
		if(i <= 2){
			cans = INFLL;
		}
		else if(i-3 >= 0){
			pii que = query(1, 0, n-1, 2, i-3);
			int tans = v + que.first;
			if(i+1 < n) tans -= vec[pos[i+1]];
			cans = tans;
			par[i] = que.second;
		}
		
		if(i-2 >= 0){
			int tans = v - vec[pos[0]];
			if(i+1 < n) tans -= vec[pos[i+1]];
			if(tans < cans){
				cans = tans;
				par[i] = -1;
			}
		}
		
		dp[i] = cans;
		update(1, 0, n-1, i, cans);
	}
	
	
	vi ans(n);
	int cnt = 1;
	
	int cur = n-1;
	while(true){
		
		int nxt = par[cur];
		for(int i = nxt+1; i <= cur; i++){
			ans[pos[i]] = cnt;
		}
		
		if(nxt==-1) break;
		
		cur = nxt;
		cnt++;
	}
	
	cout << dp[n-1] << ' ' << cnt << endl;
	for(int i = 0; i < n; i++) cout << ans[i] << ' ' ; cout << endl;
}
