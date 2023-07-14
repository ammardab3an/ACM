// Problem: D. Makoto and a Blackboard
// Contest: Codeforces - Hello 2019
// URL: https://codeforces.com/problemset/problem/1097/D
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int inv[55];
int ppp[55];
int mem[10010][55];
int vis[10010][55], vid;

int go(int i, int rm){
	
	if(!i){
		return ppp[rm];
	}	
	
	int &ret = mem[i][rm];
	int &vis = ::vis[i][rm];
	if(vis==vid) return ret;
	vis=vid;
	
	int ans = 0;
	
	int q = inv[rm+1];
	for(int j = 0; j <= rm; j++){
		ans = add(ans, mul(q, go(i-1, j)));
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
    
    int n, k;
    cin >> n >> k;
    
    for(int i = 1; i < 55; i++){
    	inv[i] = pow_exp(i, MOD-2);
    }
    
    vpii tmp;
    for(int i = 2; i*i <= n; i++){
    	
    	int cnt = 0;
    	while(n%i==0){
    		n /= i;
    		cnt++;
    	}	
    	
    	if(cnt){
    		tmp.push_back({i, cnt});
    	}
    }
    
    if(n > 1){
    	tmp.push_back({n, 1});
    }
    
    int ans = 1;
    
    for(auto [v, f] : tmp){
    	
    	ppp[0] = 1;
    	for(int i = 1; i <= f+1; i++){
    		ppp[i] = mul(ppp[i-1], v);
    	}
    	
    	vid++;
    	
    	int cans = go(k, f);
    	ans = mul(ans, cans);
    }
    
    cout << ans << endl;
}
