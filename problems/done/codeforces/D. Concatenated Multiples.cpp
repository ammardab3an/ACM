// Problem: D. Concatenated Multiples
// Contest: Codeforces - Codeforces Round #506 (Div. 3)
// URL: https://codeforces.com/contest/1029/problem/D
// Memory Limit: 256 MB
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

int vec[NMAX];
map<int, int> mp[11];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        
        int l = 0;
        int t = vec[i];
        while(t) l++, t/=10;    
        
        int p = 1;
        for(int j = 0; j < 11; j++){
            int x = (vec[i] * p) % k;
            auto it = mp[j].find((k-x)%k);
            if(it != mp[j].end()) ans += it->second;
            p = (p*10)%k;   
        }
        
        mp[l][(vec[i]%k)]++;
    }
    
    for(int i = 0; i < 11; i++) mp[i].clear();
    reverse(vec, vec+n);
    
    for(int i = 0; i < n; i++){
        
        int l = 0;
        int t = vec[i];
        while(t) l++, t/=10;    
        
        int p = 1;
        for(int j = 0; j < 11; j++){
            int x = (vec[i] * p) % k;
            auto it = mp[j].find((k-x)%k);
            if(it != mp[j].end()) ans += it->second;
            p = (p*10)%k;   
        }
        
        mp[l][(vec[i]%k)]++;
    }
    
    cout << ans << endl;
}
