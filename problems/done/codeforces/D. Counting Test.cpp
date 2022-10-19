// Problem: D. Counting Test
// Contest: Codeforces - 2017 JUST Programming Contest 4.0
// URL: https://codeforces.com/gym/101532/problem/D
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
    
    int t; cin >> t; while(t--){

		int n, m;
		cin >> n >> m;
		
		string str;
		cin >> str;
		
		vector<vi> pre(n, vi(26));
		
		pre[0][str[0]-'a'] = 1;
		for(int i = 1; i < n; i++){
			for(int j = 0; j < 26; j++){
				pre[i][j] = pre[i-1][j];
			}
			pre[i][str[i]-'a']++;
		}
		
		while(m--){
			
			int l, r;
			cin >> l >> r;
			l--, r--;
			
			char c;
			cin >> c;
			
			if(r < n){
				cout << pre[r][c-'a']-pre[l][c-'a']+(str[l]==c) << endl;
				continue;	
			}
			
			int ans = 0;
			
			if(l%n!=0){
				ans += pre[n-1][c-'a']-pre[l%n][c-'a']+(str[l%n]==c);
				l += n-(l%n);
			}
			
			if(r%n!=n-1){
				ans += pre[r%n][c-'a'];
				r -= (r%n) + 1;
			}
			
			ans += pre[n-1][c-'a'] * (r-l+1)/n;
			
			cout << ans << endl;
		}
    }	
}
