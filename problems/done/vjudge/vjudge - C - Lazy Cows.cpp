// Problem: C - Lazy Cows
// Contest: Virtual Judge - Dynamic Programming Sheet 2 Week 4
// URL: https://vjudge.net/contest/490713#problem/C
// Memory Limit: 1536 MB
// Time Limit: 9000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

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
const int NMAX = 1e3 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, k, b;
int arr[NMAX], sz;
int pos[NMAX];
int mem[NMAX][NMAX][5];

int go(int i, int rm, int b){
	
	if(rm < 0){
		return INFLL;
	}
	
	if(i==sz){
		return 0;
	}
	
	int &ret = mem[i][rm][b];
	if(ret+1) return ret;
	
	if(!b){
		int st_path = (arr[i]==3 ? 2 : 1) + go(i+1, rm-1, arr[i]);
		int nd_path = 2 + go(i+1, rm-1, 3);
		int rd_path = 2 + go(i+1, rm-2, 4);
		return ret = min({st_path, nd_path, rd_path});
	}
	else{	
		
		int st_path = INFLL;
		int nd_path = INFLL;
		int rd_path = INFLL;
		
		if(b==4){
			st_path = min({go(i, rm, 0), go(i, rm, 1), go(i, rm, 2)});
		}
		else{
			st_path = go(i, rm, 0);
		}
		
		if(b==3 || b==4 || b==arr[i]){
			nd_path = (b<3 ? 1 : 2) * (pos[i] - pos[i-1]) + go(i+1, rm, b);
		}
		
		if((b==1 || b==2) && arr[i]!=b){
			rd_path = (pos[i] - pos[i-1] + 1) + go(i+1, rm-1, 4);
		}
		
		return ret = min({st_path, nd_path, rd_path});
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n >> k >> b;
		
		vector<vector<bool>> tmp(2, vector<bool>(b));
		
		for(auto _ : vi(n)){
			
			int i, j;
			cin >> i >> j;
			i--, j--;
			
			tmp[i][j] = true;
		}
		
		sz = 0;
		for(int i = 0; i < b; i++){
			
			bool b0 = tmp[0][i];
			bool b1 = tmp[1][i];
			
			if(b0&&b1){
				arr[sz++] = 3;
			}
			else if(b0){
				arr[sz++] = 1;
			}
			else if(b1){
				arr[sz++] = 2;
			}
			
			if(b0||b1){
				pos[sz-1] = i;
			}
		}
		
		// for(int i = 0; i < sz; i++){
			// cout << pos[i]+1 << ' ' << arr[i] << endl;
		// }
		
		memset(mem, -1, sizeof mem);
		
		int ans = go(0, k, 0);
		cout << ans << endl;
    }	
}
