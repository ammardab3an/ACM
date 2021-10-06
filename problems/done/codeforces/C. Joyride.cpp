// Problem: C. Joyride
// Contest: Codeforces - 2017-2018 ACM-ICPC German Collegiate Programming Contest (GCPC 2017)
// URL: https://codeforces.com/gym/101873/problem/C
// Memory Limit: 256 MB
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

int x, n, m, t;
vi adj[1010];
pii arr[1010];

int mem[1010][1010];

int go(int u, int rem){
    
    if(rem==0 && u==0) return 0;
    if(rem==0) return INFLL;
    
    int &ret = mem[u][rem];
    if(ret+1) return ret;
    
    int ans = INFLL;
    
    if(arr[u].first <= rem){
        ans = min(ans, arr[u].second + go(u, rem-arr[u].first));
    }
    
    for(auto v : adj[u]){
        
        int ct = arr[v].first;
        int cp = arr[v].second;
        
        if(ct+t > rem) continue;
        
        ans = min(ans, cp + go(v, rem-ct-t));
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> x;
    cin >> n >> m >> t;
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    
    memset(mem, -1, sizeof mem);
    
    if(x < 2*arr[0].first){
        cout << "It is a trap." << endl;
        return 0;
    }
    
    int ans = arr[0].second + go(0, x-arr[0].first);
    
    if(ans < INFLL){
        cout << ans << endl;
    }
    else{
        cout << "It is a trap." << endl;
    }
}
