// Problem: E - Least Elements
// Contest: AtCoder - AtCoder Beginner Contest 281
// URL: https://atcoder.jp/contests/abc281/tasks/abc281_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

struct DS{
	
	int k;
	DS(int k) : k(k){}
	
	int sm_taken = 0;
	multiset<int> st0, st1;
	
	int get_sum_kst(){
		return sm_taken;
	}
	
	void fix(){
		
		if(st1.empty()){
			return;
		}
		
		if(st0.size() < k){
			
			while(!st1.empty() && st0.size() < k){
				sm_taken += *st1.begin();
				st0.insert(*st1.begin());
				st1.erase(st1.begin());
			}	
			
			return;
		}
		
		int mx0 = *st0.rbegin();
		int mn1 = *st1.begin();
		
		if(mn1 < mx0){
			
			st0.erase(st0.find(mx0));
			st1.erase(st1.begin());
			
			st0.insert(mn1);
			st1.insert(mx0);
			
			sm_taken += mn1 - mx0;
		}
	}
	
	void insert(int x){
		
		if(st0.size() < k){
			st0.insert(x);
			sm_taken += x;
		}
		else{
			st1.insert(x);
			fix();
		}
	}	
	
	void erase(int x){
		
		auto it1 = st1.find(x);
		if(it1 != st1.end()){
			st1.erase(it1);
			return;
		}
		
		auto it0 = st0.find(x);
		assert(it0 != st0.end());
		st0.erase(it0);
		sm_taken -= x;
		fix();
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    DS ds(k);
    
    for(int i = 0; i < m-1; i++){
    	ds.insert(vec[i]);
    }
    
    for(int i = m-1; i < n; i++){
    	
    	if(i-m >= 0){
    		ds.erase(vec[i-m]);
    	}
    	
    	ds.insert(vec[i]);
    	
    	cout << ds.get_sum_kst() << ' ';
    }
    
    cout << endl;
}
