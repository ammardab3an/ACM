// Problem: A. Average Rank
// Contest: Codeforces - 2019-2020 ICPC Northwestern European Regional Programming Contest (NWERC 2019)
// URL: https://codeforces.com/gym/102500/problem/A
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
    
    vi pnt(n, 0);
    vi ans(n, 1*k);
    vi tmp(k+1, 0);
    vi pre(k+5, n);
    
    for(int i = 0; i < k; i++){
        
        int rk = k-i;
        
        int m; cin >> m; while(m--){
            
            int c;
            cin >> c;
            c--;
            
            int old_lvl = pre.back() - pre[pnt[c]];
            int new_lvl = pre.back() - pre[pnt[c]+1];
            ans[c] -= (old_lvl + 1) * rk;
            ans[c] += (new_lvl + 1) * rk;
            
            ans[c] += tmp[pnt[c]];
            ans[c] -= tmp[pnt[c]+1];
            tmp[pnt[c]] += rk;
            
            pre[pnt[c]++]--;
        }
    }
    
    cout << fixed << setprecision(9);
    
    for(int i = 0; i < n; i++){
        long double tot = ans[i] + tmp[pnt[i]];
        cout << tot/k << endl;
    }
}
