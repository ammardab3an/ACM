// Problem: C. Complementary XOR
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1750/problem/C
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

		int n;
		cin >> n;
		
		vector<string> str(2);
		for(auto &s : str) cin >> s;
		
		vpii ans;
		
		bool found0 = false; // same
		bool found1 = false;
		
		for(int i = 0; i < n; i++){
			if(str[0][i]==str[1][i]){
				found0 = true;
			}
			else{
				found1 = true;
			}
		}	
		
		if(found0 && found1){
			cout << "NO" << endl;
			continue;
		}
		
		if(found1){
			found0 = true;
			found1 = false;
			ans.push_back({0, n-1})	;
			for(auto &c : str[0]) c = '0'+'1'-c;
		}
		
		if(found0){
			
			int cnt = 0;
			for(int i = 0; i < n; i++) if(str[0][i]=='1'){
				cnt++;
			}	
			
			if(cnt%2==0){
				for(int i = 0; i < n; i++) if(str[0][i]=='1'){
					ans.push_back({i, i});
					str[0][i] = '0'+'1'-str[0][i];
					str[1][i] = '0'+'1'-str[1][i];
				}
			}
			else if((n-cnt)%2==0){
				
				ans.push_back({0, 0});
				ans.push_back({1, n-1});
				for(auto &c : str[0]) c = '0'+'1'-c;
				for(auto &c : str[1]) c = '0'+'1'-c;
				
				for(int i = 0; i < n; i++) if(str[0][i]=='1'){
					ans.push_back({i, i});
					str[0][i] = '0'+'1'-str[0][i];
					str[1][i] = '0'+'1'-str[1][i];
				}
			}
			else{
				
				ans.push_back({0, n-1});
				for(auto &c : str[0]) c = '0'+'1'-c;
				
				for(int i = 0; i < n; i++) if(str[1][i]=='0'){
					ans.push_back({i, i});
					str[0][i] = '0'+'1'-str[0][i];
					str[1][i] = '0'+'1'-str[1][i];
				}
				for(int i = 0; i < n; i++){
					str[1][i] = '0'+'1'-str[1][i];		
				}
			}
		}
		
		// for(auto s : str) cout << s << endl;
		
		cout << "YES" << endl;
		cout << ans.size() << endl;
		for(auto [i, j] : ans){
			cout << i+1 << ' ' << j+1 << endl;
		}
    }	
}
