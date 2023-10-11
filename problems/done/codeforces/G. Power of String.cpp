// Problem: G. Power of String
// Contest: Codeforces - ACM International Collegiate Programming Contest, Amman Collegiate Programming Contest (2018)
// URL: https://codeforces.com/gym/101810/problem/G
// Memory Limit: 256 MB
// Time Limit: 15000 ms
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int K;
int cnt[26];
int mem[26][5050];
int vis[26][5050], vid;
int fr, to;

int calc(int c, int i){
	return (c*(c-1)/2) * ('a'+i);	
}

int go(int i, int k){
	
	if(i==fr || i==to){
		return go(i+1, k);
	}	
	
	if(i==26){
		int mn = min(k, cnt[fr]);
		int c_fr = cnt[fr] - mn;
		int c_to = cnt[to] + (K - (k-mn));
		return calc(c_fr, fr) + calc(c_to, to);
	}
	
	int &ret = mem[i][k];
	int &vis = ::vis[i][k];
	if(vis==vid) return ret;
	vis = vid;
	
	int mn = min(cnt[i], k);
	int st_path = calc(cnt[i], i) + go(i+1, k);
	int nd_path = calc(cnt[i]-mn, i) + go(i+1, k-mn);
	
	return ret = max(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n >> K;
		
		string str;
		cin >> str;
		
		for(int i = 0; i < 26; i++){
			cnt[i] = 0;
		}
		
		for(auto c : str){
			cnt[c-'a']++;
		}
		
		// for(auto c : cnt) cout << c << ' ' ; cout << endl;
		
		int ans = 0;
		for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++) if(i != j){
			
			vid++;
			fr = i;
			to = j;
			
			int cans = go(0, K);
			ans = max(ans, cans);
		}
		
		cout << ans << endl;
    }	
}
