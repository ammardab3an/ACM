// Problem: C. Double Lexicographically Minimum
// Contest: Codeforces - Codeforces Round #854 by cybercats (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1799/problem/C
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

		string str;
		cin >> str;
		
		vi cnt(26);
		for(auto c : str) cnt[c-'a']++;
		
		vpii tmp;
		for(int i = 0; i < 26; i++) if(cnt[i]){
			tmp.push_back({i, cnt[i]});
		}
		
		string ans, mid;
		string c, s0, s1;
		
		for(int i = 0; i < tmp.size(); i++){
			
			auto [v, f] = tmp[i];
			ans += string(f/2, 'a'+v);
			
			if(f%2==1){
				
				if(i+1==tmp.size()){
					mid = string(1, 'a'+v);
					if(!c.empty()) mid += c, c.clear();
					break;
				}
				else if(f > 2){
					
					if(i+2==tmp.size()){
						
						auto [nv, nf] = tmp[i+1];
						ans += string(nf/2, 'a'+nv);
						
						mid += string(nf%2, 'a'+nv);
						mid += string(1, 'a'+v);
						
					}
					else{
						
						for(int j = i+1; j < tmp.size(); j++){
							auto [v, f] = tmp[j];
							mid += string(f, 'a'+v);
						}
						
						if(c.empty()){
							mid += string(1, 'a'+v);
						}
						else{
							mid = string(1, 'a'+v) + mid + c;
							c.clear();	
						}
					}
					
					break;
				}
				else{
					
					if(c.empty()){
						
						
						if(i+3<=tmp.size() && tmp[i+1].second >= 2){
							
							// cout << char('a'+v) << endl;
							
							for(int j = i+1; j < tmp.size(); j++){
								auto [v, f] = tmp[j];
								mid += string(f, 'a'+v);
							}
							
							mid += string(1, 'a'+v);
							break;
						}
						else{						
							c = string(1, 'a'+v);
						}
					}
					else{
						
						s0 = string(1, 'a'+v);
						s1 = c;
						c.clear();
						
						for(int j = i+1; j < tmp.size(); j++){
							auto [v, f] = tmp[j];
							mid += string(f, 'a'+v);
						}
						
						break;
					}
				}
			}
		}
		
		if(!c.empty()){
			mid = c;
			c.clear();
		}
		
		// cout << mid << endl;
		
		// cout << ' ' << c << endl;
		
		string ans1 = ans;
		reverse(ans1.begin(), ans1.end());
		
		cout << ans+s0+mid+s1+ans1 << endl;
    }	
}
