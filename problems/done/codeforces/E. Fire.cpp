// Problem: E. Fire
// Contest: Codeforces - Codeforces Round #436 (Div. 2)
// URL: https://codeforces.com/problemset/problem/864/E
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 100 + 5;
const int TMAX = 20 + 5;

int n;
struct e{
	int t, d, p;
} arr[NMAX];

int foo[NMAX];

int mem[NMAX][TMAX * NMAX];
int par[NMAX][TMAX * NMAX];

int go(int pos, int ct){
	
	if(pos == n) return 0;
	
	int &ret = mem[pos][ct];
	if(ret+1) return ret;
	
	int stPath = go(pos+1, ct);
	int ndPath = 0;
	if(arr[foo[pos]].d > ct+arr[foo[pos]].t){
		ndPath = go(pos+1, ct+arr[foo[pos]].t) + arr[foo[pos]].p;
	}
	
	par[pos][ct] = stPath < ndPath;
	return ret = max(stPath, ndPath);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> arr[i].t >> arr[i].d >> arr[i].p;
    }
    
    for(int i = 0; i < n; i++) foo[i] = i;
    
    sort(foo, foo+n, [&](int a, int b){
    	return arr[a].d < arr[b].d;
    	// return (pii){arr[a].d, arr[a].t} < (pii){arr[b].d, arr[b].t};
    });
    
    memset(mem, -1, sizeof mem);
    memset(par, -1, sizeof par);
    
    cout << go(0, 0) << endl;
    
    int cur_pos = 0;
    int cur_ct = 0;
    
    vi tmp;
    
    while(par[cur_pos][cur_ct] != -1){
    	
    	if(par[cur_pos][cur_ct]){
    		tmp.push_back(foo[cur_pos]+1);
    		cur_ct += arr[foo[cur_pos]].t;
    	}
    	cur_pos++;
    }
    
    cout << tmp.size() << endl;
    for(auto i : tmp) cout << i << ' ' ; cout << endl;
}