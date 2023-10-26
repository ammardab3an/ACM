
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

map<int, vi> mp;
vi cur;
int sm = 0;
int pro = 1;

void go(int i){
	
	if(i > 41 || sm > 41){
		return;
	}
	
	if(sm==41){
		auto it = mp.find(pro);
		if(it==mp.end()) mp[pro] = cur;
		else if(it->second.size() > cur.size()) mp[pro] = cur;
		return;
	}	
	
	go(i+1);
	
	cur.push_back(i);
	sm += i;
	pro *= i;
	
	go(i);
	
	cur.pop_back();
	sm -= i;
	pro /= i;
}

int32_t main(){
    
    fastIO;
    
	go(1);
	// cout << mp.size() << endl;
	
	auto &ans = mp;
	
	int tt = 1;
    int t; cin >> t; while(t--){

		int p;
		cin >> p;
		
		cout << "Case #" << tt++ << ": ";
		
		if(ans[p].empty()){
			cout << -1 << endl;
		}
		else{
			cout << ans[p].size() << ' ';
			for(auto e : ans[p]) cout << e << ' '; cout << endl;
		}
    }	
}
