// Problem: I - File Recover Testing
// Contest: Virtual Judge - String Processing Sheet Week 1
// URL: https://vjudge.net/contest/488773#problem/I
// Memory Limit: 1536 MB
// Time Limit: 1975 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

bool is_prime(int x){
	for(int i = 2; i*i <= x; i++) if(x%i==0){
		return false;
	}
	return true;
}

int32_t main(){
    
    fastIO;
    // #undef endl
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int k;
    string str;
    
    int p[] = {rand(1e5, 2e5), rand(1e6, 2e6)};
    int m[] = {rand(30, 50), rand(50, 100)};
    for(int j = 0; j < 2; j++){
    	while(!is_prime(p[j])) p[j]++;
    	while(!is_prime(m[j])) m[j]++;
    }
    
	const int N = 1e6;
	vector<vi> pow_m(N, vi(2));
	pow_m[0][0] = pow_m[0][1] = 1;
	for(int i = 1; i < N; i++)
	for(int j = 0; j < 2; j++){
		pow_m[i][j] = (pow_m[i-1][j] *1ll* m[j])%p[j];
	}
	
    while(cin >> k >> str, k != -1){
    	
    	int n = str.size();
    	
    	if(k < n){
    		cout << 0 << endl;
    		continue;
    	}
    	
    	vector<vi> pre(n, vi(2));
    	
    	vi cval = {0, 0};
    	
    	for(int i = 0; i < n; i++){
    		
	    	for(int j = 0; j < 2; j++){
	    		cval[j] = ((cval[j] *1ll* m[j])%p[j] + (str[i]-'a'+1))%p[j];
	    	}
	    	
	    	pre[i] = cval;
    	}
    	
    	auto calc = [&](int l, int r){
    		vi ret = pre[r];
    		if(l) for(int j = 0; j < 2; j++){
    			ret[j] = (ret[j] - (pre[l-1][j] *1ll* pow_m[r-l+1][j])%p[j] + p[j])%p[j];
    		}
    		return ret;
    	};
    	
    	int mx = 0;
    	for(int l = 1; l < n; l++){
    		
    		vi tmp_0 = calc(0, l-1);
    		vi tmp_1 = calc((n-1)-(l-1), (n-1)-(0));
    		
    		if(tmp_0[0]==tmp_1[0] && tmp_0[1]==tmp_1[1]){
    			mx = l;
    		}
    	}
    	
    	// cout << mx << endl;
    	
    	k -= n;
    	int ans = 1;
    	ans += k / (n-mx);
    	
    	cout << ans << endl;
    }
}
