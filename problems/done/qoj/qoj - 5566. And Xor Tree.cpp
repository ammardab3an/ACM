// 5566. And Xor Tree
// https://qoj.ac/problem/5566

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353; // 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}

const int NMAX = 1e5 + 10;

vector<vi> adj;
int good[NMAX];
int cans[3];

array<array<int, 4>, 3> calc(int u){
	
	int cval = good[u];
	array<array<int, 4>, 3> sm = {0};
	array<array<int, 4>, 3> cur = {0};
	
	for(auto v : adj[u]){
		
		auto nxt = calc(v);
		
		for(int i = 0; i < 4; i++){
			cur[0][i&cval] += nxt[0][i];
			cur[1][i|cval] += nxt[1][i];
			cur[2][i^cval] += nxt[2][i];
		}
		
		for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++){
			
			if((i&j&cval) == 3){
				cans[0] += 2 * sm[0][i] * nxt[0][j];
			}
			
			if((i|j|cval) == 3){
				cans[1] += 2 * sm[1][i] * nxt[1][j];	
			}
			
			if((i^j^cval) == 3){
				cans[2] += 2 * sm[2][i] * nxt[2][j];	
			}
		}
		
		for(int i = 0; i < 3; i++)
		for(int j = 0; j < 4; j++){
			sm[i][j] += nxt[i][j];
		}	
	}
	
	for(int i = 0; i < 3; i++){
		cans[i] += 2 * cur[i][3];
	}
		
	for(int i = 0; i < 3; i++){
		cur[i][cval]++;
	}	
	
	if(cval==3){
		for(int i = 0; i < 3; i++){
			cans[i]++;
		}
	}
	
	return cur;
}

int tin[NMAX], tim;
void dfs(int u, int p){
	tin[u] = tim++;
	if(p != -1) adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
	for(auto v : adj[u]) if(v != p){
		dfs(v, u);
	}
}

int32_t main(){
    
    fastIO;
	
	int n;
	cin >> n;
	
	vi vec(n);
	for(auto &i : vec) cin >> i;
	
	adj.resize(n);
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	if(n==0){
		n = 1e5;
		vec = vi(n);
		adj.resize(n);
		for(auto &i : vec) i = rand(0, 1<<25);
		for(int i = 1; i < n; i++){
			int p = rand(0, i-1);
			adj[p].push_back(i);
			adj[i].push_back(p);
		}
	}
	
	{
		
		dfs(0, -1);
		
		vi nvec(n);
		vector<vi> nadj(n);
		
		for(int i = 0; i < n; i++){
			nvec[tin[i]] = vec[i];
		}
		
		for(int i = 0; i < n; i++){
			for(auto v : adj[i]){
				nadj[tin[i]].push_back(tin[v]);
			}
		}
	
		vec.swap(nvec);
		adj.swap(nadj);
	}
	
	array<int, 3> ans = {0};
	
	for(int p = 0; p < 25; p++)
	for(int q = 0; q <= p; q++){
		
		for(int i = 0; i < n; i++){
			good[i] = (((vec[i]>>p)&1)<<1) | ((vec[i]>>q)&1);
		}
		
		int cval = mul(1<<p, 1<<q);
		if(p != q) cval = mul(cval, 2);
		
		memset(cans, 0, sizeof cans);
		
		calc(0);
		
		for(int i = 0; i < 3; i++){
			ans[i] = add(ans[i], mul(cans[i], cval));
		}
	}
	
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
}