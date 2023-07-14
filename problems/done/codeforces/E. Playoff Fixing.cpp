// Problem: E. Playoff Fixing
// Contest: Codeforces - Educational Codeforces Round 149 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1837/problem/E
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 1e6 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	// assert(n >= c);
	if(n < c) return 0;
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	init();
	
	int m;
	cin >> m;
	
	int n = 1<<m;
	
	vi vec(n);
	for(auto &i : vec){
		cin >> i;
		if(i != -1) i--;
	}
	
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	
	vi pos(n, -1);
	for(int i = 0; i < n; i++){
		if(vec[i] != -1){		
			pos[vec[i]] = i;
		}
	}
	
	vi cur(n/2);
	for(int i = 0; i < n; i++){
		cur[i/2] += vec[i]==-1;
	}
	
	int ans = 1;
	
	for(int k = 0; k < m; k++){
		
		
		vector<bool> vis(cur.size());
		
		int sz = cur.size();
		int rm = cur.size();
		bool bad = false;
		
		for(int i = 0; i < cur.size(); i++){
			int p = pos[sz*2-1 - i];
			if(p != -1){
				if(vis[p>>(k+1)]){
					bad = true;
					break;
				}
				else{
					vis[p>>(k+1)] = true;
					rm--;
				}
			}
		}
		
		if(bad){
			ans = 0;
			break;
		}
		
		vi nxt(sz/2);
		
		for(int i = 0; i < sz/2; i++){
			nxt[i] = cur[i*2]+cur[i*2+1]-2+vis[i*2]+vis[i*2+1];
		}
		
		
		int cans = 1;
		for(int i = 0; i < sz; i++) if(!vis[i]){
			cans = mul(cans, cur[i]);
		}
		
		cans = mul(cans, fac[rm]);
		ans = mul(ans, cans);
		
		cur = nxt;
	}
	
	cout << ans << endl;
}








