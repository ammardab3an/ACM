// Problem: C. Swap Letters
// Contest: Codeforces - Codeforces Round 585 (Div. 2)
// URL: https://codeforces.com/contest/1215/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

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

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n;
	cin >> n;
	
	string str_a, str_b;
	cin >> str_a >> str_b;
	
	n = str_a.size();
	
	vi tmp;
	vector<vi> vec(2);
	for(int i = 0; i < n; i++) if(str_a[i] != str_b[i]){
		tmp.push_back(i);
		vec[str_a[i]-'a'].push_back(i);
	}
	
	if(tmp.size()%2){
		cout << -1 << endl;
		return 0;
	}
	
	vpii ans;
	for(int i = 0; i+1 < vec[0].size(); i+=2){
		ans.push_back({vec[0][i], vec[0][i+1]});
	}
	for(int i = 0; i+1 < vec[1].size(); i+=2){
		ans.push_back({vec[1][i], vec[1][i+1]});
	}
	
	tmp.clear();
	if(vec[0].size()%2){
		tmp.push_back(vec[0].back());
	}
	if(vec[1].size()%2){
		tmp.push_back(vec[1].back());
	}
	
	if(tmp.size()){
		assert(tmp.size()==2);
		ans.push_back({tmp[0], tmp[0]});
		ans.push_back({tmp[0], tmp[1]});
	}
	
	cout << ans.size() << endl;
	for(auto [a, b] : ans){
		cout << a+1 << ' ' << b+1 << endl;
	}
}
