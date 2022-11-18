// H. Prehistoric Programs
// https://judge.icpc.global/team/problems/23/text
 
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
    
    vector<string> vec(n);
    for(auto &s : vec) cin >> s;
    
    vpii tmp(n);
    vector<iii> comp(n);
    
    for(int i = 0; i < n; i++){
    	
    	auto &s = vec[i];
    	int sm = s[0]=='(' ? +1 : -1;
    	int mn = sm;
    	for(int j = 1; j < s.size(); j++){
    		sm += s[j]=='(' ? +1 : -1;
    		mn = min(mn, sm);
    	}
    	
    	if(sm==mn){
    		if(sm >= 0){
    			comp[i] = {0, {sm, 0}};
    		}
    		else{
    			comp[i] = {3, {-sm, 0}};
    		}
    	}
    	else{
    		if(sm >= 0){
    			comp[i] = {1, {-mn, -sm}};
    		}
    		else{			
	    		comp[i] = {2, {mn, -sm}};	
    		}
    	}
    	
    	tmp[i] = {mn, sm};
    }
    
    vi pos(n);
    iota(pos.begin(), pos.end(), 0);
    sort(pos.begin(), pos.end(), [&](int i, int j){
    	return comp[i] < comp[j];
    });
    
    vi ans;
    int tot = 0;
    bool bad = false;
    
    for(auto p : pos){
    	
    	if(tot+tmp[p].first < 0){
    		bad = true;
    		break;
    	}
    	
    	tot += tmp[p].second;
    	ans.push_back(p);
    }
    
    if(bad || tot){
    	cout << "impossible" << endl;
    }
    else{
    	for(auto i : ans){
    		cout << i+1 << endl;
    	}
    }
}
