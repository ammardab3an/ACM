// Problem: F. Vitaly and Advanced Useless Algorithms
// Contest: Codeforces - Codeforces Round #776 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1650/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
 
const int NMAX = 1e5 + 10;

int n, m;
int arr[NMAX];
int opt[NMAX][3];
int pos[NMAX];
int nxt[NMAX];
int mem[NMAX][111][2];
int vis[NMAX][111][2], vid;
vi calc_res;

int go(int i, int rst, bool b){
	
	if(rst <= 0){
		return 0;
	}	
	
	if(i == m || (!b && opt[pos[i]][0] != opt[pos[i-1]][0])){
		return INF;
	}
	
	if(vis[i][rst][b]==vid){
		return mem[i][rst][b];
	}
	else{
		vis[i][rst][b] = vid;
	}
	
	int st_path = go(i+1, rst, 0);
	int nd_path = go(i+1, rst-opt[pos[i]][2], 0) + opt[pos[i]][1];
	
	int ans = min(st_path, nd_path);
	return mem[i][rst][b] = ans;
}

void calc(int i, int rst, bool b){
	
	if(rst <= 0){
		return;
	}	
	
	if(go(i, rst, b) == go(i+1, rst, 0)){
		calc(i+1, rst, 0);
	}
	else{
		calc_res.push_back(i);
		calc(i+1, rst-opt[pos[i]][2], 0);
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			nxt[i] = m;
		}		
		
		for(int i = 0; i < m; i++)
		for(int j = 0; j < 3; j++){
			cin >> opt[i][j];
		}
		
		for(int i = 0; i < m; i++){
			opt[i][0]--;
		}
		
		iota(pos, pos+m, 0);
		sort(pos, pos+m, [&](int i, int j){
			return opt[i][0] < opt[j][0];
		});
		
		for(int i = 0; i < m; i++){
			nxt[opt[pos[i]][0]] = min(nxt[opt[pos[i]][0]], i);
		}
		
		// for(int i = 0; i < m; i++){
			// for(int j = 0; j < 3; j++){
				// cout << opt[pos[i]][j] << ' ';
			// }
			// cout << endl;
		// }
		// for(int i = 0; i < n; i++){
			// cout << nxt[i] << ' ';
		// } cout << endl;
		
		vid++;
		calc_res.clear();
		
		bool bad = false;
		
		int h = 0;
		for(int i = 0; i < n; i++){
			int nh = go(nxt[i], 100, 1);
			// cout << i << ' ' << nh << endl;
			if(h+nh > arr[i]){
				bad = true;
				break;
			}
			else{
				h += nh;
				calc(nxt[i], 100, 1);
			}
		}
		
		if(bad){
			cout << -1 << endl;
		}
		else{
			cout << calc_res.size() << endl;
			for(auto i : calc_res){
				cout << pos[i]+1 << ' ';
			}
			cout << endl;
		}
    }	
}
