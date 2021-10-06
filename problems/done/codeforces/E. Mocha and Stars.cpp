// Problem: E. Mocha and Stars
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/E
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
const int MOD = 998244353; //1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * a * b) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (a + b) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 1e5 + 10;

vector <int> prime;
bool not_prime[NMAX];
int mob[NMAX];
int l[NMAX], r[NMAX];

void mobius(int n = NMAX){
	
	for(int i = 2; i < n; i++){
		
		if(!not_prime[i]){
			prime.push_back(i);
			mob[i] = -1;
		}
		
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			
			not_prime[i * prime[j]] = true;
			
			if (i % prime[j] == 0){
				mob[i * prime[j]] = 0;
				break;	
			}
			else{
				mob[i * prime[j]] = mob[i] * mob[prime[j]];
			}
		}
	}	
}

int n, m, g;
int mem[55][100100];
int vis[55][100100], vid;

int go(int i, int left){
    
    if(left < 0) return 0;
    if(i == n) return left+1;
    if(!left) return 0;
    
    if(vis[i][left] == vid) return mem[i][left];
    vis[i][left] = vid;
    
    int cl = (l[i]+g-1)/g;
    int cr = r[i]/g;
    
    int bg = left-cr;
    int ed = left-cl;
    
    int pre = go(i, left-1);
    int cur = add(go(i+1, ed), -go(i+1, bg-1));
    
    return mem[i][left] = add(pre, cur);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }
    
    mobius();
    mob[1] = 1;
    
    int ans = 0;
    
    for(int i = 1; i < NMAX; i++){
        
        if(m/i == 0) break;
        
        vid++, ::g = i;
        int cans = add(go(0, m/i), -go(0, m/i-1));
        
        ans = add(ans, mul(mob[i], cans));
    }
    
    cout << ans << endl;
}