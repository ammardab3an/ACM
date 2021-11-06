// Problem: D. Bosses
// Contest: Codeforces - ITMO Academy: pilot course - Disjoint Sets Union - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/D
// Memory Limit: 64 MB
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

int par[NMAX];
int cnt[NMAX];

pii get_par(int u){
    
    if(par[u]==u){
        return {u, 0};
    }
    
    pii t = get_par(par[u]);
    
    par[u] = t.first;
    cnt[u] += t.second;
    
    return {par[u], cnt[u]};
}

void merge(int u, int p){
    cnt[u]++;
    par[u] = p;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    iota(par, par+n, 0);
    
    while(k--){
        
        int ty;
        cin >> ty;
        
        if(ty==1){
            
            int u, v;
            cin >> u >> v;
            u--, v--;
            
            merge(u, v);
        }
        else{
            
            int u;
            cin >> u;
            u--;
            
            cout << get_par(u).second << endl;
        }
        
        // for(int i = 0; i < 5; i++) cout << par[i] << ' '; cout << endl;
        // for(int i = 0; i < 5; i++) cout << cnt[i] << ' '; cout << endl;
    }
}
