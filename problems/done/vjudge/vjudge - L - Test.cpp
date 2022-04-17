// Problem: L - Test
// Contest: Virtual Judge - String Processing Sheet Week 1
// URL: https://vjudge.net/contest/488773#problem/L
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
 
const int NMAX = 3e5 + 10;

vi p, m;
int pow_m[NMAX][2];

bool is_prime(int x){
	for(ll i = 2; i*i <= x; i++) if(x%i==0){
		return false;
	}
	return true;
}

void init(){	
	p = {rand(1e5, 2e5), rand(1e9, 2e9)};
	m = {rand(30, 50), rand(50, 100)};
	for(int j = 0; j < 2; j++){
		while(!is_prime(p[j])) p[j]++;
		while(!is_prime(m[j])) m[j]++;
	}
	pow_m[0][0] = pow_m[0][1] = 1;
	for(int i = 1; i < NMAX; i++)
	for(int j = 0; j < 2; j++){
		pow_m[i][j] = (pow_m[i-1][j] *1ll* m[j])%p[j];
	}
}

struct hash_struct{
	
	int n;
	string str;
	
	vector<vi> pre;
	
	hash_struct(){}
	
	hash_struct(string _str){
		str = _str;
		n = str.size();
		build();
	}
	
	void build(){
		
		vi cval(2);
		pre.resize(n);
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 2; j++){
				cval[j] = ((cval[j] *1ll* m[j])%p[j] + (str[i]-'a'+1))%p[j];
			}
			pre[i] = cval;
		}
	}
	
	vi query(int l, int r){
		vi ret = pre[r];
		if(l) for(int j = 0; j < 2; j++){
			ret[j] = (ret[j] - (pre[l-1][j] *1ll* pow_m[r-l+1][j])%p[j] + p[j])%p[j];
		}
		return ret;
	}
};

int32_t main(){
    
    fastIO;
    // #undef endl
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
    // freopen("name.in", "r", stdin);
    
    init();
	
    vector<string> vec(3);
    vector<hash_struct> tmp_hs(3);
    
    for(int i = 0; i < 3; i++){
    	cin >> vec[i];
    	tmp_hs[i] = hash_struct(vec[i]);
    }
    
    vi pos = {0, 1, 2};
    
    int ans = INF;
    
    do{
    	
    	string res;
    	
    	for(int p : pos){
    		
    		string &str = vec[p];
    		hash_struct &str_hs = tmp_hs[p];
    		
    		hash_struct res_hs(res);
    		
    		if(str.size() <= res.size()){
    			
    			bool good = false;
    			
    			vi q_0 = str_hs.query(0, str.size()-1);
	    		for(int i = 0; i+str.size()-1 < res.size(); i++){
	    			vi q_1 = res_hs.query(i, i+str.size()-1);
	    			if(q_0==q_1){
	    				good = true;
	    				break;
	    			}
	    		}
	    		
	    		if(good) continue;
    		}		
    		
    		int mx = 0;
    		int mn = min(res.size(), str.size());
    		
    		for(int l = mn; l >= 1; l--){
    			
    			vi q_0 = str_hs.query(0, l-1);
    			vi q_1 = res_hs.query(((int)res.size()-1)-(l-1), (int)res.size()-1);
    			
    			if(q_0==q_1){
    				mx = l;
    				break;
    			}
    		}
    		
    		for(int k = mx; k < str.size(); k++){
    			res.push_back(str[k]);
    		}
    	}
    	
    	ans = min(ans, (int)res.size());
    	
    } while(next_permutation(pos.begin(), pos.end()));
    
    cout << ans << endl;
}

	  	 	   	   	  	 		 	 		     	