// Problem: XOR Sum
// Contest: Virtual Judge - UVALive
// URL: https://vjudge.net/problem/UVALive-4682
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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
	node *nxt[2];
	node(){
		nxt[0] = nxt[1] = nullptr;
	}
};

void dfs_delete(node *nd){
	
	if(!nd) return;
	
	dfs_delete(nd->nxt[0]);
	dfs_delete(nd->nxt[1]);
	delete nd->nxt[0];
	delete nd->nxt[1];
}

struct TrieXOR{
		
	node root;
	
	~TrieXOR(){
		dfs_delete(root.nxt[0]);
		dfs_delete(root.nxt[1]);
	}
	
	void insert(int val){
		
		node *cur = &root;
		
		for(int i = 30; i >= 0; i--){
			
			bool b = (val>>i)&1;
			
			if(!cur->nxt[b]){
				cur->nxt[b] = new node();
			}
			
			cur = cur->nxt[b];
		}
	}
	
	int query(int val){
		
		int ret = 0;
		node *cur = &root;
		
		for(int i = 30; i >= 0; i--){
			
			bool b = (val>>i)&1;
			
			if(cur->nxt[!b]){
				ret ^= (1 << i);
				cur = cur->nxt[!b];
			}
			else{
				cur = cur->nxt[b];
			}
		}
		
		return ret;
	}

};

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
		for(auto &i : vec) cin >> i;
		
		int ans = 0;
		
		TrieXOR tree;
		tree.insert(0);
		
		int _xor = 0;
		
		for(int i = 0; i < n; i++){
			_xor ^= vec[i];
			int cans = tree.query(_xor);
			ans = max(ans, cans);
			tree.insert(_xor);
		}
		
		cout << ans << endl;
    }	
}
