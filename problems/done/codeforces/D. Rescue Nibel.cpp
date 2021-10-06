// Problem: D. Rescue Nibel!
// Contest: Codeforces - Codeforces Round #672 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1420/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353 ; //1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}

const int NMAX = 3e5 + 10;

int inv[NMAX], fac[NMAX], ifac[NMAX];

void init(){
    
    inv[1] = 1; 
    fac[0] = ifac[0] = 1;
    
    for(int i = 2; i < NMAX; i++) inv[i] = mul(MOD-MOD/i, inv[MOD%i]);
    for(int i = 1; i < NMAX; i++) fac[i] = mul(fac[i-1], i);
    for(int i = 1; i < NMAX; i++) ifac[i] = mul(ifac[i-1], inv[i]);
}

int choose(int n, int c){
    return mul(mul(fac[n], ifac[c]), ifac[n-c]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    init();
        
    int n, k;
    cin >> n >> k;
    
    vpii vec(n), tmp;
    
    for(auto &p : vec){
        cin >> p.first >> p.second;
        tmp.push_back({p.first, -1});
        tmp.push_back({p.second, +1});
    }
    
    sort(tmp.begin(), tmp.end());
    
    int ans = 0;
    
    int cnt = 0;
    for(int i = 0; i < tmp.size(); i++){
        
        cnt += -tmp[i].second;
        
        if(tmp[i].second == -1 && cnt >= k){
            int cans = choose(cnt-1, k-1);
            ans = add(ans, cans);
        }
        
    }
    
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
