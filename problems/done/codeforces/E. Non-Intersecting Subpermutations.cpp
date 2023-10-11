// Problem: E. Non-Intersecting Subpermutations
// Contest: Codeforces - Educational Codeforces Round 154 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1861/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
const int MOD = 998244353; // 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * (a) * (b)) % MOD;
	if(ret < 0) ret += MOD;
	return ret;
}
 
int add(int a, int b){
	int ret = (1ll * (a) + (b)) % MOD;
	if(ret < 0) ret += MOD;
	return ret;
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, k;
pii mem[4040][4040];

pii merge(const pii &a, const pii &b){	
	pii ret = a;
	ret.first = add(ret.first, mul(-1, b.first));
	ret.second = add(ret.second, mul(-1, b.second));
	return ret;
}

pii go(int i, int cnt){
	
	if(i==n){
		pii cans = {cnt==k, 1};
		if(cnt){
			pii tmp = go(i, cnt-1);
			cans.first = add(cans.first, tmp.first);
			cans.second = add(cans.second, tmp.second);
		}
		return cans;
	}
	
	pii &ret = mem[i][cnt];
	if(ret.first+1) return ret;
	
	pii cans = {0, 0};
		
	if(cnt){
		pii nxt = merge(go(i+1, cnt), go(i+1, 0));
		cans.first = add(cans.first, nxt.first);
		cans.second = add(cans.second, nxt.second);
	}
	
	if(cnt+1==k){
		pii nxt = go(i+1, 0);
		cans.first = add(cans.first, nxt.first);
		cans.second = add(cans.second, nxt.second);
		cans.first = add(cans.first, nxt.second);
	}
	else{
		pii nxt = merge(go(i+1, cnt+1), go(i+1, cnt));
		nxt.first = mul(nxt.first, k-cnt);
		nxt.second = mul(nxt.second, k-cnt);
		cans.first = add(cans.first, nxt.first);
		cans.second = add(cans.second, nxt.second);	
	}
	
	if(cnt){
		pii tmp = go(i, cnt-1);
		cans.first = add(cans.first, tmp.first);
		cans.second = add(cans.second, tmp.second);
	}
	
	return ret = cans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();

    cin >> n >> k;
    
    memset(mem, -1, sizeof mem);
    
    pii ans = go(0, 0);
    cout << ans.first << endl;
}
