// Problem: D. Meta-set
// Contest: Codeforces - Codeforces Round #824 (Div. 2)
// URL: https://codeforces.com/contest/1735/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
    
    int n, m;
    cin >> n >> m;
    
    vector<vi> vec(n, vi(m));
    for(auto &v : vec)
    for(auto &i : v) cin >> i;
    
    map<vi, int> frq;
    for(auto v : vec) frq[v]++;
    
    map<vi, int> cnt;
    
    vector<vi> cnv(3, vi(3));
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) if(i != j)
    for(int k = 0; k < 3; k++) if(i != k) if(j != k){
    	cnv[i][j] = k;
    }
    for(int i = 0; i < 3; i++){
    	cnv[i][i] = i;
    }
    
    for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++){
    	
    	vi cur(m);
    	
    	for(int k = 0; k < m; k++){
			cur[k] = cnv[vec[i][k]][vec[j][k]];
    	}
    	
    	if(cur != vec[i]){
	    	cnt[cur]++;		
    	}
    }
    
    auto choose = [](int n, int c) -> int{
    	
    	if(c > n) return 0;
    	
    	int ret = 1;
    	for(int i = 1; i <= c; i++){
    		ret *= n;
    		ret /= i;
    		n--;
    	}	
    	
    	return ret;
    };
    
    int ans = 0;
    for(auto &[v, c] : cnt){
    	
    	auto it = frq.find(v);
    	if(it==frq.end()) continue;
    	
    	int f = it->second;
    	
    	int st_path = choose(f, 5);
    	int nd_path = choose(f, 3) * c;
    	int rd_path = choose(c, 2) * f;
    	
    	// for(auto i : v) cout << i << ' '; cout << endl;
    	// cout << st_path << ' ' << nd_path << ' ' << rd_path << endl;
    	
    	int cans = st_path + nd_path + rd_path;
    	ans += cans;
    }
    
    cout << ans << endl;
}
