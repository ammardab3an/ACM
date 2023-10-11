// Problem: F - Yakiniku Restaurants
// Contest: AtCoder - AtCoder Regular Contest 067
// URL: https://atcoder.jp/contests/arc067/tasks/arc067_d
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct sparse_table{
    
    vector<vi> st;
    vector<int> lg2;
    
    sparse_table(){};
    
    sparse_table(const vi &vec){
        
        int n = vec.size();
        int k = ceil(log2(double(n)));
        st.resize(n, vi(k+1));
        
        for (int i = 0; i < n; i++){
            st[i][0] = vec[i];
        }

        for (int j = 1; j <= k; j++){
	        for (int i = 0; i + (1 << j) <= n; i++){
	        	st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	        }
        }
        
        lg2.resize(n+1);
        
        lg2[1] = 0;
        for(int i = 2; i <= n; i++){
            lg2[i] = lg2[i/2] + 1;
        }
    }
        
    int query(int l, int r){
        int j = lg2[r-l+1];
        return max(st[l][j], st[r-(1<<j)+1][j]);
    }
};

int n, m;
int arr[NMAX];
int mat[NMAX][202];
sparse_table st[202];
int ans;

void init(){
	
	for(int i = 0; i < m; i++){
		
		vi cur(n);
		for(int j = 0; j < n; j++){
			cur[j] = mat[j][i];
		}
		
		st[i] = sparse_table(cur);
	}
}

int calc(int l, int r){
	
	int ret = 0;
	
	for(int i = 0; i < m; i++){
		ret += st[i].query(l, r);
	}
	
	ret -= arr[r] - arr[l];
	
	return ret;
}

void go(int i, int j, int l, int r){
	
	if(i > j){
		return;
	}	
	
	int mid = (i+j)/2;
	pii cans = {-1, -1};
	for(int k = l; k <= min(r, mid); k++){
		cans = max(cans, {calc(k, mid), k});
	}
	
	ans = max(ans, cans.first);
	
	int opt = cans.second;
	go(i, mid-1, l, opt);
	go(mid+1, j, opt, r);
}

int32_t main(){
    
    fastIO;
    
	cin >> n >> m;
	for(int i = 1; i < n; i++){
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++){
		cin >> mat[i][j];
	}
	
	init();
	
	go(0, n-1, 0, n-1);
	cout << ans << endl;
}
