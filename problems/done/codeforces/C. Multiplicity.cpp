// Problem: C. Multiplicity
// Contest: Codeforces - Codeforces Round #523 (Div. 2)
// URL: https://codeforces.com/contest/1061/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
 
int n, id;
int arr[100010];
vi frq[1000010];
vi tmp[100010];
int sm[100010];
int mem[int(2.4e7)];

int go(int i, int j){
	
	if(j == tmp[i].size()){
		return 0;
	}
	
	int &ret = mem[sm[i-1]+j];
	if(ret+1) return ret;
	
	int st_path = go(i, j+1);
	int nd_path = 0;
	
	if(i != n){
		auto it = upper_bound(tmp[i+1].begin(), tmp[i+1].end(), tmp[i][j]);
		if(it != tmp[i+1].end()) nd_path = go(i+1, it-tmp[i+1].begin());
	}
	
	return ret = add(add(1, st_path), nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    	frq[arr[i]].push_back(i);
    }
    
    for(int i = 1; i <= n; i++){
    	
	    for(int j = i; j <= 1e6; j += i){
	    	for(auto k : frq[j]){
	    		tmp[i].push_back(k);
	    	}
	    }
	    
	    sm[i] = sm[i-1] + tmp[i].size();
    }
    
    for(int i = 1; i <= n; i++){
    	sort(tmp[i].begin(), tmp[i].end());
    }
    
    for(int i = 0; i <= 1e6; i++){
    	frq[i].clear();
    }
    
    memset(mem, -1, sizeof mem);
    
    int ans = go(1, 0);
    cout << ans << endl;
}