// Problem: F - Cards
// Contest: AtCoder - AtCoder Beginner Contest 247
// URL: https://atcoder.jp/contests/abc247/tasks/abc247_f
// Memory Limit: 1024 MB
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
const int MOD = 998244353; //1e9 + 7;
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

int n;
vi adj[NMAX];
bool vis[NMAX];
int mem[2][NMAX][2];
int _vis[2][NMAX][2], vid;

int dfs(int u){
	
	int ret = 1;
	vis[u] = true;
	
	for(auto v : adj[u]) if(!vis[v]){
		ret += dfs(v);	
	}	
	
	return ret;
}

int go(int i, bool lst, bool b){
	
	if(i==0){
		return go(i+1, b, b);	
	}
	if(i == n-1){
		return (!lst || (lst && !b)) ? 1 : 2;
	}
	
	if(_vis[b][i][lst] == vid){
		return mem[b][i][lst];
	}
	else{
		_vis[b][i][lst] = vid;
	}
	
	int ans = 0;
	
	if(lst){
		int st_path = go(i+1, 0, b);
		int nd_path = go(i+1, 1, b);
		ans = add(st_path, nd_path);
	}
	else{
		ans = go(i+1, 1, b);
	}
	
	return mem[b][i][lst] = ans;
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
    
    vi col(n);
    
    for(int i = 0; i < n; i++){
    	int c;
    	cin >> c;
    	c--;
    	col[c] = i;
    }
    
    for(int i = 0; i < n; i++){
    	int c;
    	cin >> c;
    	c--;
    	adj[col[c]].push_back(i);
    }
    
    vi vec;
    for(int i = 0; i < n; i++) if(!vis[i]){
    	vec.push_back(dfs(i));
    }
    
    // for(auto i : vec) cout << i << ' ' ; cout << endl;
    
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    while(vec.back()==1) vec.pop_back();
    
    int ans = 1;
    int lst = -1;
    int lst_ans = -1;
    
    for(auto i : vec){
    	
    	if(i==lst){
    		ans = mul(ans, lst_ans);
    		continue;	
    	}
    	
    	:: n = i;
    	vid++;
    	int st_path = go(0, 1, 0);
    	int nd_path = go(0, 1, 1);
    	int cans = add(st_path, nd_path);
    	ans = mul(ans, cans);
    	
    	lst = i;
    	lst_ans = cans;
    }
    
    cout << ans << endl;
}
