// Problem: D2. Remove the Substring (hard version)
// Contest: Codeforces - Codeforces Round #579 (Div. 3)
// URL: https://codeforces.com/contest/1203/problem/D2
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
// typedef long long int       ll;
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
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m;
string str_a, str_b;

int nxt_f[NMAX][26];
int nxt_b[NMAX][26];

int ans_f[NMAX];
int ans_b[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> str_a >> str_b;
    
    n = str_a.size();
    m = str_b.size();
    
    {
        vi tmp(26, -1);
        
        for(int i = n-1; i >= 0; i--){
            
            for(int j = 0; j < 26; j++){
                nxt_f[i+1][j] = tmp[j];
            }
            
            tmp[str_a[i]-'a'] = i;
        }
        
        for(int j = 0; j < 26; j++){
            nxt_f[0][j] = tmp[j];
        }
        
        int p = nxt_f[0][str_b[0]-'a'];
        ans_f[0] = p+1;
        
        for(int i = 1; i < m; i++){
            p = nxt_f[p+1][str_b[i]-'a'];
            ans_f[i] = p+1;
        }   
        
    }
    
    reverse(str_a.begin(), str_a.end());
    reverse(str_b.begin(), str_b.end());
    
    {
        vi tmp(26, -1);
        
        for(int i = n-1; i >= 0; i--){
            
            for(int j = 0; j < 26; j++){
                nxt_b[i+1][j] = tmp[j];
            }
            
            tmp[str_a[i]-'a'] = i;
        }
        
        for(int j = 0; j < 26; j++){
            nxt_b[0][j] = tmp[j];
        }
        
        int p = nxt_b[0][str_b[0]-'a'];
        ans_b[0] = p+1;
        
        for(int i = 1; i < m; i++){
            p = nxt_b[p+1][str_b[i]-'a'];
            ans_b[i] = p+1;
        }   
    }
    
    // for(int i = 0; i < m; i++) cout << ans_f[i] << ' ' ; cout << endl;
    // for(int i = 0; i < m; i++) cout << ans_b[i] << ' ' ; cout << endl;
    
    int ans = max(n-ans_f[m-1], n-ans_b[m-1]);
    
    // cout << ans << endl;
    
    for(int i = 0; i < m-1; i++){
        
        int cans = ans_f[i] + ans_b[m-i-2];
        
        ans = max(ans, n-cans);
    }
    
    cout << ans << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
