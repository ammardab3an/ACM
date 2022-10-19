// Problem: E. Text Editor
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
 
const int NMAX = 5e3 + 10;

int n, m;
char str_a[NMAX], str_b[NMAX];
bool can0[NMAX][NMAX];
bool can1[NMAX][NMAX];
int mem1[NMAX][NMAX];

void init_can0(){
	
	for(int i = n; i >= 0; i--)
	for(int j = m; j >= 0; j--)
	{
		
		if(j==m){
			can0[i][j] = 1;
			continue;
		}
		if(i==n){
			can0[i][j] = 0;
			continue;
		}
		
		if(str_a[i] == str_b[j]){
			can0[i][j] = can0[i+1][j+1];
		}
		else{
			can0[i][j] = can0[i+1][j];
		}
	}
}

void init_can1(){
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	{
		
		if(j==0){
			can1[i][j] = (str_a[i]==str_b[j]) || (i && can1[i-1][j]);	
			continue;
		}
		
		if(i==0){
			can1[i][j] = 0;
			continue;
		}
		
		if(str_a[i] == str_b[j]){
			can1[i][j] = can1[i-1][j-1];
		}
		else{
			can1[i][j] = can1[i-1][j];
		}	
	}
}

int calc(int i, int j){
	
	if(i==n || j==m){
		return 0;
	}	
	
	int &ret = mem1[i][j];
	if(ret+1) return ret;
	
	if((str_a[i]==str_b[j]) && can0[i][j]){
		return ret = 1+calc(i+1, j+1);
	}
	else{
		return ret = 0;
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
		cin >> str_a >> str_b;
		
		init_can0();
		init_can1();
		
		for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++) mem1[i][j] = -1;
		
		if(!can0[0][0]){
			cout << -1 << endl;
			continue;
		}
		
		int ans = n;
		
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			
			if(!can1[i][j] || !can0[i][j]) continue;
			
			int len = calc(i, j);
			
			int r = n-(i+len);
			int l = i;
			
			int cans = r + (2*l-j) + (l!=0);
			
			ans = min(ans, cans);
		}
		
		cout << ans << endl;
    }	
}
