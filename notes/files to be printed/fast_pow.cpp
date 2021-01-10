
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;


int fast_pow(int n, int p){
	if(!p) return 1;
	if(p&1) return (n*fast_pow(n, p-1))%MOD;
	int tmp = fast_pow(n, p/2);
	return(tmp*tmp)%MOD;
}

int fact[333], ifact[333];

int get_fact(int n){
	if(n < 2) return 1;
	if(fact[n]) return fact[n];
	return fact[n] = (n*get_fact(n-1))%MOD;
}

int choose(int n, int r){
	
	return ( 
				(get_fact(n) * fast_pow( get_fact(r) , MOD-2)) % MOD
			
				* fast_pow(get_fact(n-r), MOD-2) 
			 
			) % MOD;
}

int fchoose(int n, int r){
	return ((fact[n]*ifact[r]%MOD) * ifact[n-r])%MOD;
}

void fillFactArr(){
	
	fact[0] = 1;
	ifact[0] = 1;
	
	for(int i = 1; i < 333; i++){
		fact[i] = (i*fact[i-1])%MOD;
		ifact[i] = fast_pow(fact[i], MOD-2);
	}	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){


    }	
}
