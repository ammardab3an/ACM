// Problem: Chef and Bitwise OR Operation
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/CHEFAOR
// Memory Limit: 256 MB
// Time Limit: 10000 ms
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

int n, k;
int arr[5050];
int mem[5050][5050];
int _or[5050][5050];
vi nxt[5050];

int go(int i, int k){
	
	if(i == n){
		return !k ? 0 : -INFLL;
	}
	
	if(!k){
		return -INFLL;
	}
	
	int &ret = mem[i][k];
	if(ret+1) return ret;
	
	int ans = 0;
	
	for(auto j : nxt[i]){
		int cans = _or[i][j] + go(j+1, k-1);
		ans = max(ans, cans);
	}
	
	return ret = ans;
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
			cin >> arr[i];
			nxt[i].clear();
		}
		
		memset(mem, -1, sizeof mem);
		
		for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++){
			
			if(i==j){
				_or[i][j] = arr[j];
			}
			else{
				_or[i][j] = _or[i][j-1] | arr[j];
			}
			
			if((i==j) || (_or[i][j] != _or[i][j-1])){
				nxt[i].push_back(j);
			}
		}
		
		for(int i = 0; i < n; i++){
			nxt[i].push_back(n-1);
		}
		
		cout << go(0, k) << endl;
    }	
}
