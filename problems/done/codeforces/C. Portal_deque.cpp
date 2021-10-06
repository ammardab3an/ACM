// Problem: C. Portal
// Contest: Codeforces - Codeforces Round #745 (Div. 2)
// URL: https://codeforces.com/contest/1581/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int n, m;
char grid[555][555];
int pre[2][555][555];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        cin >> n >> m;
        
        for(int i = 0; i < n; i++) cin >> grid[i];
        
        for(int k = 0; k < 2; k++)
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            pre[k][i][j] = grid[i][j]-'0' == k;
            if(i) pre[k][i][j] += pre[k][i-1][j];
            if(j) pre[k][i][j] += pre[k][i][j-1];
            if(i&&j) pre[k][i][j] -= pre[k][i-1][j-1];
        }
        
        auto get = [&](int k, int i0, int j0, int i1, int j1){
            
            int ret = pre[k][i1][j1];
            if(i0) ret -= pre[k][i0-1][j1];
            if(j0) ret -= pre[k][i1][j0-1];
            if(i0&&j0) ret += pre[k][i0-1][j0-1];
            
            return ret;    
        };
        
        int ans = INF;
        
        for(int l = 0; l < m; l++)
        for(int r = l+3; r < m; r++){
            
            deque<int> que;
            que.push_back(-INF);
            
            for(int i = 0; i < n; i++){
                
                if(que.size() >= 4){
                    int tmp = get(1, 0, l+1, i-1, r-1) + get(0, 0, l, i-1, l) + get(0, 0, r, i-1, r) + get(0, i, l+1, i, r-1);
                    ans = min(ans, tmp - que[que.size()-4]);
                }
                
                {
                    int tmp = get(1, 0, l+1, i, r-1) + get(0, 0, l, i, l) + get(0, 0, r, i, r) - get(0, i, l+1, i, r-1);
                    que.push_back(que.empty() ? tmp : max(que.back(), tmp));
                    if(que.size() > 10) que.pop_front();
                }
            }
        }
                
        cout << ans << endl;
    }	
}
