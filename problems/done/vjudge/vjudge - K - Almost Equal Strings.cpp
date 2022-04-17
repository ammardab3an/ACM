// Problem: K - Almost Equal Strings
// Contest: Virtual Judge - String Processing Sheet Week 1
// URL: https://vjudge.net/contest/488773#problem/K
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

struct hash_struct{
	
	int n;
	string str;
	
	vi p, m;
	vector<vi> pre;
	vector<vi> pow_m;
	
	hash_struct(){}
	
	hash_struct(string _str){
		str = _str;
		n = str.size();
		init();
		build();
	}
	
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
		
		pow_m.resize(n, vi(2));
		
		pow_m[0][0] = pow_m[0][1] = 1;
		for(int i = 1; i < n; i++)
		for(int j = 0; j < 2; j++){
			pow_m[i][j] = (pow_m[i-1][j] *1ll* m[j])%p[j];
		}
	}
	
	void build(){
		
		pre.resize(n);
		
		vi cval(2);
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
	
	bool equal(vi a, vi b){
		return a[0]==b[0] && a[1]==b[1];
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
    
    
    int n;
    cin >> n;
    
    string str;
    cin >> str;
    
    hash_struct str_hs(str);
    
    int q; cin >> q; while(q--){
    	
    	vi a(2), b(2);
    	cin >> a[0] >> a[1] >> b[0] >> b[1];
    	a[0]--, a[1]--, b[0]--, b[1]--;
    	
    	if(a[1]-a[0]+1 != b[1]-b[0]+1){
    		cout << "DIFFERENT" << endl;
    		continue;
    	}
    	
    	int len = a[1]-a[0]+1;
    	
		int ans = 0;
		
    	{
    		int l = 1;
    		int r = len;
    			
    		while(l <= r){
    			
    			int mid = (l+r)/2;
    			
    			vi q_a = str_hs.query(a[0], a[0]+mid-1);
    			vi q_b = str_hs.query(b[0], b[0]+mid-1);
    			
    			if(str_hs.equal(q_a, q_b)){
    				ans = mid;
    				l = mid+1;	
    			}
    			else{
    				r = mid-1;
    			}
    		}
    	}
    	
    	if(ans == len || ans == len-1){
    		cout << "SIMILAR" << endl;
    	}
    	else{
    		
    		vi q_a = str_hs.query(a[0]+ans+1, a[1]);
    		vi q_b = str_hs.query(b[0]+ans+1, b[1]);
    		if(str_hs.equal(q_a, q_b)){
    			cout << "SIMILAR" << endl;
    		}
    		else{
    			cout << "DIFFERENT" << endl;
    		}	
    	}
    }
}
