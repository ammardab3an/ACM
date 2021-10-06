// Problem: G. FacePalm Accounting
// Contest: Codeforces - 2014-2015 ACM-ICPC, NEERC, Southern Subregional Contest
// URL: https://codeforces.com/gym/100513/problem/G
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
    
    int n, k;
    cin >> n >> k;
    
    int mn = 0;
    int sm = 1; // hay
    int dif = 0;
    
    vi vec(n);
    for(auto &i : vec) cin >> i, mn = min(mn, i);
    
    for(int i = 0; i < k; i++) sm += vec[i];
    
    if(sm > 0){
        for(int i = k-1; i >= 0; i--){
            int del = min(sm, vec[i]-mn);
            vec[i] -= del;
            dif += del;
            sm -= del;
        }
    }
    
    for(int i = k; i < n; i++){
        
        if(i-k >= 0) sm -= vec[i-k];
        
        sm += vec[i];
        
        if(sm > 0){
            int del = min(sm, vec[i]-mn);
            vec[i] -= del;
            dif += del;
            sm -= del;
        }
    }
    
    cout << dif << endl;
    for(int i : vec) cout << i << ' '; cout << endl;
}
