// Problem: D. Dirty Deeds Done Dirt Cheap
// Contest: Codeforces - Codeforces Global Round 3
// URL: https://codeforces.com/contest/1148/problem/D
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
    
    int n;
    cin >> n;
    
    vpii tmp_0, tmp_1;
    vi pos_0, pos_1;
    
    for(int i = 0; i < n; i++){
    	
    	int a, b;
    	cin >> a >> b;
    	
    	if(a==b) continue;
    	
    	if(a < b){
    		tmp_0.push_back({a, b});
    		pos_0.push_back(i);
    	}
    	else{
    		tmp_1.push_back({a, b});
    		pos_1.push_back(i);
    	}
    }
    
    if(tmp_0.size() > tmp_1.size()){
    	
    	vi pos(tmp_0.size());
    	iota(pos.begin(), pos.end(), 0);
    	sort(pos.begin(), pos.end(), [&](int i, int j){
    		return tmp_0[i].second > tmp_0[j].second;
    	});
    	
    	cout << tmp_0.size() << endl;
    	for(auto i : pos) cout << pos_0[i]+1 << ' '; cout << endl;
    }
    else{
    	
    	vi pos(tmp_1.size());
    	iota(pos.begin(), pos.end(), 0);
    	sort(pos.begin(), pos.end(), [&](int i, int j){
    		return tmp_1[i].first < tmp_1[j].first;
    	});
    	
    	cout << tmp_1.size() << endl;
    	for(auto i : pos) cout << pos_1[i]+1 << ' '; cout << endl;
    }
    
}
