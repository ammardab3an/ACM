// Problem: D. Round Subset
// Contest: Codeforces - Educational Codeforces Round 26
// URL: https://codeforces.com/problemset/problem/837/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    
    vpii vec(n);
    int mx_5 = 0;
    int sm_5 = 0;
    
    for(int i = 0; i < n; i++){
        
        ll ai;
        cin >> ai;
        
        int cnt_2 = 0;
        int cnt_5 = 0;
        
        while(ai > 0 && ai%2==0){
            cnt_2++;
            ai /= 2;
        }
        
        while(ai > 0 && ai%5==0){
            cnt_5++;
            ai /= 5;
        }
        
        vec[i] = {cnt_2, cnt_5};
        mx_5 = max(mx_5, cnt_5);
        sm_5 += cnt_5;
        
    }

    vector<vi> dp(k+1, vi(sm_5+1, -INF));
    dp[0][0] = 0;
    
    for(int i = 0; i < n; i++){
        
        for(int j = k; j >= 1; j--){
            
            for(int w = vec[i].second; w <= sm_5; w++){
                
                dp[j][w] = max(dp[j][w], dp[j-1][w-vec[i].second]+vec[i].first);
            }
        }    
    }   
    
    int ans = 0;
    for(int i = 0; i <= sm_5; i++){
        ans = max(ans, min(i, dp[k][i]));
    }
    cout << ans << endl;
}
