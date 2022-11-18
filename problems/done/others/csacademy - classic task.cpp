// classic task
// https://csacademy.com/contest/archive/task/classic-task/submissions/

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
 
const int NMAX = 1e4 + 10;

int n, m;
int row[NMAX], col[NMAX];
int ans[NMAX];

int get(int i, int j){
	return (row[i] + j+1) ^ (col[j] + i+1);
}

vi go0(int x0, int y0, int x1, int y1){
	
	vector<vi> dp(2, vi(y1-y0+1));
	
	for(int i = x0; i <= x1; i++){
		for(int j = y0; j <= y1; j++){
			
			auto &cur = dp[(i-x0)&1][j-y0];
			
			if(i > x0 && j > y0){
				cur = get(i, j) + min(dp[(i-x0-1)&1][j-y0], dp[(i-x0)&1][j-y0-1]);
			}
			else if(i > x0){
				cur = get(i, j) + dp[(i-x0-1)&1][j-y0];
			}
			else if(j > y0){
				cur = get(i, j) + dp[(i-x0)&1][j-y0-1];
			}
			else{
				cur = get(i, j);		
			}
		}
	}
	
	return dp[(x1-x0)&1];
}

vi go1(int x0, int y0, int x1, int y1){
	
	vector<vi> dp(2, vi(y1-y0+1));
	
	for(int i = x1; i >= x0; i--){
		for(int j = y1; j >= y0; j--){
			
			auto &cur = dp[(i-x0)&1][j-y0];
			
			if(i < x1 && j < y1){
				cur = get(i, j) + min(dp[(i-x0+1)&1][j-y0], dp[(i-x0)&1][j-y0+1]);
			}
			else if(i < x1){
				cur = get(i, j) + dp[(i-x0+1)&1][j-y0];
			}
			else if(j < y1){
				cur = get(i, j) + dp[(i-x0)&1][j-y0+1];
			}
			else{
				cur = get(i, j);		
			}
		}
	}
	
	return dp[(x0-x0)&1];
}

int tot = 0;

void hirschberg(int x0, int y0, int x1, int y1){
	
	assert(x0 <= x1);
	assert(y0 <= y1);
	
	// cout << x0 << ' ' << y0 << ' ' << x1 << ' ' << y1 << endl << flush;
	
	if(x0==x1){
		for(int i = y0; i <= y1; i++){
			tot += get(x0, i);
		}
		for(int i = y0; i < y1; i++){
			cout << 'R';
		}
		return;
	}
	
	int mid = x0 + (x1-x0)/2;
	vi v0 = go0(x0, y0, mid, y1);
	vi v1 = go1(mid+1, y0, x1, y1);
	
	int mn = INFLL;
	int mn_p = -1;
	for(int i = 0; i <= y1-y0; i++){
		if(v0[i]+v1[i] < mn){
			mn = v0[i]+v1[i];
			mn_p = y0+i;
		}
	}
	
	hirschberg(x0, y0, mid, mn_p);
	cout << 'D';
	hirschberg(mid+1, mn_p, x1, y1);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> row[i];
    for(int i = 0; i < m; i++) cin >> col[i];
    
    if(n==m && n==0){
    	n = m = 1000;
    	for(int i = 0; i < n; i++) row[i] = rand()&1;
    	for(int i = 0; i < m; i++) col[i] = rand()&1;
    }
    
    // for(int i = 0; i < n; i++){
    	// for(int j = 0; j < m; j++){
    		// cout << get(i, j) << ' ';
    	// }
    	// cout << endl;
    // }
    // cout << endl;
    	
    hirschberg(0, 0, n-1, m-1);
    
    // cout << endl;
    // cout << tot << endl;
}
