// Problem: H. Holiday Wall Ornaments
// Contest: Codeforces - COMPFEST 13 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1575/H
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
 
const int NMAX = 505;

int n, m;
string str, pat;

int mem0[NMAX][2];
int pat_pre[NMAX];

int mem1[NMAX][NMAX][NMAX];

int nxtL(int i, char c){
	
	int &ret = mem0[i][c-'0'];
	if(ret+1) return ret;
	
	while(i && pat[i]!=c) i = pat_pre[i-1];
	if(pat[i]==c) i++;
	return ret = i;
}

void compute_prefix(){
	pat_pre[0] = 0;
	for(int i = 1; i < m; i++){
		pat_pre[i] = nxtL(pat_pre[i-1], pat[i]);
	}
}

int go(int i, int j, int rm){
	
	if(j==m) rm--;
	
	if(rm < 0){
		return INF;
	}
	
	if(i == n){
		return rm==0 ? 0 : INF;
	}
	
	int &ret = mem1[i][j][rm];
	if(ret+1) return ret;
	
	int st_path = (str[i] != '0') + go(i+1, nxtL(j, '0'), rm);
	int nd_path = (str[i] != '1') + go(i+1, nxtL(j, '1'), rm); 
	
	return ret = min(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    cin >> str >> pat;
    
    memset(mem0, -1, sizeof mem0);
    memset(mem1, -1, sizeof mem1);
    
    compute_prefix();
    
    for(int i = 0; i < n-m+2; i++){    
	    int cans = go(0, 0, i);
	    if(cans > n) cans = -1;
	    cout << cans << ' ';
    }
}
