// Problem: D. Minimum maximum on the Path
// Contest: Codeforces - ITMO Academy: pilot course - Binary Search - Step 3
// URL: https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/D
// Memory Limit: 512 MB
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

int n, m, d;
vpii adj[NMAX];
vi adj_mx[NMAX];

int mx;
int mem[NMAX];

int go(int u){
    
    if(u==n-1){
        return 0;
    }    
    
    int &ret = mem[u];
    if(ret+1) return ret;
    
    int ans = INF;
    
    for(auto p : adj[u]){
        if(p.first > mx) break;
        ans = min(ans, 1+go(p.second));
    }
    
    return ret = ans;
}

void calc(int u){
    
    cout << u+1 << ' ';
    
    if(u == n-1){
        cout << endl;
        return;    
    }    
    
    int ans = go(u);
    
    for(auto p : adj[u]){
        if(ans == (1+go(p.second))){
            calc(p.second);
            break;
        }
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m >> d;
    
    for(int i = 0; i < m; i++){
        
        int u, v, a;
        cin >> u >> v >> a;
        u--, v--;
        
        adj[u].push_back({a, v});
    }
    
    for(int i = 0; i < n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    
    int l = 0;
    int r = 1e9;
    
    int ans = INF;
    
    while(l <= r){
        
        int mid = (l+r)/2;
        
        mx = mid;
        memset(mem, -1, sizeof mem);
        
        if(go(0) <= d){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    
    if(ans==INF){
        cout << -1 << endl;
    }
    else{
        mx = ans;
        memset(mem, -1, sizeof mem);
        cout << go(0) << endl;
        calc(0);
    }
}
