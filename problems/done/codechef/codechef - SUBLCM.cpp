// Problem: Subarray LCM
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/SUBLCM
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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

const int MAXN = 1e6+10;

int spf[MAXN];
vi factors[MAXN];
bool vis[MAXN];

void init(){
    
    for (int i=1; i<MAXN; i++){
        spf[i] = i;
    }
    
    for (int i=4; i<MAXN; i+=2){
        spf[i] = 2;
    }
    
    for (int i=3; i*i<MAXN; i+=2) if (spf[i] == i){
        for (int j=i*i; j<MAXN; j+=i){
            if (spf[j]==j){
                spf[j] = i;
            }
        }
    }
    
    for(int i = 1; i < MAXN; i++){
    	
    	int t = i;
    	while(t != 1){
    		factors[i].push_back(spf[t]);
    		t /= spf[t];	
    	}
    	
    	factors[i].resize(unique(factors[i].begin(), factors[i].end()) - factors[i].begin());
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
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		int r = 0;
		int ans = -1;
		
		auto add = [&](int v){
			for(auto i : factors[v]){
				vis[i] = true;
			}
		};
		
		auto del = [&](int v){
			for(auto i : factors[v]){
				vis[i] = false;
			}
		};
		
		auto check = [&](int v){
			for(auto i : factors[v]){
				if(vis[i]){
					return false;
				}
			}
			return true;
		};
		
		for(int l = 0; l < n; l++){
			
			if(l){
				del(vec[l-1]);
			}	
			
			while(r < n && check(vec[r])){
				add(vec[r++]);
			}
			
			if(r != l+1){
				ans = max(ans, r-l);
			}
		}
		
		del(vec[n-1]);
		
		cout << ans << endl;
    }	
}
