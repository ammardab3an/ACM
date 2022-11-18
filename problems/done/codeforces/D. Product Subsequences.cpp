// Problem: D. Product Subsequences
// Contest: Codeforces - SpecialForces
// URL: https://codeforces.com/gym/409982/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int n;
int arr[1010];
array<int, 3> mem[1010][3];
int vis[1010][3], vid;

array<int, 3> go(int i, int res){
	
	if(i==n){
		return (array<int, 3>){res>0, res<0, res==0};
	}	
	
	auto &ret = mem[i][res+1];
	if(vis[i][res+1]==vid) return ret;
	vis[i][res+1] = vid;
	
	auto st_path = go(i+1, res);
	auto nd_path = go(i+1, res*arr[i]);
	
	array<int, 3> ans;
	for(int j = 0; j < 3; j++){
		ans[j] = add(st_path[j], nd_path[j]);
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
    
    int t; cin >> t; while(t--){
	
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			if(arr[i] > 0) arr[i] = 1;
			if(arr[i] < 0) arr[i] = -1;
		}
		
		vid++;
		
		array<int, 3> ans = go(0, 1);
		ans[0] = add(-1, ans[0]);
		
		for(auto i : ans) cout << i << ' '; cout << endl;
    }	
}
