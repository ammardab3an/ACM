// Problem: D. Problem with Random Tests
// Contest: Codeforces - Educational Codeforces Round 137 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1743/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
    
    string str;
    cin >> str;
	
	vi cur(n);
	iota(cur.begin(), cur.end(), -n);
	
	int p = 0;
	while(p < n && cur.size() > 1){
		
		vi val(cur.size());
		for(int e = 0; e < cur.size(); e++){
			
			int j = cur[e];
			
			int cnt = 0;
			for(int k = 0; p+k < n; k++){
				bool b0 = str[p+k]-'0';
				bool b1 = p+j+k >= 0 ? str[p+j+k]-'0' : 0;
				
				if(b0||b1){
					cnt++;
				}
				else{
					break;
				}
			}
			
			val[e] = cnt;
		}	
		
		int mx = *max_element(val.begin(), val.end());
		
		vi ncur;
		for(int i = 0; i < cur.size(); i++){
			if(val[i]==mx){
				ncur.push_back(cur[i]);
			}
		}
		
		swap(cur, ncur);
		
		p += mx+1;
	}
	
	string ans;
	
	{
		int i = 0;
		int j = cur[0];
		
		for(int i = 0; i < n; i++){
			bool b0 = str[i]-'0';
			bool b1 = (i+j)>=0 ? str[i+j]-'0' : 0;
			ans.push_back('0' + (b0||b1));
		}
	}
	
	{
		int i = 0;
		while(i < ans.size() && ans[i]=='0'){
			i++;
		}
		i = min(i, (int)ans.size()-1);
		ans = ans.substr(i);
	}
	
	cout << ans << endl;
}
