// Problem: Mahesh and his lost array
// Contest: CodeChef - Practice
// URL: https://www.codechef.com/problems/ANUMLA
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
		
		vi vec(1 << n);
		for(auto &i : vec) cin >> i;
		
		if(n==1){
			cout << max(vec[0], vec[1]) << endl;
			continue;
		}
		
		multiset<int> mst;
		for(auto i : vec) mst.insert(i);
		
		vi taken;
		mst.erase(mst.begin());
		taken.push_back(*mst.begin());
		mst.erase(mst.begin());
		
		vi pst;
		pst.push_back(0);
		pst.push_back(taken.front());
		
		while(mst.size()){
			
			int cur = *mst.begin();
			
			for(auto i : pst){
				mst.erase(mst.find(i+cur));
			}
			for(int i = pst.size()-1; i >= 0; i--){
				pst.push_back(pst[i]+cur);
			}
			
			taken.push_back(cur);
		}
		
		for(auto i : taken) cout << i << ' '; cout << endl;
    }	
}
