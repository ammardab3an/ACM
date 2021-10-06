// Problem: E. Elections
// Contest: Codeforces - 2019-2020 ICPC, NERC, Northern Eurasia Finals (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1267/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
    
    int n, m;
    cin >> n >> m;
    
    vector<vi> vec(m, vi(n));
    for(auto &v : vec) for(auto &i : v) cin >> i;
    
    int ans = INF;
    vi ans_vec;
    
    for(int i = 0; i < n-1; i++){
    	
    	vpii tmp;
    	
    	int dif = 0;
    	
    	for(int j = 0; j < m; j++){
    		int cdif = vec[j][n-1] - vec[j][i];
    		dif += cdif;
    		if(cdif > 0) tmp.emplace_back(cdif, j);
    	}
    	
    	sort(tmp.begin(), tmp.end(), greater<pii>());
    	
    	int cans = 0;
    	vi cans_vec;
    	
    	for(auto p : tmp){
    		cans++;
    		cans_vec.push_back(p.second);
    		dif -= p.first;
    		if(dif <= 0) break;
    	}
    	
    	if(cans < ans){
    		ans = cans;
    		ans_vec = cans_vec;
    	}
    }
    
    cout << ans << endl;
    for(auto i : ans_vec) cout << i+1 << ' ';
}