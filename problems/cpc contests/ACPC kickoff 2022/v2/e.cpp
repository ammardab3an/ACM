
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
int pro[3];
int mem[NMAX][4][4];
int vis[NMAX][4][4], vid;
int _2, _3;

int go(int i, int lst, int cnt_s){
	
	if(i==n){
		return 0;
	}	
	
	int &ret = mem[i][lst][cnt_s];
	if(vis[i][lst][cnt_s]==vid) return ret;
	vis[i][lst][cnt_s] = vid;
	
	if(lst==2){
		int st_path = mul(_2, go(i+1, 0, 1));
		int nd_path = mul(_2, go(i+1, 1, 0));
		return ret = add(st_path, nd_path);
	}
	else{
		int st_path = mul(_3, add(cnt_s==2, go(i+1, 0, min(cnt_s+1, int(2)))));
		int nd_path = mul(_3, go(i+1, 1, 0));
		int rd_path = mul(_3, go(i+1, 2, 0));
		return ret = add(st_path, add(nd_path, rd_path));
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    freopen("wonder.in", "r", stdin);
    
    _2 = pow_exp(2, MOD-2);
    _3 = pow_exp(3, MOD-2);
    
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < 3; i++){
			int a, b;
			cin >> a >> b;
			pro[i] = mul(a, pow_exp(b, MOD-2));
		}
		
		vid++;
		
		int st_path = mul(pro[0], go(1, 0, 1));
		int nd_path = mul(pro[1], go(1, 1, 0));
		int rd_path = mul(pro[2], go(1, 2, 0));
		
		int ans = add(st_path, add(nd_path, rd_path));
		
		cout << ans << endl;
    }	
}
