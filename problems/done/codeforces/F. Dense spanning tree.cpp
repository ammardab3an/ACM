// Problem: F. Dense spanning tree
// Contest: Codeforces - ITMO Academy: pilot course - Disjoint Sets Union - Step 2
// URL: https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/F
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

int par[NMAX];

int get_par(int u){
    return par[u] = par[u]==u ? u : get_par(par[u]);
}

bool merge(int u, int v){
    
    if((u=get_par(u))==(v=get_par(v))){
        return false;
    }    
    
    rand()&1 ? par[u] = v : par[v] = u;
    
    return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vector<iii> vec(m);
    for(auto &p : vec){
        cin >> p.second.first >> p.second.second >> p.first;
    }
    
    sort(vec.begin(), vec.end());
    
    int ans = INFLL;
    
    for(int i = 0; i < m; i++){
        
        iota(par, par+n, 0);
        
        int l = -1, r = -1;
        for(int j = i; j < m; j++){
            
            auto &p = vec[j];
            int w = p.first;
            int u = p.second.first;
            int v = p.second.second;
            u--, v--;
            
            if(merge(u, v)){
                if(l==-1){
                    l = w;
                }
                r = w;
            }
        }
        
        bool good = true;
        for(int i = 0; i < n; i++){
            if(merge(0, i)){
                good = false;
                break;
            }
        }
        
        if(good){
            ans = min(ans, r-l);
        }
    }
    
    if(ans==INFLL){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << ans << endl;
    }
}
