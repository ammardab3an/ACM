// Problem: C - Triangle?
// Contest: AtCoder - AtCoder Beginner Contest 224
// URL: https://atcoder.jp/contests/abc224/tasks/abc224_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
    
    int n;
    cin >> n;
    
    vpii vec(n);
    for(auto &p : vec) cin >> p.first >> p.second;
    
    sort(vec.begin(), vec.end());
    
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
    for(int k = j+1; k < n; k++){
        
        pii p0 = vec[i];
        pii p1 = vec[j];
        pii p2 = vec[k];
        
        int m0 = p1.second - p0.second;
        int m1 = p1.first - p0.first;
        
        int g = __gcd(m0, m1);
        m0 /= g;
        m1 /= g;
        
        int m2 = p2.second - p1.second;
        int m3 = p2.first - p1.first;
        
        g = __gcd(m2, m3);
        m2 /= g;
        m3 /= g;
        
        ans += (m0 != m2) || (m1 != m3);
    }
    
    cout << ans << endl;
}
