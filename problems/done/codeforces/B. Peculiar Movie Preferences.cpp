// Problem: B. Peculiar Movie Preferences
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1628/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
		
		bool ans = false;
		
		for(auto &s : vec){
			
			cin >> s;
			
			int i = 0;
			int j = s.size()-1;
			bool good = true;
			while(i < j){
				if(s[i++] != s[j--]){
					good = false;
					break;
				}
			}
			ans |= good;
		}
		
		if(ans){
			cout << "YES" << endl;
			continue;
		}
		
		for(int k : {0, 1}){
			
			if(k){
				reverse(vec.begin(), vec.end());
			}
			
			set<string> pst;
			
			for(auto s : vec){
				
				// st_path
				string tmp = s;
				reverse(tmp.begin(), tmp.end());
				if(pst.find(tmp) != pst.end()){
					ans = true;
					break;
				}
				
				// nd_path
				if(s.size() == 3){
					
					string tmp(2, '0');
					
					if(k==0){
						tmp[0] = s[2];
						tmp[1] = s[1];
					}
					else{
						tmp[0] = s[1];
						tmp[1] = s[0];	
					}
					
					if(pst.find(tmp) != pst.end()){
						ans = true;
						break;
					}
				}
				
				pst.insert(s);
			}
		}
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
