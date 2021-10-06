
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"
#include "testlib.h"

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

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//  
// int rand(int x, int y) {
	// return uniform_int_distribution<int>(x, y)(rng);
// }

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

ll rn(ll l,ll r){
    return rnd.next(l,r);
}

int32_t main(int32_t argc, char* argv[]){
    
    registerValidation(argc, argv);
    
    int const max_test_cases = 100000;
    int const max_n = 100000;
    int const min_ai = 0;
    int const max_ai = 1000000000;
    int const max_sum_of_n = 100000;
    
    int t = inf.readInt(1, max_test_cases, "T");
    inf.readEoln();
    
    int cnt = 0;
    
    for(int i = 0; i < t; i++){
        
        int n = inf.readInt(1, max_n, "N");
        inf.readEoln();
        
        cnt += n;
        
        for(int j = 0; j < n; j++){
            int ai = inf.readInt(min_ai, max_ai, "Ai");
            if(j!=n-1) inf.readSpace();
        }
        
        inf.readEoln();
        
        ensuref(cnt <= max_sum_of_n, ("The total number of elements exceeded " + to_string(max_sum_of_n)).c_str());
    }
    
    inf.readEof();
}