// Problem: D. The Strongest Build
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    
    int n;
    cin >> n;
    
    vector<vi> vec(n);
    for(auto &v : vec){
        int sz; cin >> sz;
        for(auto &e : (v = vi(sz))){
            cin >> e;
        }
    }
    
    set<vi> ban_st;
    priority_queue< pair<int, vi> > que;
    
    int m; cin >> m; while(m--){
        
        vi tmp(n);
        for(int i = 0; i < n; i++){
            cin >> tmp[i], --tmp[i];
        }
        
        ban_st.insert(tmp);
    }
    
    {
        vi tmp(n);
        int sm = 0;
        for(int i = 0; i < n; i++){
            tmp[i] = vec[i].size()-1;
            sm += vec[i].back();
        }
        
        que.push({sm, tmp});
    }
    
    vi ans;
    
    while(!que.empty()){
        
        auto tp = que.top();
        que.pop();
        
        if(ban_st.count(tp.second) == 0){
            ans = tp.second;
            break;
        }
        
        int &sm = tp.first;
        vi &tmp = tp.second;
        
        for(int i = 0; i < n; i++) if(tmp[i]){
            
            sm -= vec[i][tmp[i]];
            tmp[i]--;
            sm += vec[i][tmp[i]];
            
            que.push({sm, tmp});
            
            sm -= vec[i][tmp[i]];
            tmp[i]++;
            sm += vec[i][tmp[i]];
        }
    }
    
    for(auto i : ans) cout << i+1 << ' ';
}