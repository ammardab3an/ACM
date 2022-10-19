// Problem: E. Narrow Components
// Contest: Codeforces - Educational Codeforces Round 126 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1661/problem/E
// Memory Limit: 256 MB
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
 
const int NMAX = 5e5 + 10;

int n;
string grid[3];
int pre[NMAX];
int bad[NMAX];
bool zero[NMAX];

int par[NMAX*3];
int get_par(int u){
	return par[u] = (par[u]==u) ? u : get_par(par[u]);
}
bool merge(int u, int v){
	if((u=get_par(u))==(v=get_par(v))){
		return false;
	}
	if(rand()&1) swap(u, v);
	par[u] = v;
	return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < 3; i++){
    	cin >> grid[i];
    }
    
    for(int i = 0; i < 3*n; i++){
    	par[i] = i;
    }
    
    int cans = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < 3; j++) if(grid[j][i]=='1'){
    		
    		cans++;
    		
    		if(i && grid[j][i-1]=='1'){
    			cans -= merge(j*n+i, j*n+(i-1));
    		}
    		
    		if(j && grid[j-1][i]=='1'){
    			cans -= merge(j*n+i, (j-1)*n+i);
    		}
    	}
    	
    	pre[i] = cans;
    }
    
    for(int i = 0; i < n; i++){
    	bad[i] = grid[0][i]=='1' && grid[1][i]=='0' && grid[2][i]=='1';
    }   
    for(int i = n-2; i >= 0; i--){
    	if(bad[i]==1){
    		bad[i] += bad[i+1];
    	}
    }
    
    for(int i = 0; i < n; i++){
    	zero[i] = grid[0][i]=='0' && grid[1][i]=='0' && grid[2][i]=='0';
    }
    
    // for(int i = 0; i < n; i++) cout << i+1 << ' '; cout << endl;
    // for(int i = 0; i < n; i++) cout << pre[i] << ' '; cout << endl;
    // for(int i = 0; i < n; i++) cout << bad[i] << ' '; cout << endl;
    
    int q; cin >> q; while(q--){
    	
    	int l, r;
    	cin >> l >> r;
    	l--, r--;
    	
    	if(!bad[l]){
	    	int cans = pre[r] - (pre[l] - !zero[l]);
    		cout << cans << endl;		
    	}
    	else{
    		
    		if(l+bad[l] > r){
    			cout << 2 << endl;
    		}
    		else{
    			
    			int cans = pre[r] - (pre[l+bad[l]] - !zero[l+bad[l]]);
    			
	    		cans += 2;
	    		int j = l+bad[l];
	    		cans -= grid[0][j]=='1';
	    		cans -= grid[2][j]=='1';
		    	
		    	cout << cans << endl;
    		}
    	}
    }
}
