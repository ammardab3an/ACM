// Problem: D. Bandit in a City
// Contest: Codeforces - Codeforces Round #678 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1436/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
int val[NMAX];
vi adj[NMAX];

void merge(map<int, int> &a, map<int, int> &b){
	
	if(a.size() < b.size()){
		swap(a, b);
	}	
	
	for(auto [v, f] : b){
		a[v] += f;
	}
}

map<int, int> go(int u){
	
	map<int, int> mp;
	
	if(adj[u].empty()){
		mp[val[u]] = 1;
		return mp;
	}	
	
	for(auto v : adj[u]){
		map<int, int> nxt = go(v);
		merge(mp, nxt);
	}
	
	int rm = val[u];
	
	while(rm){
		
		if(mp.size()==1){
			
			if(rm%(mp.begin()->second)==0){
				int k = rm/(mp.begin()->second);
				pii tt = *mp.begin();
				mp.clear();
				mp[tt.first+k] = tt.second;	
			}
			else{
				int k = rm/(mp.begin()->second);
				int r = rm%(mp.begin()->second);
				pii tt = *mp.begin();
				mp.clear();
				mp[tt.first+k+1] = r;
				mp[tt.first+k] = tt.second-r;
			}
			
			rm = 0;
		}
		else{
			
			int dif = (mp.rbegin()->first)-(mp.begin()->first);
			int c = min(mp.begin()->second, rm/dif);
			
			if(c){
				mp.begin()->second -= c;
				mp.rbegin()->second += c;
				rm -= c*dif;
			}
			else{
				mp.begin()->second -= 1;
				mp[(mp.begin()->first)+rm]++;
				rm = 0;
			}	
		}
		
		if(mp.begin()->second==0){
			mp.erase(mp.begin());
		}
	}
	
	return mp;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 1; i < n; i++){
    	int p;
    	cin >>p;
    	p--;
    	adj[p].push_back(i);
    }
    for(int i = 0; i < n; i++){
    	cin >> val[i];
    }
    
    map<int, int> ans = go(0);
    cout << ans.rbegin()->first << endl;
}
