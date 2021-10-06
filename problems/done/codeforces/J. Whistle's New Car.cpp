// Problem: J. Whistle's New Car
// Contest: Codeforces - 2016-2017 ACM-ICPC, Egyptian Collegiate Programming Contest (ECPC 16)
// URL: https://codeforces.com/gym/101147/problem/J
// Memory Limit: 512 MB
// Time Limit: 15000 ms
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
 
const int NMAX = 5e5 + 10;

int n;
vpii adj[NMAX];
int arr[NMAX], ans[NMAX];

struct node{
    
    multiset<int> st;    
    int water_level = 0;
    
    void update(int v){
        water_level += v;
        while(st.size() && ((*st.begin()) + water_level < 0)){
            st.erase(st.begin());
        }
    }
    
    void insert(int v){
        st.insert(v-water_level);
    }
    
    void merge(node& other){
        for(auto i : other.st){
            st.insert(i+other.water_level-water_level);
        }
    }
};

vector<node> vec;

int dfs(int u, int p){
    
    if(adj[u].size()==1 && p!=-1){
        vec.push_back(node());    
        vec.back().insert(arr[u]);
        ans[u] = 0;
        return vec.size()-1;
    }
    
    vi tmp;
    for(auto [v, c] : adj[u]) if(v != p){
        tmp.push_back(dfs(v, u));
        vec[tmp.back()].update(-c);
        if(vec[tmp.front()].st.size() < vec[tmp.back()].st.size()){
            swap(tmp.back(), tmp.front());
        }
    }   
    
    for(int i = 1; i < tmp.size(); i++){
        vec[tmp.front()].merge(vec[tmp[i]]);
        vec[tmp[i]].st.clear();
    }
    
    ans[u] = vec[tmp.front()].st.size();
    vec[tmp.front()].insert(arr[u]);
    
    return tmp.front();
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("car.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        cin >> n;
        
        init:{
            vec.clear();
            for(int i = 0; i < n; i++) adj[i].clear();
        }
        
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        for(int i = 0; i < n-1; i++){
            
            int u, v, c;
            cin >> u >> v >> c;
            u--, v--;
            
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        
        dfs(0, -1);
        
        for(int i = 0; i < n; i++) cout << ans[i] << ' ' ; 
        cout << endl;
    }	
}
