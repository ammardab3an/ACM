// Problem: C. Prime Number
// Contest: Codeforces - Codeforces Round #209 (Div. 2)
// URL: https://codeforces.com/problemset/problem/359/C
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
const int MOD = 1e9 + 7;
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

    int n, x;
    cin >> n >> x;
    
    vi a(n);
    for(auto &i : a) cin >> i;
    
    int com = 0;
    for(int i = 0; i < n-1; i++) com += a[i];
    
    map<int, int> cnt;
    for(int i = 0; i < n; i++) cnt[a[n-1] - a[i]]++;
    
    int power = 0;
    
    for(auto p : cnt){
        if(p.second % x != 0){
            power = p.first;
            break;
        }
        cnt[p.first+1] += p.second/x;
    }
    
    power = min(power, a[n-1]);
    
    int ans = pow_exp(x, com + power);
    
    cout << ans << endl;    
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
