// Problem: J - Lucky Common Subsequence
// Contest: Virtual Judge - String Processing Sheet Week 1
// URL: https://vjudge.net/contest/488773#problem/J
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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

string str_0, str_1, pat;
int mem[111][26];
int mem2[111][111][111];
int pat_pre[111];

int nxtL(int i, char c){
	int &ret = mem[i][c-'A'];
	if(ret+1) return ret;
	while(i && pat[i] != c) i = pat_pre[i-1];
	if(pat[i]==c) i++;
	return ret = i;
}

void computePrefix(){
	pat_pre[0] = 0;
	for(int i = 1; i < pat.size(); i++){
		pat_pre[i] = nxtL(pat_pre[i-1], pat[i]);
	}
}

int go(int i, int j, int k){
	
	if(k==pat.size()){
		return -INF;
	}
	if(i==str_0.size() || j==str_1.size()){
		return 0;
	}
	
	int &ret = mem2[i][j][k];
	if(ret+1) return ret;
	
	int st_path = go(i+1, j, k);
	int nd_path = go(i, j+1, k);
	int rd_path = 0;
	
	if(str_0[i]==str_1[j]){
		rd_path = 1 + go(i+1, j+1, nxtL(k, str_0[i]));
	}
	
	return ret = max({st_path, nd_path, rd_path});
}

string build(int i, int j, int k){
	
	assert(k < pat.size());
	
	if(i==str_0.size() || j==str_1.size()){
		return "";
	}
	
	int ans = go(i, j, k);
	
	if(go(i+1, j, k) == ans){
		return build(i+1, j, k);
	}	
	else if(go(i, j+1, k) == ans){
		return build(i, j+1, k);
	}
	else{
		return str_0[i] + build(i+1, j+1, nxtL(k, str_0[i]));
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> str_0 >> str_1 >> pat;
    
    memset(mem, -1, sizeof mem);
    memset(mem2, -1, sizeof mem2);
    
    computePrefix();
    
    if(go(0, 0, 0) <= 0){
    	cout << 0 << endl;
    }
    else{
    	// cout << go(0, 0, 0) << endl;
    	cout << build(0, 0, 0) << endl;
    }
}
