// Problem: C. Color Stripe
// Contest: Codeforces - Codeforces Round #135 (Div. 2)
// URL: https://codeforces.com/contest/219/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define lli int64_t

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

// #define endl '\n'
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
const int NMAX = 5e5 + 10;
const int MMAX = 2e5 + 10;

int n, k;
char str[NMAX];
int dp[NMAX][26];
int par[NMAX][26];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> k >> str;
    
    for(int i = n-1; i >= 0; i--){
        
        for(int j = 0; j < k; j++){
            
            int ans = INF;
            for(int c = 0; c < k; c++) if(c != j){
                int cans = dp[i+1][c] + (c != (str[i]-'A'));
                if(cans < ans){
                    ans = cans;
                    par[i][j] = c;
                }
            }
            
            dp[i][j] = ans;
        }
    }
    
    auto it = min_element(dp[0], dp[0]+k);
    cout << *it << endl;
    
    int i = 0;
    int c = it-dp[0];
    string ans;
    
    while(i < n){
        c = par[i][c];
        ans.push_back('A' + c);
        i++;
    }
    
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    