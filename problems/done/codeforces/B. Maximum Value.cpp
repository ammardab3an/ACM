// Problem: B. Maximum Value
// Contest: Codeforces - Codeforces Round #276 (Div. 1)
// URL: https://codeforces.com/contest/484/problem/B
// Memory Limit: 256 MB
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
const int MMAX = 1e6 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));
int f[MMAX];

vi a;
set <int> s;

const int AMAX = 2e6 + 10;
int pre[AMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t = 1; 
    while(t--){
        
        int n; 
        cin >> n;
        
        a.resize(n);        
        
        for (int i=0;i<n;++i){
            cin >> a[i];
            s.insert(a[i]);
            pre[a[i]] = a[i];
        }
        
        for(int i = 1; i < AMAX; i++){
            pre[i] = max(pre[i-1], pre[i]);
        }
        
        int Ans = 0;
        sort(a.begin(),a.end());
        
        int mx = a.back();
        a.resize( unique(a.begin(), a.end()) - a.begin() );
        
        n = a.size();
        
        for (int i=0;i<n;i++){
        
            int t = a[i];
            for (int j = 2 * t; j <= 2 * mx; j += t) {
                int tt = pre[j-1];
                if(tt < t) continue;
                Ans = max(Ans, tt % t);
            }
        }
        
        cout << Ans << endl;
    }	
}
