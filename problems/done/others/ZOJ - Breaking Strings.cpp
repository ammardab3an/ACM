// Problem: Breaking Strings
// Contest: ZOJ
// URL: https://zoj.pintia.cn/problem-sets/91827364500/problems/91827366359
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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
 
const int NMAX = 1e3 + 10;

int n, m;
int arr[NMAX];
int mem[NMAX][NMAX];
int pos[NMAX][NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    while(cin >> n >> m){
    	
	    // cin >> n >> m;
	    
	    m+=2;
	    arr[0] = 0;
	    arr[m-1] = n;
	    
	    for(int i = 1; i < m-1; i++){
	    	cin >> arr[i];
	    }
	    
	    for(int l = 0; l < m; l++)
	    for(int i = 0; i+l < m; i++){
	    	
	    	int j = i+l;
	    	
	    	if(i+1 >= j){
	    		mem[i][j] = 0;
	    		pos[i][j] = -1;
	    		continue;	
	    	}
	    	
	    	int p0 = pos[i][j-1];
	    	int p1 = pos[i+1][j];
	    	
	    	if(p0==-1) p0 = i+1;
	    	if(p1==-1) p1 = j-1;
	    	
	    	int cans = INFLL;
	    	int cpos = -1;
	    	
	    	for(int k = p0; k <= p1; k++){
	    		
	    		int cur = mem[i][k] + mem[k][j];
	    		
	    		if(cur < cans){
	    			cans = cur;
	    			cpos = k;
	    		}
	    	}
	    	
	    	mem[i][j] = (arr[j]-arr[i]) + cans;
	    	pos[i][j] = cpos;
	    }
	    
	    cout << mem[0][m-1] << endl;
    }
}
