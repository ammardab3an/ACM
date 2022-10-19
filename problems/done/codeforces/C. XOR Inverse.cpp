// Problem: C. XOR Inverse
// Contest: Codeforces - Codeforces Round #673 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1416/C
// Memory Limit: 512 MB
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
    
    int ans_xor = 0;
    int ans_inv = 0;
    
    vector<vi> vecs;
    vecs.emplace_back(vec);
    
    for(int i = 30; i >= 0; i--){
    	
    	int st_path = 0;
    	int nd_path = 0;
    	
    	for(auto &v : vecs){
    		
    		vi cnt(2);
    		for(auto e : v){
    			bool b = (e>>i)&1;
    			if(b){
    				nd_path += cnt[0];
    			}
    			else{
    				st_path += cnt[1];
    			}
    			cnt[b]++;
    		}
    	}	
    	
    	if(st_path <= nd_path){
    		ans_inv += st_path;
    	}
    	else{
    		ans_xor ^= 1<<i;
    		ans_inv += nd_path;	
    	}
    	
		vector<vi> nvecs;
		
		for(auto &v : vecs){
			vector<vi> tt(2);
			for(auto e : v){
				tt[(e>>i)&1].push_back(e);	
			}
			for(auto &v : tt){
				if(!v.empty()){					
    				nvecs.emplace_back(v);
				}
			}
		}
		
		swap(vecs, nvecs);
    }
    
    cout << ans_inv << ' ' << ans_xor << endl;
}

/*

0xxx
1xxx
0xxx
1xxx
0xxx

*/