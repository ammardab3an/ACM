// Problem: Just Primes
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/JPM/
// Memory Limit: 1536 MB
// Time Limit: 3000 ms
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

const int NMAX = 5e4 + 10;

vi primes;
int lp[NMAX];
int ans[NMAX];

void init(){
    
    for(int i = 2; i < NMAX; i++){
        
        if(lp[i] == 0){
            lp[i] = i;
            primes.push_back(i);
        }
        
        for(auto p : primes){
            if(lp[i] < p || i*p > NMAX) break; 
            lp[i*p] = p;    
        }
    }   
    
    memset(ans, INF, sizeof ans);
    
    ans[0] = 0;
    for(auto p : primes){
        for(int i = NMAX-1; i >= p; i--){
            ans[i] = min(ans[i], ans[i-p]+1);
        }        
    }
}

int32_t main(){

    fastIO;

    init();
    
    int tt = 1;
    int t; scanf("%d", &t); while(t--){

		int n;
		scanf("%d", &n);
		
        int que = ans[n];
        if(que >= INF) que = -1;
		
		printf("Case %d: %d\n", tt++, que);
    }
}
