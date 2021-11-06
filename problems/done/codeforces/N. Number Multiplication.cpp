// Problem: N. Number Multiplication
// Contest: Codeforces - 2020-2021 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/102861/problem/N
// Memory Limit: 1024 MB
// Time Limit: 1400 ms
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

const int PMAX = 31622786;

vi primes;
int lp[PMAX];

int n, m, k;
int arr[1010];
vpii adj[1010];

void init(){
    
    for(int i = 2; i < PMAX; i++){
        
        if(lp[i] == 0){
            lp[i] = i;
            primes.push_back(i);
        }
        
        for(auto p : primes){
            if(p > lp[i] || p*i >= PMAX) break;
            lp[p*i] = i;
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
    
    init();
    
    cin >> m >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < k; i++){
        
        int u, v, cnt;
        cin >> u >> v >> cnt;
        u--, v--;
        
        adj[v].push_back({u, cnt});
    }
    
    vi ans(m);
    
    for(int i = 0; i < n; i++){
        
        vpii fac;
        int ai = arr[i];
        
        sort(adj[i].begin(), adj[i].end());
        
        vi new_adj;
        
        for(auto [v, c] : adj[i]){
            
            if(ans[v]){
                int t = ans[v];
                while(c--) ai /= t;
            }
            else{
                new_adj.push_back(v);
            }
        }
        
        for(auto p : primes){
            
            if(p*p > ai) break;
            
            int cnt = 0;
            while(ai%p==0) ai/=p, cnt++;
            
            if(cnt){
                fac.push_back({p, cnt});
            }
        }
        
        if(ai > 1) fac.push_back({ai, 1});
        
        for(int j = 0; j < fac.size(); j++){
            ans[new_adj[j]] = fac[j].first;
        }
    }
    
    for(auto i : ans) cout << i << ' ';
}
