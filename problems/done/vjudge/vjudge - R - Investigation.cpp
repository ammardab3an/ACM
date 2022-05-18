// Problem: R - Investigation
// Contest: Virtual Judge - Dynamic Programming Sheet 2 Week 4
// URL: https://vjudge.net/contest/490713#problem/R
// Memory Limit: 64 MB
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

int n, k;
string num;
int mem[33][100][100][2];

int go(int i, int val, int sm, bool b){
	
	if(i == n){
		return val+sm==0;
	}	
	
	int &ret = mem[i][val][sm][b];
	if(ret+1) return ret;
	
	int ans = 0;
	
	int mx = b ? 9 : num[i]-'0';
	for(int j = 0; j <= mx; j++){
		int cans = go(i+1, (val*10+j)%k, (sm+j)%k, b || (j < num[i]-'0'));
		ans += cans;
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
    
    int tt = 1;
    int t; cin >> t; while(t--){

		cout << "Case " << tt++ << ": ";
		
		int l, r, k;
		cin >> l >> r >> k;
		
		if(k > 100){
			cout << 0 << endl;
			continue;
		}
		
		::k = k;
		
		num = to_string(r);
		n = num.size();
		memset(mem, -1, sizeof mem);
		int ans = go(0, 0, 0, 0);
		
		if(l){
			num = to_string(l-1);
			n = num.size();
			memset(mem, -1, sizeof mem);
			ans -= go(0, 0, 0, 0);
		}
		
		cout << ans << endl;
    }	
}
