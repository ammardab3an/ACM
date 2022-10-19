// Problem: D. Lizard Era: Beginning
// Contest: Codeforces - Codeforces Round #325 (Div. 1)
// URL: https://codeforces.com/problemset/problem/585/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

vector<pair<array<int, 3>, int>> tmp;

void go(int i, int id, array<int, 3> sm, const vector<array<int, 3>> &vec){
	
	if(i==vec.size()){
		tmp.emplace_back(sm, id);
		return;
	}
	
	for(int j = 0; j < 3; j++){
		sm[j] += vec[i][j];
	}
	
	for(int j = 0; j < 3; j++){
		sm[j] -= vec[i][j];
		go(i+1, id*3+j, sm, vec);
		sm[j] += vec[i][j];
	}
}

vector<pair<array<int, 3>, int>> calc(const vector<array<int, 3>> &vec){
	tmp.clear();
	go(0, 0, (array<int, 3>){0, 0, 0}, vec);
	return tmp;
}

vector<string> get_s(int id, int n){
	
	vector<string> ret;
	
	for(int i = n-1; i >= 0; i--){
		
		int del = id%3;
		id /= 3;
		
		ret.push_back("");
		for(int j = 0; j < 3; j++) if(j != del){
			ret.back().push_back("LMW"[j]);
		}
	}
	
	reverse(ret.begin(), ret.end());
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    vector<array<int, 3>> vec(n, (array<int, 3>){0, 0, 0});
    for(auto &v : vec)
    for(auto &i : v) cin >> i;
    
    int m = (n+1)/2;
    
    vector<array<int, 3>> _a(vec.begin(), vec.begin()+m);
    vector<array<int, 3>> _b(vec.begin()+m, vec.end());
    
    auto a = calc(_a);
    auto b = calc(_b);
    tmp.clear();
    vec.clear();
    
    auto nb = b;
    
    for(auto &[v, id] : nb){	
    	int s = 0;
    	for(auto i : v){
    		s += i;
    	}
    	
    	for(auto &i : v){
    		i = s-3*i;
    	}
    }
    
    for(int i = 0; i < nb.size(); i++){
    	nb[i].second = i;
    }
    
    sort(nb.begin(), nb.end());
    
    int ans = -INFLL;
    pii ans_id = {-1, -1};
    
    for(int i = 0; i < a.size(); i++){
    	
    	auto [v, id] = a[i];
    	auto nv = v;
    	
    	int s = 0;
    	for(auto i : v){
    		s += i;
    	}
    	for(auto &i : nv){
    		i = 3*i-s;
    	}
    	
    	auto it = lower_bound(nb.begin(), nb.end(), (pair<array<int, 3>, int>){nv, -1});
    	
    	if(it!=nb.end() && (it->first==nv)){
    		
    		int s = v[0] + b[it->second].first[0];
    		
    		if(s > ans){
    			ans = s;
    			ans_id = {id, b[it->second].second};
    		}
    	}
    }
    
    if(ans_id.first==-1){
    	cout << "Impossible" << endl;
    }
    else{
    	for(auto s : get_s(ans_id.first, _a.size())){
    		cout << s << endl;
    	}
    	for(auto s : get_s(ans_id.second, _b.size())){
    		cout << s << endl;
    	}
    }
}
