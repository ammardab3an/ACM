// Problem: E. Keyboard Purchase
// Contest: Codeforces - Educational Codeforces Round 74 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1238/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m;
string str;
int cnt[22][22];
int mem[22][1 << 20];

int go(int i, int msk){
	
	if(i == m){
		return 0;
	}	
	
	int &ret = mem[i][msk];
	if(ret+1) return ret;
	
	int ans = INF;
	
	for(int j = 0; j < m; j++) if(!((msk>>j)&1)){
		
		int cans = 0;
		
		for(int k = 0; k < m; k++) if(k != j){
			if((msk>>k)&1){
				cans += i * cnt[j][k];
			}
			else{
				cans -= i * cnt[j][k];
			}
		}
		
		cans += go(i+1, msk | (1 << j));
		ans = min(ans, cans);
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
    
    cin >> n >> m;
    cin >> str;
    
    for(int i = 1; i < n; i++){
    	cnt[str[i-1]-'a'][str[i]-'a']++;
    	cnt[str[i]-'a'][str[i-1]-'a']++;
    }
    
    memset(mem, -1, sizeof mem);
    
    int ans = go(0, 0);
    cout << ans << endl;
}
