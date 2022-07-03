// 3D cummulative sum

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
 
const int NMAX = 101;

int n;
int arr[NMAX][NMAX][NMAX];
int pre[NMAX][NMAX][NMAX];

void fill(){
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	for(int k = 0; k < n; k++){
		pre[i][j][k] = arr[i][j][k];
		if(i) pre[i][j][k] += pre[i-1][j][k];
		if(j) pre[i][j][k] += pre[i][j-1][k];
		if(k) pre[i][j][k] += pre[i][j][k-1];
		if(i&&j) pre[i][j][k] -= pre[i-1][j-1][k];
		if(i&&k) pre[i][j][k] -= pre[i-1][j][k-1];
		if(j&&k) pre[i][j][k] -= pre[i][j-1][k-1];
		if(i&&j&&k) pre[i][j][k] += pre[i-1][j-1][k-1];
	}
}

int go(vi x, vi y, vi z){
	
	int ret = 0;
	ret += pre[x[1]][y[1]][z[1]];
	if(x[0]) ret -= pre[x[0]-1][y[1]][z[1]];
	if(y[0]) ret -= pre[x[1]][y[0]-1][z[1]];
	if(z[0]) ret -= pre[x[1]][y[1]][z[0]-1];
	if(x[0]&&y[0]) ret += pre[x[0]-1][y[0]-1][z[1]];
	if(x[0]&&z[0]) ret += pre[x[0]-1][y[1]][z[0]-1];
	if(y[0]&&z[0]) ret += pre[x[1]][y[0]-1][z[0]-1];
	if(x[0]&&y[0]&&z[0]) ret -= pre[x[0]-1][y[0]-1][z[0]-1];
	
	return ret;
}

int calc(vi x, vi y, vi z){
	
	int ret = 0;
	for(int i = x[0]; i <= x[1]; i++)
	for(int j = y[0]; j <= y[1]; j++)
	for(int k = z[0]; k <= z[1]; k++){
		ret += arr[i][j][k];
	}
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    for(int k = 0; k < n; k++){
    	arr[i][j][k] = rand(10, 99);
    }
    
    fill();
    
    int q;
    cin >> q;
    while(q--){
    	
    	vi x(2);
    	vi y(2);
    	vi z(2);
    	
    	for(int i = 0; i < 2; i++){
    		x[i] = rand(0, n-1);
    		y[i] = rand(0, n-1);
    		z[i] = rand(0, n-1);
    	}
    	
    	if(x[0] > x[1]) swap(x[0], x[1]);
    	if(y[0] > y[1]) swap(y[0], y[1]);
    	if(z[0] > z[1]) swap(z[0], z[1]);
    	
    	int st_path = go(x, y, z);
    	int nd_path = calc(x, y, z);
    	
    	if(st_path != nd_path){
    		cout << x[0] << ' ' << y[0] << ' ' << z[0] << endl;
    		cout << x[1] << ' ' << y[1] << ' ' << z[1] << endl;
    		cout << st_path << ' ' << nd_path << endl;
    		break;
    	}
    }
}
