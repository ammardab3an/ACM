// Problem: C. Array transformation
// Contest: Codeforces - International Collegiate Programming Contest, Egyptian Collegiate Programming Contest (ECPC 2018)
// URL: https://codeforces.com/gym/101992/problem/C
// Memory Limit: 1024 MB
// Time Limit: 7000 ms
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

const int NMAX = 5e3 + 10;

int n, m;
int arr_a[NMAX];
int arr_b[NMAX];
int arr_c[NMAX];
int suf[NMAX];
int tmp[2*NMAX];
int fst[2*NMAX];
int lst[2*NMAX];
int mem[NMAX][NMAX];
int vis[NMAX][NMAX], vid;

int go(int i, int j){
	
	if(j==m){
		return suf[i];
	}	
	if(i==n){
		return 1e15;
	}
	
	int &ret = mem[i][j];
	if(vis[i][j]==vid) return ret;
	vis[i][j] = vid;
	
	int ans = 1e15;
	
	if(arr_a[i]==arr_b[j]){
		
		if(fst[arr_b[j]]==j){
			int st_path = go(i+1, j+1);
			int nd_path = arr_c[i] + go(i+1, j);
			ans = min(ans, min(st_path, nd_path));
		}
		else{
			int st_path = go(i+1, j+1);
			ans = min(ans, st_path);
		}
	}	
	else{
		if(fst[arr_a[i]] < j && j < lst[arr_a[i]]){
			// pass
		}	
		else{
			int st_path = arr_c[i] + go(i+1, j);
			ans = min(ans, st_path);
		}
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("transform.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n >> m;
		
		for(int i = 0; i < n; i++){
			cin >> arr_a[i];
		}
		
		for(int i = 0; i < m; i++){
			cin >> arr_b[i];
		}
		
		for(int i = 0; i < n; i++){
			cin >> arr_c[i];	
		}
		
		suf[n] = 0;
		for(int i = n-1; i >= 0; i--){
			suf[i] = suf[i+1] + arr_c[i];
		}
		
		{
			for(int i = 0; i < n; i++){
				tmp[i] = arr_a[i];
			}
			for(int j = 0; j < m; j++){
				tmp[n+j] = arr_b[j];
			}
			
			int sz = n+m;
			sort(tmp, tmp+sz);
			sz = unique(tmp, tmp+sz)-tmp;
			
			for(int i = 0; i < n; i++){
				arr_a[i] = lower_bound(tmp, tmp+sz, arr_a[i])-tmp;
			}
			for(int i = 0; i < m;i ++){
				arr_b[i] = lower_bound(tmp, tmp+sz, arr_b[i])-tmp;
			}
			
			for(int i = 0; i < sz; i++){
				fst[i] = INF;
				lst[i] = -INF;
			}
		}
		
		for(int i = 0; i < m; i++){
			fst[arr_b[i]] = min(fst[arr_b[i]], i);
			lst[arr_b[i]] = max(lst[arr_b[i]], i);
		}
		
		vid++;
		int ans = go(0, 0);
		
		if(ans > (1e9 * 2e5)){
			cout << "No" << endl;
		}
		else{		
			cout << ans << endl;
		}
    }	
}
