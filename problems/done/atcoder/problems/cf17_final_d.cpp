// Problem: D - Zabuton
// Contest: AtCoder - CODE FESTIVAL 2017 Final
// URL: https://atcoder.jp/contests/cf17-final/tasks/cf17_final_d
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
 
const int NMAX = 5e3 + 10;

int n;
pii arr[NMAX];
int mem[NMAX][NMAX];

int go(int i, int rm){
	
	if(i==n){
		return rm==0 ? 0 : INFLL;
	}	
	
	int &ret = mem[i][rm];
	if(ret+1) return ret;
	
	int st_path = go(i+1, rm);
	int nd_path = INFLL;
	
	if(rm) if(arr[i].first >= go(i+1, rm-1)){
		nd_path = arr[i].second + go(i+1, rm-1);
	}
	
	return ret = min(st_path, nd_path);
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
    	cin >> arr[i].first >> arr[i].second;
    }
    
    sort(arr, arr+n, [](const pii &a, const pii &b){
    	return a.first+a.second > b.first+b.second;	
    });
    
    memset(mem, -1, sizeof mem);
    
    int ans = 0;
    for(int i = n; i >= 0; i--){
    	if(go(0, i) < INFLL){
    		ans = i;
    		break;
    	}
    }
    
    cout << ans << endl;
}
