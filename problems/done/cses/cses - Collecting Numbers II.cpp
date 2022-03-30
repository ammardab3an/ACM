// Problem: Collecting Numbers II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2217
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vi vec(n);
    for(auto &i : vec) cin >> i, --i;
    
    vi pos(n);
    for(int i = 0; i < n; i++){
    	pos[vec[i]] = i;
    }
    
    int ans = 1;
    for(int i = 1; i < n; i++){
    	ans += pos[i] < pos[i-1];
    }
    
    while(m--){
    	
    	int i, j;
    	cin >> i >> j;
    	i--, j--;
    	
    	i = vec[i];
    	j = vec[j];
    	
    	if(i > j) swap(i, j);
    	
    	if(i) ans -= pos[i] < pos[i-1];
    	if(i+1 < n) ans -= pos[i+1] < pos[i];
    	
    	if(j) ans -= pos[j] < pos[j-1];
    	if(j+1 < n) ans -= pos[j+1] < pos[j];
    	
    	if(i+1 == j) ans += pos[j] < pos[i];	
    	
    	swap(pos[i], pos[j]);
    	swap(vec[pos[i]], vec[pos[j]]);
    	
    	if(i) ans += pos[i] < pos[i-1];
    	if(i+1 < n) ans += pos[i+1] < pos[i];
    	
    	if(j) ans += pos[j] < pos[j-1];
    	if(j+1 < n) ans += pos[j+1] < pos[j];
    	
    	if(i+1 == j) ans -= pos[j] < pos[i];
    	
    	cout << ans << endl;
    }
}
