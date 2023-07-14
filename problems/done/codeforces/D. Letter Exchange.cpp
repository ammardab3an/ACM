// Problem: D. Letter Exchange
// Contest: Codeforces - Codeforces Round #850 (Div. 2, based on VK Cup 2022 - Final Round)
// URL: https://codeforces.com/contest/1786/problem/D
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
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vector<string> vec(n);
		for(auto &s : vec){
			cin >> s;
			sort(s.begin(), s.end());
		}
		
		map<pair<char, char>, vi> mp;
		
		for(int i = 0; i < n; i++){
			
			string s = vec[i];
			
			if(s[0] != s[1] && s[0] != s[2] && s[1] != s[2]){
				continue;
			}
			else if(s[0]==s[1] && s[0]==s[2]){
				if(s[0] != 'w') mp[{s[0], 'w'}].push_back(i);
				if(s[0] != 'i') mp[{s[0], 'i'}].push_back(i);
				if(s[0] != 'n') mp[{s[0], 'n'}].push_back(i);
			}
			else if(s[0]==s[1]){
				if(s[0] != 'w' && s[2] != 'w') mp[{s[0], 'w'}].push_back(i);
				if(s[0] != 'i' && s[2] != 'i') mp[{s[0], 'i'}].push_back(i);
				if(s[0] != 'n' && s[2] != 'n') mp[{s[0], 'n'}].push_back(i);
			}
			else if(s[1]==s[2]){
				if(s[0] != 'w' && s[2] != 'w') mp[{s[1], 'w'}].push_back(i);
				if(s[0] != 'i' && s[2] != 'i') mp[{s[1], 'i'}].push_back(i);
				if(s[0] != 'n' && s[2] != 'n') mp[{s[1], 'n'}].push_back(i);
			}
			else{
				assert(false);
			}
		}
		
		vector<pair<pair<int, char>, pair<int, char>>> ans;
		
		for(int i = 0; i < 3; i++)
		for(int j = i+1; j < 3; j++){
			
			char c0 = "win"[i];
			char c1 = "win"[j];
			
			vi &v0 = mp[{c0, c1}];
			vi &v1 = mp[{c1, c0}];
			
			while(!v0.empty() && !v1.empty()){
				ans.push_back({{v0.back(), c0}, {v1.back(), c1}});
				v0.pop_back();
				v1.pop_back();
			}
		}
		
		
		vi tmp = {0, 1, 2};
		
		do{
			
			char c0 = "win"[tmp[0]];
			char c1 = "win"[tmp[1]];
			char c2 = "win"[tmp[2]];
			
			vi &v0 = mp[{c0, c1}];
			vi &v1 = mp[{c1, c2}];
			vi &v2 = mp[{c2, c0}];
			
			// cout << c0 << ' ' << c1 << ' ' << c2 << endl;
			
			while(!v0.empty() && !v1.empty() && !v2.empty()){
				ans.push_back({{v0.back(), c0}, {v2.back(), c2}});
				ans.push_back({{v0.back(), c2}, {v1.back(), c1}});
				v0.pop_back();
				v1.pop_back();
				v2.pop_back();
			}
			
		} while(next_permutation(tmp.begin(), tmp.end()));
		
		// for(auto [a, b] : mp){
			// cout << a.first << ' ' << a.second << ' ' << b.size() << endl;	
		// }
		// return 0;
		
		for(auto &p : mp){
			assert(p.second.empty());
		}
		
		cout << ans.size() << endl;
		for(auto [a, b] : ans){
			cout << a.first+1 << ' ' << a.second << ' ' << b.first+1 << ' ' << b.second << endl;
		}
		
		// cout << flush;
    }	
}

/*

i w 1
n i 1
w n 1

*/