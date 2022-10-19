// Problem: G. Cut Substrings
// Contest: Codeforces - Codeforces Round #820 (Div. 3)
// URL: https://codeforces.com/contest/1729/problem/G
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
 
const int NMAX = 500 + 10;

int n, m;
string str, pat;
int mem[NMAX][26];
int vis[NMAX][26], vid;
int pat_pre[NMAX];
int match[NMAX];

int nxtL(int i, char c){
	
	int &ret = mem[i][c-'a'];
	if(vis[i][c-'a']==vid) return ret;
	vis[i][c-'a'] = vid;
	
	while(i && pat[i] != c) i = pat_pre[i-1];
	if(pat[i] == c) i++;
	
	return ret = i;
}

void computePrefix(){
	pat_pre[0] = 0;
	for(int i = 1; i < pat.size(); i++){
		pat_pre[i] = nxtL(pat_pre[i-1], pat[i]);
	}
}

int memo[NMAX][NMAX];
int viso[NMAX][NMAX];

int go(int i, int j){
	
	if(j==m){
		return INF;
	}
	
	if(i >= n){
		return 0;
	}
	
	int &ret = memo[i][j];
	if(viso[i][j]==vid) return ret;
	viso[i][j] = vid;
	
	int st_path = match[i]!=vid ? INF : 1 + go(i+m, 0);
	int nd_path = go(i+1, nxtL(j, str[i]));
	
	return ret = min(st_path, nd_path);
}

int memc[NMAX][NMAX];
int visc[NMAX][NMAX];

int calc(int i, int j){
	
	if(i >= n){
		return 1;
	}	
	
	int &ret = memc[i][j];
	if(visc[i][j]==vid) return ret;
	visc[i][j] = vid;
	
	int ans = go(i, j);
	int st_path = match[i]!=vid ? INF : 1 + go(i+m, 0);
	int nd_path = go(i+1, nxtL(j, str[i]));
	
	ret = 0;
	if(ans==st_path){
		ret = add(ret, calc(i+m, 0));
	}
	if(ans==nd_path){
		ret = add(ret, calc(i+1, nxtL(j, str[i])));
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
    
    int t; cin >> t; while(t--){

		cin >> str >> pat;
		n = str.size();
		m = pat.size();
		
		vid++;
		
		computePrefix();
		
		{
			int j = 0;
			for(int i = 0; i < n; i++){
				j = nxtL(j, str[i]);
				if(j==m) match[i-m+1] = vid;
			}	
		}
		
		int ans = go(0, 0);
		int cnt = calc(0, 0);
		
		cout << ans << ' ' << cnt << endl;		
    }	
}
