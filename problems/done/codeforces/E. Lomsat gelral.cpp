// Problem: E. Lomsat gelral
// Contest: Codeforces - Educational Codeforces Round 2
// URL: https://codeforces.com/problemset/problem/600/E
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
 
const int NMAX = 1e5 + 10;

vi adj[NMAX];
int col[NMAX], ans[NMAX];

vector<pair<map<int,int>, map<int, int>>> vec;

int dfs(int u, int p){
    
    if(p != -1 && adj[u].size()==1){
        
        ans[u] = col[u];

        map<int, int> mp, pm;
        
        mp[col[u]] = 1;
        pm[1] = col[u];
        
        vec.push_back({mp, pm});
        return vec.size()-1;
    }    
    
    vi tmp;
    for(auto v : adj[u]) if(v != p){
        tmp.push_back(dfs(v, u));
        if(vec[tmp.front()].first.size() < vec[tmp.back()].first.size()){
            swap(tmp.front(), tmp.back());
        }
    }
    
    auto &mx_mp = vec[tmp.front()].first;
    auto &mx_pm = vec[tmp.front()].second;
    
    for(auto i : tmp) if(i != tmp.front()){
        
        auto &mp = vec[i].first;
        auto &pm = vec[i].second;
        
        for(auto p : mp){
            
            if(mx_mp.count(p.first)){
                mx_pm[mx_mp[p.first]] -= p.first;
            }
            
            mx_mp[p.first] += p.second;
            mx_pm[mx_mp[p.first]] += p.first;
        }
        
        mp.clear();
        pm.clear();    
    }
    
    {
        pii p = {col[u], 1};
        
        if(mx_mp.count(p.first)){
            mx_pm[mx_mp[p.first]] -= p.first;
        }
        
        mx_mp[p.first] += p.second;
        mx_pm[mx_mp[p.first]] += p.first;
    }
    
    ans[u] = mx_pm.rbegin()->second;
    
    return tmp.front();
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> col[i];
    
    if(n==1){
        cout << col[0] << endl;
        return 0;
    }
    
    for(int i = 0; i < n-1; i++){
        
        int u, v;
        cin >> u >> v;
        u--, v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
}
