// Problem: C. Quiz Master
// Contest: Codeforces - Codeforces Round #845 (Div. 2) and ByteRace 2023
// URL: https://codeforces.com/contest/1777/problem/C
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

vi factors[NMAX];
int vis[NMAX];
int frq[NMAX];
int vid;
int cnt;
int m;

void reset(){
	vid++;
	cnt = 0;
}

bool debug = false;

void insert(int x){
	
	if(x > m) return;
	
	if(debug)
	cout << "ins " << x << endl;
	
	if(vis[x] != vid){
		vis[x] = vid;
		frq[x] = 0;
	}
	
	frq[x]++;
	if(frq[x]==1) cnt++;
}

void erase(int x){
	
	if(x > m) return;
	
	if(debug)
	cout << "ers " << x << endl;
	
	if(vis[x] != vid){
		vis[x] = vid;
		frq[x] = 0;
	}
	
	frq[x]--;
	if(frq[x]==0) cnt--;
	
	assert(frq[x] >= 0);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	for(int i = 1; i < NMAX; i++){
		
		int x = i;
		for(int j = 1; j*j <= x; j++) if(x%j==0){
			factors[i].push_back(j);
			if(x/j != j) factors[i].push_back(x/j);
		}	
		
		sort(factors[i].begin(), factors[i].end());
		factors[i].resize(unique(factors[i].begin(), factors[i].end())-factors[i].begin());
	}   
	 
    int t; cin >> t; while(t--){

		int n;
		cin >> n >> m;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		sort(vec.begin(), vec.end());
		
		auto test = [&](int width){
			
			reset();
			
			int r = 0;
			for(int l = 0; l < n; l++){
				
				if(l){
					for(auto e : factors[vec[l-1]]){
						erase(e);
					}
				}
				
				while(r < n && vec[r]-vec[l] <= width){
					
					for(auto e : factors[vec[r]]){
						insert(e);
					}
					
					r++;
				}
				
				if(cnt==m) return true;
			}
			
			return false;
		};
		
		int l = 0;
		int r = 1e5 + 10;
		
		int ans = -1;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			
			if(test(mid)){
				ans = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		
		cout << ans << endl;
    }	
}
