// Problem: D. Linguistics
// Contest: Codeforces - Codeforces Round #794 (Div. 2)
// URL: https://codeforces.com/contest/1686/problem/D
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		string str;
		cin >> str;
		
		vi cnt(2);
		for(auto c : str) cnt[c-'A']++;
		
		if((a+c+d != cnt[0]) || (b+c+d != cnt[1])){
			cout << "NO" << endl;
			continue;
		}
		
		vector<vi> tmp(3);
		
		char lst = str[0];
		char lst_head = str[0];
		int lst_cnt = 0;
		
		for(auto c : str){
			
			if(c!=lst){
				lst_cnt++;
			}
			else{
				
				if(lst_cnt){
					
					if(lst_cnt%2==1){
						tmp[0].push_back(lst_cnt);
					}
					else{
						tmp[(lst_head-'A')+1].push_back(lst_cnt);
					}
				}
					
				lst = lst_head = c;
				lst_cnt = 1;
			}
			
			lst = c;
		}
		
		if(lst_cnt%2==1){
			tmp[0].push_back(lst_cnt);
		}
		else{
			tmp[(lst_head-'A')+1].push_back(lst_cnt);
		}
		
		auto calc = [](int &x, vi &a, vi &b, vi &c){
			
			sort(a.begin(), a.end(), greater<int>());
			sort(b.begin(), b.end());
			sort(c.begin(), c.end());
			
			while(x && !a.empty()){
				int k = min(x, a.back()/2);
				x -= k;
				a.back() -= k*2;
				if(a.back()==0) a.pop_back();
			}
			
			while(x && !b.empty()){
				int k = min(x, b.back()/2);
				x -= k;
				b.back() -= k*2;
				if(b.back()<=1) b.pop_back();
			}
			
			while(x && !c.empty()){
				if(c.back() < 2) break;
				int k = min(x, (c.back()-2)/2);
				x -= k;
				c.back() -= k*2 + 2;
				if(c.back()==0) c.pop_back();
			}
		};
		
		calc(c, tmp[1], tmp[0], tmp[2]);			
		calc(d, tmp[2], tmp[0], tmp[1]);
		
		cout << ((!c && !d) ? "YES" : "NO") << endl;
		
    }	
}
