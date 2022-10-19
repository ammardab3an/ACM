// Problem: C. Gargari and Bishops
// Contest: Codeforces - Codeforces Round #264 (Div. 2)
// URL: https://codeforces.com/problemset/problem/463/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
 
const int NMAX = 2e3 + 10;

int n;
int arr[NMAX][NMAX];
int di[2][2*NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) cin >> arr[i][j];
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){    	
    	di[0][i-j+(n-1)] += arr[i][j];
    	di[1][i+j] += arr[i][j];	
    }
    
    vector<iii> mx(2, {-1, {-1, -1}});
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
    	
    	int val = di[0][i-j+(n-1)] + di[1][i+j] - arr[i][j];
    	iii cur = {val, {i+1, j+1}};
    	
    	bool b = (i+j)%2;
    	mx[b] = max(mx[b], cur);
    }
    
    cout << mx[0].first+mx[1].first << endl;
    cout << mx[0].second.first << ' ' << mx[0].second.second << ' ';
    cout << mx[1].second.first << ' ' << mx[1].second.second << endl;
}
