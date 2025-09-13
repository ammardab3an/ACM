// Problem: G. Shorten the Array
// Contest: Codeforces - Codeforces Round 1016 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2093/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

struct DS{
	
	struct node{
		int frq = 0;
		multiset<pii> elements;
		node *nxt[2] = {nullptr, nullptr};
		~node(){
			delete nxt[0];
			delete nxt[1];
		}
	};	
	
	node *root = new node();
	
	void insert(int pos, int val, int d){
		root->frq += d;
		node *cur = root;
		for(int i = 30; i >= 0; i--){
			bool b = (val >> i)&1;
			if(!cur->nxt[b]) cur->nxt[b] = new node();
			cur = cur->nxt[b];
			cur->frq += d;
		}
		if(d==+1){
			cur->elements.insert({pos, val});
		}
		else{
			cur->elements.erase({pos, val});
		}
	}
	
	pii query(int val){
		node *cur = root;
		for(int i = 30; i >= 0; i--){
			bool b = (val >> i)&1;
			if(cur->nxt[!b] && cur->nxt[!b]->frq){
				cur = cur->nxt[!b];
			}
			else{
				cur = cur->nxt[b];
			}
		}
		assert(!cur->elements.empty());
		return *cur->elements.begin();
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int n, k;
		cin >> n >> k;
		
		vi vec(n);
		for(auto &e : vec) cin >> e;
		
		DS ds;
		int ans = INF;
		for(int i = 0; i < n; i++){
			ds.insert(i, vec[i], +1);
			while(ds.root->frq > 0){
				pii cur = ds.query(vec[i]);
				if((cur.second^vec[i]) < k){
					break;
				}
				ans = min(ans, i-cur.first+1);
				ds.insert(cur.first, cur.second, -1);
			}
		}
		
		cout << (ans==INF ? -1 : ans) << endl;
    }	
}
