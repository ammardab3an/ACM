// Problem: K. Khoshaf
// Contest: Codeforces - 2018 Arab Collegiate Programming Contest (ACPC 2018)
// URL: https://codeforces.com/gym/101991/problem/K
// Memory Limit: 1024 MB
// Time Limit: 12000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, k, l, r;
int cnt[3];

int mem[155][155][155][3];
int vis[155][155][155][3], vid;

int go(int c0, int c1, int c2, int lst){
	
	int &ret = ::mem[c0][c1][c2][lst];
	int &vis = ::vis[c0][c1][c2][lst];
	if(vis==vid) return ret;
	vis = vid;
	
	if(c0+c1+c2==n+1){
		int tot = ((c0*(c0-1))/2) + ((c1*(c1-1))/2) + ((c2*(c2-1))/2);
		return ret = tot==k;
	}
	
	int ans = 0;
	if(c0 < 150){
		int cur = (0+3-lst)%3;
		int cans = mul(cnt[cur], go(c0+1, c1, c2, 0));
		ans = add(ans, cans);
	}
	if(c1 < 150){
		int cur = (1+3-lst)%3;
		int cans = mul(cnt[cur], go(c0, c1+1, c2, 1));
		ans = add(ans, cans);
	}
	if(c2 < 150){
		int cur = (2+3-lst)%3;
		int cans = mul(cnt[cur], go(c0, c1, c2+1, 2));
		ans = add(ans, cans);
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("khoshaf.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n >> k >> l >> r;
		
		int m = n/3;
		if((m*(m-1))/2 > k){
			cout << 0 << endl;
			continue;
		}
		
		cnt[0] = r/3-(l-1)/3;
		cnt[1] = cnt[2] = cnt[0];
		
		if(cnt[0]){
			int mx = 3 * (r/3);
			int mn = 3 * ((l+2)/3);
			if(mx+1 > r) cnt[1]--;
			if(mx+2 > r) cnt[2]--;
			if(mn-2 >= l) cnt[1]++;
			if(mn-1 >= l) cnt[2]++;
		}
		else{
			for(int i = l; i <= r; i++){
				cnt[i%3]++;
			}
		}
		
		assert((r-l+1) == (cnt[0]+cnt[1]+cnt[2]));
		
		vid++;
		int ans = go(1, 0, 0, 0);
		cout << ans << endl << flush;
    }	
}
