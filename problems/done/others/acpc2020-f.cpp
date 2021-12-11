
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 100 + 10;
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
    	
    	int n;
    	cin >> n;
    	
    	vector<double> vec(n);
    	for(auto &d : vec) cin >> d;
    	
    	vector<vector<double>> tmp(n, vector<double>(2));
    	
    	// tmp[i] : propability of having i alternations	
    	// tmp[i][1] : ends with one
    	// tmp[i][0] : ends with zero
    	
    	tmp[0][0] = 1;
    	tmp[0][1] = 1;
    	
    	for(int i = 0; i < n; i++){
    		
    		for(int j = i; j > 0; j--){
    			tmp[j][1] += tmp[j-1][0];
    			tmp[j][0] += tmp[j-1][1];
    		}
    		
    		for(int j = i; j >= 0; j--){
    			tmp[j][1] *= vec[i];
    			tmp[j][0] *= (1.0-vec[i]);
    		}
    	}
    	
    	double ans_0 = 0;
    	double ans_1 = 0;
    	
    	for(int i = 1; i < n; i++){
    		ans_0 += (tmp[i][0]+tmp[i][1]) * i;
    		ans_1 += (tmp[i][0]+tmp[i][1]) * i*i;
    	}
    	
    	double ans = ans_1 - ans_0*ans_0;
    	cout << fixed << setprecision(6) << ans << endl;
    }	
}
