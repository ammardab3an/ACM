// Problem: Strange Functions
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/STR_FUNC
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    const int N = 20;
    
    vector<vi> F(N+1, vi(1<<N));
    vector<vi> G(N+1, vi(1<<N));
    
    vi res_F(n), res_G(n);
    
    for(int mask = 0; mask < n; mask++){
    	
    	G[0][mask] = 0;
		for(int i = 0; i < N; i++){
			if(mask & (1<<i)){
				G[i+1][mask] = add(G[i][mask], G[i][mask^(1<<i)]);
			}
			else{
				G[i+1][mask] = G[i][mask];
			}
		}
		
    	F[0][mask] = G[N][mask];
    	for(int i = 0; i < N; i++){
			if(mask & (1<<i)){
				F[i+1][mask] = add(F[i][mask], F[i][mask^(1<<i)]);
			}
			else{
				F[i+1][mask] = F[i][mask];
			}
		}
		F[N][mask] = add(pow_exp(vec[mask], 2), pow_exp(F[N][mask], 2));
    	
		G[0][mask] = pow_exp(F[N][mask], 2);
		for(int i = 0; i < N; i++){
			if(mask & (1<<i)){
				G[i+1][mask] = add(G[i][mask], G[i][mask^(1<<i)]);
			}
			else{
				G[i+1][mask] = G[i][mask];
			}
		}
		
		res_F[mask] = F[N][mask];
		res_G[mask] = G[N][mask];
	}
	
	int ans = 0;
	for(int i = 1; i < n; i++){
		int cans = mul(i, mul(res_F[i], res_G[i]));
		ans = add(ans, cans);
	}
	
	cout << ans << endl;
}
