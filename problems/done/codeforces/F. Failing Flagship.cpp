// Problem: F. Failing Flagship
// Contest: Codeforces - 2022 Benelux Algorithm Programming Contest (BAPC 22)
// URL: https://codeforces.com/gym/104020/problem/F
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

double calc(string str){
	
	vi conv1(222);
	conv1['N'] = 0;
	conv1['S'] = 180;
	conv1['E'] = 90;
	conv1['W'] = 270;
	
	if(str.size()==1){
		return conv1[str[0]];
	}
	
	vector<vi> conv2(222, vi(222));
	conv2['N']['E'] = 45;
	conv2['S']['E'] = 45*3;
	conv2['S']['W'] = 45*5;
	conv2['N']['W'] = 45*7;
	
	if(str.size()==2){
		return conv2[str[0]][str[1]];	
	}
	
	reverse(str.begin(), str.end());
	
	double init = conv2[str[1]][str[0]];
	double cur = init;
	double deg = 45;
	
	for(int i = 0; i < 30 && (2+i < str.size()); i++){
	
		deg /= 2;
		
		if(
			(str[2+i]==str[0] && (init==1*45 || init==5*45))||
			(str[2+i]==str[1] && (init==3*45 || init==7*45))
		){
			cur += deg;
		}
		else{
			cur -= deg;
		}
	}
	
	return cur;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    string a, b;
    cin >> a >> b;
    
    double deg_a = calc(a);
    double deg_b = calc(b);
    
    double st_path = fmod(deg_a-deg_b, 360);
    double nd_path = fmod(deg_b-deg_a, 360);
    
    if(st_path < 0) st_path += 360;
    if(nd_path < 0) nd_path += 360;
    
    cout << fixed << setprecision(10) << min(st_path, nd_path);
}
