// Problem: E. Devu and Birthday Celebration
// Contest: Codeforces - Codeforces Round #251 (Div. 2)
// URL: https://codeforces.com/problemset/problem/439/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int NMAX = 1e5 + 10;

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}

int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
}

int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}

int fac[NMAX];
int ifac[NMAX];

void init_fac(){
	
	fac[0] = ifac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
		ifac[i] = mul(ifac[i-1], pow_exp(i, MOD-2));
	}	
}

int choose(int n, int c){
	return mul(mul(fac[n], ifac[c]), ifac[n-c]);
}

vector <int> prime;
bool not_prime[NMAX];
int mob[NMAX];

void mobius(int n = NMAX){
	
	mob[1] = 1;
	
	for(int i = 2; i < n; i++){
		
		if(!not_prime[i]){
			prime.push_back(i);
			mob[i] = -1;
		}
		
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			
			not_prime[i * prime[j]] = true;
			
			if (i % prime[j] == 0){
				mob[i * prime[j]] = 0;
				break;	
			}
			else{
				mob[i * prime[j]] = mob[i] * mob[prime[j]];
			}
		}
	}	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	mobius();
	init_fac();
	
    int t; cin >> t; while(t--){

		int n, f;
		cin >> n >> f;
		
		int ans = 0;
		
		for(lli i = 1; i*i <= n; i++) if(n%i==0){
			
			if((n/i -1) >= (f-1)){
				int cans = choose(n/i -1, f-1);
				ans = add(ans, mul(mob[i], cans));
			}
			
			if(n/i != i){
				
				int j = n/i;
				if((n/j -1) >= (f-1)){
					int cans = choose(n/j -1, f-1);
					ans = add(ans, mul(mob[j], cans));
				}
			}
		}
		
		cout << ans << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
