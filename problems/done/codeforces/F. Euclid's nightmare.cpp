// Problem: F. Euclid's nightmare
// Contest: Codeforces - Good Bye 2020
// URL: https://codeforces.com/problemset/problem/1466/F
// Memory Limit: 256 MB
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
 
const int NMAX = 5e5 + 100;

int par[NMAX];
int get_par(int u){
	if(u >= NMAX) return u;
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

bool update_basis(const vi &bits){
	
	int u = bits.front();
	int v = INF;
	
	if(bits.size()==2){
		v = bits.back();
		if(u > v) swap(u, v);
	}
	
	while(u < NMAX && par[u]!=u){
		
		// cout << "  " << u << ' ' << v << endl << flush;
		
		int _u = u;
		u = v;
		v = get_par(_u);
		
		if(u==v){
			return false;
		}
		
		// cout << "  " << u << ' ' << v << endl << flush;
		
		if(u > v){
			swap(u, v);
		}
	}
	
	// cout << ' ' << u+1 << ' ' << v+1 << endl << flush;
	
	if(u < NMAX && par[u]==u){
		par[u] = v;
		return true;
	}
	
	return false;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, m;
	cin >> n >> m;
	
	vi taken;
	
	for(int i = 0; i < NMAX; i++){
		par[i] = i;
	}
	
	for(int i = 0; i < n; i++){
		
		int k;
		cin >> k;
		
		vi tmp(k);
		for(auto &i : tmp){
			cin >> i;
			i--;
		}
		
		if(tmp.size() > 1){
			assert(tmp.front() != tmp.back());
		}
		
		if(update_basis(tmp)){
			taken.push_back(i);
		}
	}
	
	cout << pow_exp(2, taken.size()) << ' ' << taken.size() << endl;
	for(auto e : taken) cout << e+1 << ' '; cout << endl;
}
