// Problem: B. Madoka and the Elegant Gift
// Contest: Codeforces - Codeforces Round #777 (Div. 2)
// URL: https://codeforces.com/contest/1647/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m;
char grid[111][111];
pii mvArr[4][3] = {
					{{-1, 0}, {-1, -1}, {0, -1}},
					{{-1, 0}, {-1, 1}, {0, 1}},
					{{1, 0}, {1, 1}, {0, 1}},
					{{1, 0}, {1, -1}, {0, -1}}
				};
				
bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m;
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
			cin >> grid[i];
		}
		
		bool good = true;
		
		
		for(int i = 0; i < n && good; i++)
		for(int j = 0; j < m && good; j++) if(grid[i][j]=='0'){
			
			for(int k = 0; k < 4; k++){
				int cnt = 0;
				for(auto p : mvArr[k]){
					int ni = i + p.first;
					int nj = j + p.second;
					if(in(ni, nj) && grid[ni][nj]=='1'){
						cnt++;
					}
				}
				if(cnt==3){
					good = false;
					break;
				}
			}
		}
		
		cout << (good ? "YES" : "NO") << endl;
    }	
}
