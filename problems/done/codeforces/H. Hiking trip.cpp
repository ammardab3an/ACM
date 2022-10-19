// Problem: H. Hiking trip
// Contest: Codeforces - 2021 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/103577/problem/H
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

typedef long double dt;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int _d, v1, v2, v3, _t;
    cin >> _d >> v1 >> v2 >> v3 >> _t;
    
    dt x1 = 0;
    dt x2 = 1;
    dt x3 = 0;
    dt d = _d;
    dt t = _t;
    bool dir = 0;
    
    dt tot_t = 0;
    
    while((abs(d-x1) > 1e-6) && (abs(tot_t-t) > 1e-6)){
    	
    	dt nt = 0;
		
    	if(dir==0){
    		
			// x3-> x2-> d
			// x3+v3*t = x2+v2*t
			// t = (x2-x3)/(v3-v2)
			
			nt = (x2-x3)/(v3-v2);
			
			if(tot_t+nt >= t){
				nt = t-tot_t;
			}
			
			if(x2+nt*v2 > d){
				
				// x2+v2*t==d
				// t = (d-x2)/v2
				nt = (d-x2)/v2;
				
				x1 = x1+v1*nt;
				x2 = x2+v2*nt;
				x3 = x3+v3*nt;
				
				tot_t += nt;
							
				// x3+v3*t==d
				// t = (d-x3)/v3
				nt = (d-x3)/v3;
				
				if(tot_t+nt >= t){
					nt = t-tot_t;
				}
			}
			
			x1 = x1+v1*nt;
			x2 = x2+v2*nt;
			x3 = x3+v3*nt;
    	}	
    	else{
    		
    		// x1-> <-x3
    		// x1+v1*t = x3-v3*t
    		// x3-x1 = -t(v3+v1)
    		// t = -(x3-x1)/(v3+v1)
    		
    		nt = (x3-x1)/(v3+v1);
    		
			if(tot_t+nt >= t){
				nt = t-tot_t;
			}
			
			x1 = x1+v1*nt;
			x2 = x2+v2*nt;
			x3 = x3-v3*nt;
			
			x3 = min(x3, d);
    	}
    	
    	tot_t += nt;
    	
    	// cout << x1 << ' ' << x2 << ' ' << x3 << ' ' << tot_t << ' ' << dir << endl;
    	
		dir ^= 1;
    }
    
    cout << fixed << setprecision(10) << x3 << endl;
}