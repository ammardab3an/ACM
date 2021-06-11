// Problem: C. Diluc and Kaeya
// Contest: Codeforces - Codeforces Round #724 (Div. 2)
// URL: https://codeforces.com/contest/1536/problem/C
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
const int NMAX = 5e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
char str[NMAX];
int sum_d[NMAX], sum_k[NMAX];
int ans[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        cin >> n;
        cin >> str;
        
        sum_d[0] = str[0] == 'D';
        sum_k[0] = str[0] == 'K';
        
        for(int i = 1; i < n; i++){
            
            sum_d[i] = sum_d[i-1] + (str[i] == 'D');
            sum_k[i] = sum_k[i-1] + (str[i] == 'K');
            
        }
        
        memset(ans, 0, n * sizeof(ans[0]));
        
        set<pii> st;
        
        for(int i = 0; i < n; i++){
            
            int a = sum_d[i];
            int b = sum_k[i];
            
            int g = __gcd(sum_d[i], sum_k[i]);
            if(g == 0) g = 1;
            
            a /= g;
            b /= g;
            
            if(st.count({a, b})){
                continue;
            }            
            else{
                st.insert({a, b});
            }
               
            int cnt = 0;
            int sm = a+b;
            
            for(int j = 0; (i+sm*j) < n; j++){
                    
                int na = sum_d[i+sm*j];
                int nb = sum_k[i+sm*j];
                
                if((na*b) == (nb*a)){
                    cnt++;
                    ans[i+sm*j] = max(ans[i+sm*j], cnt);
                }
            }
        }
        
        for(int i = 0; i < n; i++) cout << ans[i] << ' ' ; cout << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
