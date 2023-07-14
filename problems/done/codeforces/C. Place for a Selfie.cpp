// Problem: C. Place for a Selfie
// Contest: Codeforces - Codeforces Round 862 (Div. 2)
// URL: https://codeforces.com/contest/1805/problem/C
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){
	
		int n, m;
		cin >> n >> m;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		sort(vec.begin(), vec.end());
		
		while(m--){
			
			int ia, ib, ic;
			cin >> ia >> ib >> ic;
			
			double a(ia), b(ib), c(ic);
			
			/*
			f = ax2 + bx + c
			ax2 + bx + c = kx
			ax2 + (b-k)x + c = 0
			delta = (b-k)2 - 4ac
			delta < 0
			(b-k)2-4ac < 0
			b2+k2-2bk-4ac < 0
			k2 - 2bk + b2-4ac < 0
			a = 1, b = -2b, c = b2-4ac
			
			k2+bk+c < 0
			
			k2+bk+c = 0
			delta = b2-4ac = 4b2 - 4(b2-4ac)
			 = 4b2 + 4(4ac-b2)
			 = 4b2 + 16ac - 4b2
			 = 16ac
			sqrt(delta) = 4sqrt(ac)
			
			k0 = (-b+sqrt(delta)) / 2
			 = b+sqrt(delta)/2
			k1 = b-sqrt(delta)/2
			
			if(k0 > k1) swap
			
			k0 < k < k1
			*/
			
			double sdk = 4*sqrt(double(a*c));
			double k0 = b-sdk/2;
			double k1 = b+sdk/2;
			
			if(k0 > k1) swap(k0, k1);
			
			int p_l = upper_bound(vec.begin(), vec.end(), floor(k0))-vec.begin();
			int p_r = lower_bound(vec.begin(), vec.end(), ceil(k1))-vec.begin();
			
			if(p_l < p_r){
				cout << "YES" << endl;
				cout << vec[p_l] << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
		
		cout << endl;
    }	
}
