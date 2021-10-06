// Problem: F - Make Pair
// Contest: AtCoder - AtCoder Beginner Contest 217
// URL: https://atcoder.jp/contests/abc217/tasks/abc217_f
// Memory Limit: 1024 MB
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
const int MOD = 998244353; // 1e9 + 7;
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

int n, m;
vi adj[444];
int mem[444][444];
int cho[444][444];

int choose(int n, int c){
    
    if(c==0) return 1;    
    if(n==0) return 0;
    
    int &ret = cho[n][c];
    if(ret+1) return ret;
    
    return ret = add(choose(n-1, c-1), choose(n-1, c));
}

int go(int l, int r){ 
    
    if(l==r) return 0;
    if(l==r+1) return 1;
    
    int &ret = mem[l][r];
    if(ret+1) return ret;
    
    int ans = 0;
    
    for(auto v : adj[l]){
        if(l <= v && v <= r){
            int st_path = go(l+1, v-1);
            int nd_path = go(v+1, r);
            int cans = mul(st_path, nd_path);
            int cho = choose((r-l+1)/2, (v-l+1)/2);
            ans = add(ans, mul(cans, cho));
        }
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
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    memset(mem, -1, sizeof mem);
    memset(cho, -1, sizeof cho);
    
    int ans = go(0, 2*n-1);
    
    cout << ans << endl;
}
