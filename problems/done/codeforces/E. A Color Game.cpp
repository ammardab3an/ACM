// Problem: E. A Color Game
// Contest: Codeforces - The 2020 ICPC Asia Taipei-Hsinchu Site Programming Contest
// URL: https://codeforces.com/gym/102835/problem/E
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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
string str;
int dp[505][505][7];
int conv[26];

void init(){	
	conv['R'-'A'] = 0;
	conv['G'-'A'] = 1;
	conv['B'-'A'] = 2;
	conv['C'-'A'] = 3;
	conv['M'-'A'] = 4;
	conv['Y'-'A'] = 5;
	conv['K'-'A'] = 6;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
    
    cin >> str >> m;
    n = str.size();
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    for(int c = 0; c < 7; c++){
    	dp[i][j][c] = -INF;
    }
    
    for(int l = 1; l <= n; l++)
	for(int i = 0; i+l-1 < n; i++)
	for(int c = 0; c < 7; c++)
	{
    			
		if(l==1){
			if(conv[str[i]-'A']==c){
				dp[i][i][c] = 1;
			}
			else if(m == 1){
				dp[i][i][c] = 0;
			}
			else{
				dp[i][i][c] = -INF;
			}
		}	
		else{
		
			int j = i+l-1;
			
			int ans = -INF;
			for(int k = i; k < j; k++){
				ans = max(ans, dp[i][k][c] + dp[k+1][j][c]);
			}
			
			if(ans < 0){
				bool found = false;
				for(int cc = 0; cc < 7 && !found; cc++) if(cc != c){
					for(int k = i; k < j; k++){
						
						int cans = dp[i][k][cc] + dp[k+1][j][cc];
						if(cans==0 || cans >= m){
							ans = max(ans, int(0));
							found = true;
							break;
						}
					}
				}
			}
			
			dp[i][j][c] = ans;
		}		
    }
    
    
    int ans = dp[0][n-1][0];
    cout << ((ans==0 || ans>=m) ? "Yes" : "No") << endl;
}
