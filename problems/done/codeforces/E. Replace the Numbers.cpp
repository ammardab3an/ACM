// Problem: E. Replace the Numbers
// Contest: Codeforces - Educational Codeforces Round 119 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1620/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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
 
const int NMAX = 1e6 + 10;

int sz;
int par[NMAX];
int col[NMAX];
int tmp[NMAX];

int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}

void merge(int u, int v){
	
	assert(col[u]==col[v]);
	
	u = get_par(u);
	v = get_par(v);
	
	if(u==v) return;
	
	assert(col[u]==col[v]);
	
	if(rand()&1) swap(u, v);
	par[u] = v;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int q;
    
    while(cin >> q){
    	
    	sz = 0;
	    memset(tmp, -1, sizeof tmp);
	    
	    while(q--){
	    	
	    	int k;
	    	cin >> k;
	    	
	    	if(k==1){
	    		
	    		int val;
	    		cin >> val;
	    		val--;
	    		
	    		par[sz] = sz;
	    		col[sz] = val;
	    		
	    		if(tmp[val]==-1){
	    			tmp[val] = sz;
	    		}
	    		else{
	    			merge(tmp[val], sz);
	    		}
	    		
	    		sz++;
	    	}
	    	else{
	    		
	    		int _old, _new;
	    		cin >> _old >> _new;
	    		_old--, _new--;
	    			
	    		if(_old==_new) continue;
	    		if(tmp[_old] == -1) continue;
	    		
	    		int par_old = get_par(tmp[_old]);
	    		col[par_old] = _new;
	    		
	    		if(tmp[_new]==-1){
	    			tmp[_new] = par_old;
	    		}
	    		else{
	    			merge(tmp[_new], par_old);
	    		}
	    		
	    		tmp[_old] = -1;
	    	}
	    }
	    
	    for(int i = 0; i < sz; i++){
	    	cout << col[get_par(i)]+1 << ' ';
	    }
	    cout << endl;
    }
}