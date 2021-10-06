// Problem: F. Coprime Subsequences
// Contest: Codeforces - Educational Codeforces Round 20
// URL: https://codeforces.com/contest/803/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const int NMAX = 1e5 + 10;

vector <int> prime;
bool not_prime[NMAX];
int mob[NMAX];
int cnt[NMAX];

void mobius(int n = NMAX){
	
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
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		
		int ai;
		cin >> ai;
		
		for(lli i = 1; i*i <= ai; i++) if(ai%i==0){
			cnt[i]++;
			if(i != (ai/i)) cnt[ai/i]++;
		}
	}
	
	int ans = 0;
	
	for(int i = 2; i <= 1e5; i++){
		int f = add(pow_exp(2, cnt[i]), -1);
		ans = add(ans, mul(mob[i], f));	
	}
	
	ans = add(add(pow_exp(2, n), -1), ans);
	
	cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
