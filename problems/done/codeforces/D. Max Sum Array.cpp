// Problem: D. Max Sum Array
// Contest: Codeforces - 2021-2022 ICPC, NERC, Southern and Volga Russian Regional Contest (problems intersect with Educational Codeforces Round 117)
// URL: https://codeforces.com/gym/103430/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
const int NMAX = 2e6 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

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

int choose(int n, int c){
	return mul(mul(fac[n], ifac[c]), ifac[n-c]);
}

int calc(int r){
	return mul(mul(r, r+1), ifac[2]);
}

int calc(int l, int r){
	int ret = calc(r);
	ret = add(ret, mul(-1, calc(l-1)));
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
    
    int n;
    cin >> n;
    
    int sm = 0;
    
    vi vec(n);
    for(auto &i : vec) cin >> i, sm += i;
    
    vi cnt(2*(1e6) + 20);
    
    for(auto i : vec){
    	
    	int l = -(i-1);
    	int r = i-1;
    	
    	cnt[1e6 + l]++;
    	cnt[1e6 + r+2]--;
    }
    
    for(int i = 2; i < cnt.size(); i++){
    	cnt[i] += cnt[i-2];
    }
    
    vpii tmp;
    for(auto i = 0; i < cnt.size(); i++){
    	if(cnt[i]){
    		tmp.push_back({i-1e6, cnt[i]});
    	}
    }
    
    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());
    
    int ans = 0;
    int ans_cnt = 1;
    
    int r = sm;
    for(auto [i, c] : tmp){
    	
    	int nr = r-c;
    	ans = add(ans, mul(calc(nr+1, r), i));
    	ans_cnt = mul(ans_cnt, fac[c]);
    	r = nr;
    }
    
    cout << ans << ' ' << ans_cnt << endl;
}
