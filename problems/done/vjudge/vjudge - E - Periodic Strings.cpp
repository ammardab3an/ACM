// Problem: E - Periodic Strings
// Contest: Virtual Judge - String Processing Sheet Week 1
// URL: https://vjudge.net/contest/488773#problem/E
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

bool is_prime(int x){
	for(int i = 2; i*i <= x; i++) if(x%i==0){
		return false;
	}
	return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int p[] = {rand(1e5, 2e5), rand(1e6, 2e6)};
    int m[] = {rand(130, 150), rand(150, 200)};
    
    while(!is_prime(p[0])) p[0]++;
    while(!is_prime(p[1])) p[1]++;
    while(!is_prime(m[0])) m[0]++;
    while(!is_prime(m[1])) m[1]++;
    
    int b = 0;
    int t; cin >> t; while(t--){
		
		if(b++) cout << endl;
		
		string str;
		cin >> str;
		
		int n = str.size();
		
		vector<vi> pre(n, vi(2));
		vector<vi> pow_m(2, vi(n));
		
		vi cval = {0, 0};
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < 2; j++){
			cval[j] = ((cval[j]*m[j])%p[j] + int(str[i]))%p[j];
			pre[i] = cval;
		}
		
		pow_m[0][0] = pow_m[1][0] = 1;
		
		for(int j = 0; j < 2; j++)
		for(int i = 1; i < n; i++){
			pow_m[j][i] = (pow_m[j][i-1]*m[j])%p[j];
		}
		
		auto calc = [&](int l, int r){
			vi ret = pre[r];
			if(l) for(int j = 0; j < 2; j++){
				ret[j] = (ret[j] - (pre[l-1][j] * pow_m[j][r-l+1])%p[j] + p[j])%p[j];
			}
			return ret;
		};
		
		int ans = n;
		
		for(int l = 1; l <= n; l++) if(n%l==0){
			
			vi val = calc(0, l-1);
			
			bool good = true;
			
			for(int i = l; i < n; i += l){
				vi cval = calc(i, i+l-1);
				if(val[0] != cval[0] || val[1] != cval[1]){
					good = false;
					break;
				}	
			}
			
			if(good){
				ans = l;
				break;
			}
		}
		
		cout << ans << endl;
    }	
}
