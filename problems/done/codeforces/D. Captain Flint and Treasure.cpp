// Problem: D. Captain Flint and Treasure
// Contest: Codeforces - Codeforces Round #660 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1388/D
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[NMAX];
int b[NMAX];
vi adj[NMAX];
bool vis[NMAX];

int ans;
vi vec0, vec1;

void dfs(int nd){
    
    vis[nd] = true;
    
    for(auto nxt : adj[nd]) if(!vis[nxt]) dfs(nxt);
    
    ans += arr[nd];
    
    if(arr[nd] > 0){
        if(b[nd] != -1){
            arr[b[nd]] += arr[nd];
        }
        vec0.push_back(nd+1);        
    }
    else{
        vec1.push_back(nd+1);
    }
    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 0; i < n; i++){
        
        int bi;
        cin >> bi; bi--;
        
        b[i] = bi;
        
        if(bi != -2){
            adj[bi].push_back(i);
        }    
    }
    
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);
    
    cout << ans << endl;
    for(auto i : vec0) cout << i << ' ';
    for(auto i : vi(vec1.rbegin(), vec1.rend())) cout << i << ' ';
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  int ans = 2 + 2 + 3 + 2 + 5 -1 -10 -2 -4 -6
  
  10
-10 3 2 2 2 -2 -5 -4 2 -6
-1 -1 2 2 -1 5 5 7 7 9


  
*/    