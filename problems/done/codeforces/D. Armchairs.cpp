// Problem: D. Armchairs
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1525/problem/D
// Memory Limit: 512 MB
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
const int NMAX = 5e3 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[NMAX];
int pre[NMAX];
int mem[NMAX][NMAX];

int go(int i, int cur){
    
    if(i == n) return cur == pre[n-1] ? 0 : INFLL;
    
    int &ret = mem[i][cur];
    if(ret+1) return ret;
    
    int ans = INFLL;
    
    if(arr[i]){
        
        int add = 0;
            
        if(cur >= pre[i]){
            add = i;
        }
        else{
            add = -i;
        }
        
        ans = go(i+1, cur) + add;
    }
    else{
        
        int add = 0;
        
        if(cur+1 > pre[i]){
            add = -i;
        }
        else{
            add = i;
        }
        
        int stPath = go(i+1, cur);
        int ndPath = go(i+1, cur+1) + add;
        
        ans = min(stPath, ndPath);
    }
    
    return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    pre[0] = (arr[0] == 1);
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + (arr[i] == 1);
    }
    
    memset(mem, -1, sizeof mem);
    
    cout << go(0, 0);
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
