// Problem: A. Kyoya and Colored Balls
// Contest: Codeforces - Codeforces Round #309 (Div. 1)
// URL: https://codeforces.com/problemset/problem/553/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}

int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
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

int n;
int arr[1010];
int sm[1010];
int mem[1010][1010];
int cho[1010][1010];

int init(){
	
	for(int i = 0; i < 1010; i++)
	for(int j = 0; j <= i; j++){
		
		if(j == 0 || j == i)
			cho[i][j] = 1;
		else
			cho[i][j] = add(cho[i-1][j-1], cho[i-1][j]);
	}
}

int choose(int n, int c){
	
	if(n < c) return 0;
	return cho[n][min(c, n-c)];
}

int go(int pos, int lst){
	
	if(pos == n+1) return 1;
	
	int &ret = mem[pos][lst];
	if(ret+1) return ret;
	
	int ans = 0;
	
	for(int i = lst+1; i <= sm[n]-(n-pos); i++){
		
		int cans = mul(choose(i-sm[pos-1]-1, arr[pos]-1), go(pos+1, i));
		
		ans = add(ans, cans);	
	}	
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	init();
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = 1; i <= n; i++) sm[i] = sm[i-1] + arr[i];
	
	memset(mem, -1, sizeof mem);
	
	cout << go(1, 0) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
