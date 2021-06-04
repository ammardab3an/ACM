// Problem: D. CGCDSSQ
// Contest: Codeforces - Bayan 2015 Contest Warm Up
// URL: https://codeforces.com/contest/475/problem/D
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
const int LOG_MAX = ceil(log2(double(NMAX)));

int n;
int arr[NMAX];
int st[NMAX][LOG_MAX];
int lg[NMAX];

void build(){
    
    lg[1] = 0;
    for(int i = 2; i < NMAX; i++)
        lg[i] = lg[i/2]+1;
     
    for(int i = 0; i < n; i++)
        st[i][0] = arr[i];
    
    int K = lg[n]+1;
    
    for(int j = 1; j <= K; j++){
        for(int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = __gcd(st[i][j-1], st[i + (1 << (j-1))][j-1]);
    }    
}

int query(int l, int r){
    int j = lg[r-l+1];
    return __gcd(st[l][j], st[r-(1<<j)+1][j]);
}

map<int, int> mp;
void solve(){
    
    for(int i = 0; i < n; i++){
        
        int cgcd = 0;
        for(int j = i; j < n; j++){
            
            cgcd = __gcd(cgcd, arr[j]);
            
            mp[cgcd]++;
            
            int l = j;
            int r = n-1;
            
            int ans = -1;
            
            while(l <= r){
                
                int m = (l+r)/2;
                int tgcd = query(j, m);
                
                if(tgcd%cgcd==0){
                    ans = m;
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }
            
            mp[cgcd] += ans-j;
            j = ans;
        }
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
    
    build();
    
    solve();
    
    int m; cin >> m; while(m--){
        
        int xi;
        cin >> xi;
        
        auto it = mp.find(xi);
        
        if(it != mp.end())
            cout << it->second << endl;
        else
            cout << 0 << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll]
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
