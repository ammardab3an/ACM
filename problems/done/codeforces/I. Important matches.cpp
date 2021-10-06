// Problem: I. Important matches
// Contest: Codeforces - Egyptian Collegiate Programming Contest 2017 (ACM ECPC 2017) - original tests edition
// URL: https://codeforces.com/gym/101856/problem/I
// Memory Limit: 1024 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
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

int grid[222][222];
int pre[2020][222][222];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("important.in", "r", stdin);
    
    int tt = 0;
    int t; scanf("%d", &t); while(t--){
        
        printf("Case %d:\n", ++tt);
        
        int n, m, q;
        scanf("%d %d %d", &n, &m, &q);
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) scanf("%d", grid[i]+j);
        
        for(int k = 0; k < 2020; k++)
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            pre[k][i][j] = (grid[i][j] >= k);
            if(i) pre[k][i][j] += pre[k][i-1][j];
            if(j) pre[k][i][j] += pre[k][i][j-1];
            if(i&&j) pre[k][i][j] -= pre[k][i-1][j-1];
        }
        
        while(q--){
            
            int i, j, x, y;
            scanf("%d %d %d %d", &i, &x, &j, &y);
            i--, j--, x--, y--;
            
            int sz = (j-i+1) * (y-x+1);
            
            int l = 0;
            int r = 2000;
            
            int ans = -1;
            
            while(l <= r){
                
                int mid = (l+r)/2;
                
                int k = mid;
                int csm = pre[k][j][y];
                if(i) csm -= pre[k][i-1][y];
                if(x) csm -= pre[k][j][x-1];
                if(i&&x) csm += pre[k][i-1][x-1];
                
                if(csm*2 >= sz){
                    ans = k;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            
            printf("%d\n", ans);
        }

    }	
}
