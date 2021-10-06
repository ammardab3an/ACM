// Problem: C. Need for Pink Slips
// Contest: Codeforces - Codeforces Round #730 (Div. 2)
// URL: https://codeforces.com/contest/1543/problem/C
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

int v;
map<pii, int> mp;

double acc = 1e7;

int go(int a, int b){
    
    auto it = mp.find({a, b});
    if(it!=mp.end()) return it->second;
    
    double ret = 1.0;
    
    if(a){
        int na = min(a, v);
        if(b)
            ret += (double(a)/acc) * double(go(a-na, b+na/2))/acc;            
        else
            ret += (double(a)/acc) * double(go(a-na, b))/acc;            
    }
    
    if(b){
        int nb = min(b, v);
        if(a)
            ret += (double(b)/acc) * double(go(a+nb/2, b-nb))/acc;        
        else
            ret += (double(b)/acc) * double(go(a, b-nb))/acc;        
        
    }
    
    return mp[{a, b}] = ret * acc;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        double a, b, c, v;
        cin >> a >> b >> c >> v;
        
        a *= acc;
        b *= acc;
        c *= acc;
        v *= acc;
        
        ::v = v;
        
        mp.clear();
        int ans = go(a, b);
        
        cout << fixed << setprecision(10) << double(ans)/acc << endl;
    }	
}
