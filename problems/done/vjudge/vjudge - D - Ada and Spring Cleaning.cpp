// Problem: D - Ada and Spring Cleaning
// Contest: Virtual Judge - String Processing Sheet Week 1
// URL: https://vjudge.net/contest/488773#problem/D
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

bool is_prime(int x){
	for(int i = 2; i*i <= x; i++) if(x%i==0){
		return false;
	}
	return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	int p[2] = {rand(1e5, 2e5), rand(1e6, 2e6)};
	while(!is_prime(p[0])) p[0]++;
	while(!is_prime(p[1])) p[1]++;
	int m[2] = {rand(30, 40), rand(50, 60)};
	while(!is_prime(m[0])) m[0]++;
	while(!is_prime(m[1])) m[1]++;
	
    int t; cin >> t; while(t--){
	
		int n, k;
		cin >> n >> k;
		
		string str;
		cin >> str;
		
		vector<vi> pre(n, vi(2));
		vector<vi> pow_m(2, vi(n));
			
		int cval[2] = {0, 0};
		
		for(int i = 0; i < n; i++){
			cval[0] = ((cval[0]*m[0])%p[0] + (str[i]-'a'+1))%p[0];
			cval[1] = ((cval[1]*m[1])%p[1] + (str[i]-'a'+1))%p[1];
			pre[i] = {cval[0], cval[1]};
		}
		
		pow_m[0][0] = 1;
		pow_m[1][0] = 1;
		for(int i = 1; i < n; i++){
			pow_m[0][i] = (pow_m[0][i-1] * m[0])%p[0];
			pow_m[1][i] = (pow_m[1][i-1] * m[1])%p[1];
		}
		
		auto calc = [&](int l, int r){
			
			vi ret = pre[r];
			
			if(l){
				ret[0] = (ret[0] - (pre[l-1][0] * pow_m[0][r-l+1])%p[0] + p[0])%p[0];
				ret[1] = (ret[1] - (pre[l-1][1] * pow_m[1][r-l+1])%p[1] + p[1])%p[1];
			}
			
			return ret;
		};
		
		set<pii> st;
		for(int i = 0; i+k-1 < n; i++){
			vi tmp = calc(i, i+k-1);
			st.insert({tmp[0], tmp[1]});
		}
		
		cout << st.size() << endl;
    }	
}
