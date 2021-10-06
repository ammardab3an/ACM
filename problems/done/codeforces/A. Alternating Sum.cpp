// Problem: A. Alternating Sum
// Contest: Codeforces - Tinkoff Internship Warmup Round 2018 and Codeforces Round #475 (Div. 1)
// URL: https://codeforces.com/problemset/problem/963/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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
const int MOD = 1e9 + 9;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	int n, a, b, k;
	cin >> n >> a >> b >> k;
	
	string str;
	cin >> str;
	
	int init = 0;
	
	int ca = pow_exp(a, n);
	int cb = 1;
	
	for(int i = 0; i < k; i++){
		
		if(str[i] == '+') init = add(init, mul(ca, cb));
		else init = add(init, -mul(ca, cb));
		
		ca = mul(ca, pow_exp(a, MOD-2));
		cb = mul(cb, b);
	}
	
	// b = b^k
	// a = a^k
	// (1, b/a, (b/a)^2, (b/a)^3, ... (b/a)^((n+1)/k) )
	
	// (1-q^(n)) / (1-q)
	
	int q = mul(pow_exp(b, k), pow_exp(pow_exp(a, k), MOD-2));
	
	int sm = add(1, -pow_exp(q, (n+1)/k));
	sm = mul(sm, pow_exp(add(1, -q), MOD-2));
	
	int ans = mul(init, sm);
	
	if(q == 1) ans = mul(init, (n+1)/k);
	
	cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
