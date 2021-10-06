// Problem: K. Betrayed
// Contest: Codeforces - 2015 ACM Syrian Collegiate Programming Contest
// URL: https://codeforces.com/gym/101086/problem/K
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, k;
vi adj[NMAX];
int sz[22], p[22];
int mx[NMAX];

void dfs(int u, int p){
    
    mx[u] = 0;
    
    for(auto v : adj[u]) if(v != p){
        dfs(v, u);
        mx[u] = max(mx[u], mx[v] + 1);
    }
}

void go(int u, int pa, int g, int p_max){
    
    if(max(mx[u], p_max) <= k){
        p[g] += 1;
    }
    
    multiset<int> st;
    for(auto v : adj[u]) if(v != pa){
        st.insert(mx[v]+1);
    }
    
    st.insert(p_max);
    
    for(auto v : adj[u]) if(v != pa){
        st.erase(st.find(mx[v]+1));
        go(v, u, g, (*st.rbegin())+1);
        st.insert(mx[v]+1);
    }
}

int cmp(double x, double y = 0.0){
    
    if(fabs(x-y) < EPS){
        return 0;
    }
    else{
        return (x > y) * 2 -1;
    }
}

bool make_nonZero(vector<valarray<double>> &eq, int i){
    
    int n = eq.size();
    
    for(int j = i+1; j < n; j++){
        if(cmp(eq[j][i]) != 0){
            swap(eq[i], eq[j]);
            return true;
        }
    }
    
    return false;
}

bool solve(vector<valarray<double>> &eq){
    
    int n = eq.size();
    int m = eq.front().size();
    
    for(int i = 0; i < n; i++){
        
        
        if(cmp(eq[i][i]) == 0){
            if(!make_nonZero(eq, i)){
                return false;
            }
        }   
        
        double cur = eq[i][i];
        eq[i] /= cur;
        
        for(int j = 0; j < n; j++){
            
            if(i == j || cmp(eq[j][i]) == 0){
                continue;
            }
            
            cur = eq[j][i];
            eq[j] += -cur * eq[i];
        }
        
    }
    
    return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        cin >> n >> k;
        
        for(int i = 0; i < n; i++){
            
            int c;
            cin >> c;
            
            p[i] = 0;
            sz[i] = c;
            
            for(int j = 0; j < c; j++) adj[j].clear();
            
            for(int j = 1; j < c; j++){
                int pi; cin >> pi; pi--;
                adj[j].push_back(pi);
                adj[pi].push_back(j);
            }
            
            dfs(0, -1);
            go(0, -1, i, 0);
        }
        
        vector<valarray<double> > eq(n, valarray<double>(n+1));
        
        double p0 = (double) p[0] / (double) sz[0];
        double q0 = 1.0 - p0;
        
        for(int i = 0; i < n; i++){    
            
            double cp = (double) p[i] / (double) sz[i];
            double cq = 1.0 - cp;
             
            eq[i][0] = cq;
            eq[i][i] += -1.0;
            if(i+1 < n) eq[i][i+1] = cp;
            eq[i][n] = -cp -4.0*cq;
        }
        
        assert(solve(eq));
        
        cout << fixed << setprecision(4) << eq[0][n] << endl;
    }	
}
