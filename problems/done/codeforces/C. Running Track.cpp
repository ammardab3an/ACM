// Problem: C. Running Track
// Contest: Codeforces - Codeforces Round #338 (Div. 2)
// URL: https://codeforces.com/contest/615/problem/C
// Memory Limit: 512 MB
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
 
const int NMAX = 2100 + 10;

int lcp[2][NMAX][NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    string a, a_rev, b;
    
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    
    a_rev = a;
    reverse(a_rev.begin(), a_rev.end());
    
    for(int i = m-1; i >= 0; i--){
        
        for(int j = n-1; j >= 0; j--){
            
            if(b[i] == a[j])
                lcp[0][i][j] = lcp[0][i+1][j+1] + 1;
                
            if(b[i] == a_rev[j])
                lcp[1][i][j] = lcp[1][i+1][j+1] + 1;
        }
    }
    
    vpii ans;
    
    for(int i = 0; i < m; i++){
        
        int mx0 = max_element(lcp[0][i], lcp[0][i] + n) - lcp[0][i];
        int mx1 = max_element(lcp[1][i], lcp[1][i] + n) - lcp[1][i];
        int len = max(lcp[0][i][mx0], lcp[1][i][mx1]);
        
        if(len == 0){
            cout << -1 << endl;
            return 0;
        }
        
        if(len == lcp[0][i][mx0]){
            ans.emplace_back(mx0, mx0 + (len-1));
        }
        else{
            ans.emplace_back((n-1 - mx1), (n-1 - mx1) - (len-1));
        }
        
        i += len-1;
    }
    
    cout << ans.size() << endl;
    for(auto p : ans) cout << p.first+1 << ' ' << p.second+1 << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
