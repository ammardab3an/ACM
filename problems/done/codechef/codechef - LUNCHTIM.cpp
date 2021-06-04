// Problem: H - Lunchtime
// Contest: Virtual Judge - DS & DP #1
// URL: https://vjudge.net/contest/442197#problem/H
// Memory Limit: 1024 MB
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
int arr[NMAX];
int st[NMAX][LOG_MAX];
int lg[NMAX];

void init(){
    
    int K = ceil(log2(double(n)));
    
    for(int i = 0; i < n; i++)
        st[i][0] = arr[i];
        
    for(int j = 1; j <= K; j++)
        for(int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
}

int query(int l, int r){
    
    int j = lg[r-l+1];
    int ret = max(st[l][j], st[r-(1 << j)+1][j]);
    return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    lg[1] = 0;
    for(int i = 2; i < NMAX; i++)
        lg[i] = lg[i/2] + 1;
        
    int t; cin >> t; while(t--){

        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        init();
        
        vi ans(n);
        map<int, vi> mp;
        
        for(int i = n-1; i >= 0; i--){
            
            auto &vec = mp[arr[i]];
            vec.push_back(i);
            
            int l = 0;
            int r = vec.size()-1;
            
            int bs = -1;
            
            while(l <= r){
                
                int m = (l+r)/2;
                
                if(query(i, vec[m]) <= arr[i]){
                    bs = m;
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            
            ans[i] += vec.size()-1-bs;
            
            for(int i = bs; i < vec.size()-1; i++)
                ans[vec[i]] += 1;
        }
        
        for(int i : ans) cout << i << ' ' ; cout << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
