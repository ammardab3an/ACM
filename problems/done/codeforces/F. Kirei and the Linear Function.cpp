// Problem: F. Kirei and the Linear Function
// Contest: Codeforces - Codeforces Round #820 (Div. 3)
// URL: https://codeforces.com/contest/1729/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
		
		string str;
		cin >> str;
		
		int n = str.size();
		
		int w;
		cin >> w;
		
		vi pre(n);
		pre[0] = str[0]-'0';
		for(int i = 1; i < n; i++){
			pre[i] = pre[i-1] + str[i]-'0';
		}
		
		vector<vi> tmp(9);
		
		for(int i = 0; i <= n-w; i++){
			int sm = (pre[i+w-1]-pre[i]+str[i]-'0') %9;
			tmp[sm].push_back(i);
		}
		
		vector<vpii> ans(9, vpii(9, (pii){INF, INF}));
		
		for(int a = 0; a < 9; a++)
		for(int b = 0; b < 9; b++)
		for(int c = 0; c < 9; c++)
		for(int d = 0; d < 9; d++){
			// a*b+c==d
			if((a*b+c)%9 == d){
				
				auto &cans = ans[b][d];
				
				if(a==c){
					if(tmp[a].size() >= 2){
						cans = min(cans, {tmp[a][0], tmp[a][1]});
					}
				}
				else{
					if(!tmp[a].empty() && !tmp[c].empty()){
						cans = min(cans, {tmp[a][0], tmp[c][0]});
					}
				}
			}
		}
		
		int q; cin >> q; while(q--){
			
			int l, r, b;
			cin >> l >> r >> b;
			l--, r--;
			
			int a = (pre[r]-pre[l]+str[l]-'0')%9;
			
			auto p = ans[a][b];
			
			if(p.first==INF){
				cout << "-1 -1" << endl;			
			}
			else{
				cout << p.first+1 << ' ' << p.second+1 << endl;			
			}
		}
    }	
}
