// Problem: E. Another MEX Problem
// Contest: Codeforces - CodeTON Round 6 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1870/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int NMAX = 5e3 + 10;

int n;
int arr[NMAX];
vi pos[NMAX];
int mem[NMAX][NMAX];
int vis[NMAX][NMAX], vid;
vpii tmp[NMAX];

int go(int i, int _xor){
	
	if(i==n){
		return _xor;
	}	
	
	int &ret = mem[i][_xor];
	int &vis = ::vis[i][_xor];
	if(vis==vid) return ret;
	vis = vid;
	
	int ans = go(i+1, _xor);
	
	for(auto [r, j] : tmp[i]){
		int cans = go(r, _xor^j);
		ans = max(ans, cans);
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
	
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		if(n==0){
			n = 5e3;
			for(int i = 0; i < n; i++){
				arr[i] = i%1000;
			}
		}
		
		for(int i = 0; i <= n; i++){
			pos[i].clear();
			tmp[i].clear();
		}
		
		for(int i = 0; i < n; i++){
			pos[arr[i]].push_back(i);
		}
		
		for(int i = 0; i < n; i++){
			
			auto it = lower_bound(pos[0].begin(), pos[0].end(), i);
			if(it==pos[0].end()) break;
			
			int l = *it;
			int r = *it;
			
			for(int j = 1; j <= n; j++){
				
				int nl = l;
				int nr = r;
				
				auto it = lower_bound(pos[j].begin(), pos[j].end(), i);
				
				bool good = false;
				
				if(it==pos[j].end()){
					good = true;
				}
				else{
					nl = min(nl, *it);
					nr = max(nr, *it);
				}
				
				if(!good && (l != nl || r != nr)){
					good = true;
				}
				
				if(good && l==i){
					tmp[i].push_back({r+1, j});
				}
				
				if(it==pos[j].end()){
					break;
				}
				
				l = nl;
				r = nr;
			}
		}
		
		vid++;
		int ans = go(0, 0);
		cout << ans << endl;
    }	
}
