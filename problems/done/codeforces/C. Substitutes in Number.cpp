// Problem: C. Substitutes in Number
// Contest: Codeforces - Codeforces Round #265 (Div. 1)
// URL: https://codeforces.com/problemset/problem/464/C
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

int q;
pair<int, string> arr[NMAX];
int nxt[NMAX][10];

pii mem[NMAX];
bool vis[NMAX];

pii go(int i, int d){
	
	if(i==q){
		return {d, 1};
	}
	
	pii &ret = mem[i];
	if(vis[i]) return ret;
	vis[i] = true;
	
	int val = 0;
	int len = 0;
	
	for(auto c : arr[i].second){
		
		int j = nxt[i+1][c-'0'];
		pii tmp = go(j, c-'0');
		
		int cur_val = tmp.first;
		int cur_len = tmp.second;
		
		val = mul(val, pow_exp(10, cur_len));
		val = add(val, cur_val);
		len = (len+cur_len)%(MOD-1);
	}
	
	return ret = {val, len};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    string str;
    cin >> str;
    
    cin >> q; 
    cin.ignore();
    
    q++;
    arr[0].first = 0;
    arr[0].second = str;
    
    for(int i = 1; i < q; i++){
    	
    	string ln;
    	getline(cin, ln);
    	
    	int d = ln[0]-'0';
    	string to = ln.substr(3);
    	
    	arr[i].first = d;
    	arr[i].second = to;
    }
    
    for(int i = 0; i < 10; i++){
    	nxt[q][i] = q;
    }
    
    for(int i = q-1; i >= 0; i--){
    	
    	for(int j = 0; j < 10; j++){
    		nxt[i][j] = nxt[i+1][j];
    	}
    	
    	if(i != 0){		
	    	nxt[i][arr[i].first] = i;
    	}
    }
    
    pii ans = go(0, 0);
    cout << ans.first << endl;
}
