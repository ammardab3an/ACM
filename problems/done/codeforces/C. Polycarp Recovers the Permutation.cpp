// Problem: C. Polycarp Recovers the Permutation
// Contest: Codeforces - Codeforces Round #756 (Div. 3)
// URL: https://codeforces.com/contest/1611/problem/C
// Memory Limit: 256 MB
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
		
		deque<int> vec(n), tmp;
		for(auto &i : vec) cin >> i;
		
		tmp = vec;
		deque<int> dque;
		
		while(!vec.empty()){
			
			if(vec.front() <= vec.back()){
				dque.push_back(vec.back());
				vec.pop_back();
			}
			else{
				dque.push_front(vec.front());
				vec.pop_front();
			}
		}
		
		auto good = [](deque<int> a, deque<int> b) -> bool{
			
			deque<int> tmp;	
			while(a.size() > 1){
				if(a.front() <= a.back()){
					tmp.push_front(a.front());
					a.pop_front();
				}	
				else{
					tmp.push_back(a.back());
					a.pop_back();
				}
			}
			
			if(b.front() <= b.back()){
				b.pop_back();
			}
			else{
				b.pop_front();
			}
			
			// for(auto i : tmp) cout << i << ' ' ; cout << endl;
			// for(auto i : b) cout << i << ' ' ; cout << endl;
			
			return b==tmp;
		};
		
		if(good(dque, tmp)){
			for(auto i : dque) cout << i << ' '; cout << endl;
		}
		else{
			cout << -1 << endl;
		}
    }	
}
