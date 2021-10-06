// Problem: D. Say No to Palindromes
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1555/problem/d
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
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
char str[NMAX];
int pre[NMAX][3];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    cin >> str;
    
    pre[0][0] = str[0] == 'a';
    pre[0][1] = str[0] == 'b';
    pre[0][2] = str[0] == 'c';
    
    for(int i = 1; i < n; i++)
    for(int j = 0; j < 3; j++){   
        pre[i][j] = ((i-3 >= 0) ? pre[i-3][j] : 0) + (str[i] == 'a'+j);
    }
    
    
    while(m--){
        
        int l, r;
        cin >> l >> r;
        l--, r--;
        
        int sm[3][3] = {0};
        
        for(int i = 0; i < 3; i++){
            
            if(r-i < 0) break;
               
            for(int j = 0; j < 3; j++){
                sm[i][j] = pre[r-i][j];
            }
            
            for(int j = 0; j < 3; j++) if(l-j-1 >= 0) if((l-j-1)%3==(r-i)%3){
                for(int k = 0; k < 3; k++){
                    sm[i][k] -= pre[l-j-1][k];
                }
            }
            
        }
        
        int ans = INFLL;
        
        for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) if(i != j)
        for(int k = 0; k < 3; k++) if(j != k) if(i != k){
            int cans = (r-l+1) - sm[0][i] - sm[1][j] - sm[2][k];
            ans = min(ans, cans);
        }
        
        cout << ans << endl;
    }
}
