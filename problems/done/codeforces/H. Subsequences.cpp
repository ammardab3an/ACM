// Problem: H. Subsequences (hard version)
// Contest: Codeforces - Codeforces Round #570 (Div. 3)
// URL: https://codeforces.com/contest/1183/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int n, k;
char str[111];
int nxt[111][26];
int dp[111][111];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> k >> str;
    
    memset(nxt, -1, sizeof nxt);
    
    for(int i = n-1; i >= 0; i--){
        
        for(int j = 0; j < 26; j++) 
            nxt[i][j] = nxt[i+1][j];
        
        if(i+1 < n)
            nxt[i][str[i+1]-'a'] = i+1;
    }
    
    for(int i = 0; i < n; i++){
        
        int cnt = 0;
        for(int j = 0; j < 26; j++) cnt += (nxt[i][j] != -1);
        
        dp[i][1] = cnt + (nxt[i][str[i]-'a'] == -1);
    }
    
    for(int l = 2; l <= n; l++){
        
        for(int i = n-1; i >= 0; i--){
            
            dp[i][l] += dp[i+1][l];
            dp[i][l] += dp[i+1][l-1];
            
            if(nxt[i][str[i]-'a'] != -1)
                dp[i][l] -= dp[ nxt[i][str[i]-'a'] +1 ][l-1];
            
            dp[i][l] = min(dp[i][l], int(1e12));
        }
    }
    
    // for(int i = 0; i < n; i++){
        // for(int l = 0; l <= n; l++){
            // cout << dp[i][l] << ' ';
        // } cout << endl;
    // }
    
    int ans = 0;
    for(int l = n; l >= 1; l--){
        
        int cnt = dp[0][l];
        
        if(cnt >= k){
            ans += (n-l) * k;
            k = 0;
            break;
        }
        else{
            ans += (n-l) * cnt;
            k -= cnt;
        }
    }
    
    if(k == 1){
        ans += n;
        k--;
    }
    
    cout << (k ? -1 : ans) << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
