// Problem: A. Access Points
// Contest: Codeforces - 2018-2019 ICPC Northwestern European Regional Programming Contest (NWERC 2018)
// URL: https://codeforces.com/gym/102483/problem/A
// Memory Limit: 256 MB
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    vector<vi> vec(2, vi(n));
    for(int i = 0; i < n; i++){
    	cin >> vec[0][i] >> vec[1][i];
    }
    
    double ans = 0;
    
    for(auto &v : vec){

		vector<array<int, 3>> cur;
		
		for(int i = 0; i < n; i++){
			
			cur.push_back({v[i], v[i]*v[i], 1});
			
			while(cur.size() >= 2 && 
				cur[cur.size()-1][0]*cur[cur.size()-2][2] < 
				cur[cur.size()-2][0]*cur[cur.size()-1][2]){
					int j = cur.size()-2;
					cur[j][0] += cur[j+1][0];
					cur[j][1] += cur[j+1][1];
					cur[j][2] += cur[j+1][2];
					cur.pop_back();
				}	
		}
		
		for(auto [s, s2, c] : cur){
			double x = double(s)/double(c);
			ans += s2 -2.0*x*s + c*x*x;
		}
    }
    
    cout << fixed << setprecision(10) << ans << endl;
}

/*

sum (xi - x0)^2
sum xi^2 -2xi*x0 + x0^2
xi^2 is const

minimize sum of x0^2 - 2xi*x0
= n*x0^2 - 2(sum of xi)*x0
= n*x0^2 - 2*s*x0
f` = n2x0 -2s
f` = 0
x0 = s/n

*/