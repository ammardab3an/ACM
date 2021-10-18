// Problem: E. Colors and Intervals
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/E
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

// #define endl '\n'
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
 
const int NMAX = 100 + 10;
const int KMAX = 100 + 10;

const int MAX = NMAX * KMAX + 10;


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;    
    
    int sz = n*k;
    
    int mx = (n+((k-1)-1))/(k-1);
    
    vi vec(sz);
    for(auto &i : vec) cin >> i, i--;
    
    vector<vi> idx(n);
    
    for(int i = 0; i < sz; i++) {   
        idx[vec[i]].push_back(i);
    }
    
    vi colors(n);
    iota(colors.begin(), colors.end(), 0);
    
    vpii ans(n);
    
    for(int i = 1; !colors.empty(); i++){
        
        sort(colors.begin(), colors.end(), [&](int a, int b){
            return idx[a][i] < idx[b][i];
        });
        
        for(int j = 0; j < min(mx, (int)colors.size()); j++){
            ans[colors[j]] = {idx[colors[j]][i-1], idx[colors[j]][i]};
        }
        
        colors.erase(colors.begin(), colors.begin() + min(mx, (int)colors.size()));
    }
    
    for(int i = 0; i < n; i++){
        cout << ans[i].first+1 << ' ' << ans[i].second+1 << endl;
    }
}