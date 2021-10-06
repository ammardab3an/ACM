// Problem: E. Arranging The Sheep
// Contest: Codeforces - Codeforces Round #719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/E
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
 
const int NMAX = 1e6 + 10;

int n;
char str[NMAX];
int pre[NMAX];
int cnt[NMAX];
int foo[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    for(int i = 1; i < NMAX; i++) foo[i] = foo[i-1] + i;
    
    int t; cin >> t; while(t--){

        cin >> n;
        cin >> str;
        
        pre[0] = str[0] == '*';
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + (str[i] == '*') * (i+1);
        }
        
        cnt[0] = str[0] == '*';
        for(int i = 0; i < n; i++){
            cnt[i] = cnt[i-1] + (str[i] == '*');
        }
        
        int ans = INFLL;
        
        for(int i = 0; i < n; i++){
            
            int suf = pre[n-1] - pre[i];
            int ccnt = cnt[n-1] - cnt[i];
            int cans = suf - ccnt * (i+1+1) - foo[ccnt-1];
            
            int p = pre[i];
            int pcnt = cnt[i];
            int pans = pcnt * (i+1) - p - foo[pcnt-1];
            
            ans = min(ans, cans + pans);
        }
        
        cout << ans << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
