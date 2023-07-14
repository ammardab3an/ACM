// Problem: D. Counting Factorizations
// Contest: Codeforces - Codeforces Round 856 (Div. 2)
// URL: https://codeforces.com/contest/1794/problem/D
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
 
const int NMAX = 4044 + 10;

bool is_prime(int x){
	
	if(x <= 1){
		return false;
	}
	
	for(int i = 2; i*i <= x; i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

int n, m;
int arr[NMAX];
pii val[NMAX];
bool good[NMAX];
int mem[NMAX][NMAX];
int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}	
	
	ifac[NMAX-1] = pow_exp(fac[NMAX-1], MOD-2);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int go(int i, int cnt){
	
	if(i==m){
		return cnt==n/2;
	}
	
	int &ret = mem[i][cnt];
	if(ret+1) return ret;	
	
	int ans = 0;
	auto [v, f] = val[i];
	
	if(good[i]){
		int st_path = mul(ifac[f], go(i+1, cnt));
		int nd_path = mul(ifac[f-1], go(i+1, cnt+1));
		ans = add(st_path, nd_path);
	}
	else{
		ans = mul(ifac[f], go(i+1, cnt));
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
 	
 	init();
 	
 	cin >> n;
 	n *= 2;
 	
 	for(int i = 0; i < n; i++){
 		cin >> arr[i];
 	}   	
 	
 	sort(arr, arr+n);
 	
 	int cnt = 1;
 	int lst = arr[0];
 	
 	for(int i = 1; i < n; i++){
 		
 		if(arr[i]==arr[i-1]){
 			cnt++;
 		}	
 		else{
 			val[m++] = {lst, cnt};
 			lst = arr[i];
 			cnt = 1;
 		}	
 	}
 	
 	if(cnt){	
	 	val[m++] = {lst, cnt};
 	}
 	
 	for(int i = 0; i < m; i++){
 		good[i] = is_prime(val[i].first);
 		// cout << val[i].first << ' ' << val[i].second << ' ' << good[i] << endl;
 	}
 	
 	memset(mem, -1, sizeof mem);
 	
 	int ans = mul(fac[n/2], go(0, 0));
 	cout << ans << endl;
}
