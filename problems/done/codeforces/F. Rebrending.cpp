// Problem: F. Rebrending
// Contest: Codeforces - Codeforces Round 852 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1793/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 3e5 + 10;
const int BLOCK = 1200; // ceil(sqrt(double(NMAX)));

int val[NMAX];
int blk[NMAX/BLOCK + 1];

void update(int p, int x){
	val[p] = min(val[p], x);
	blk[p/BLOCK] = min(blk[p/BLOCK], x);	
}

int query(int l, int r){
	
	int ret = INF;
	
	int bl = l/BLOCK;
	int br = r/BLOCK;
	
	if(bl==br){
		for(int i = l; i <= r; i++){
			ret = min(ret, val[i]);
		}
		return ret;
	}	
	
	for(int i = l; i/BLOCK==bl; i++){
		ret = min(ret, val[i]);
	}
	
	for(int i = r; i/BLOCK==br; i--){
		ret = min(ret, val[i]);
	}
	
	for(int i = bl+1; i < br; i++){
		ret = min(ret, blk[i]);
	}
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    {
    	memset(val, INF, sizeof val);
    	memset(blk, INF, sizeof blk);
    }
    
    int n, m;
    cin >> n >> m;
    
    vi vec(n);
    for(auto &i : vec) cin >> i, --i;
    
    vi idx(n);
    for(int i = 0; i < n; i++){
    	idx[vec[i]] = i;
    }
    
    vpii queries(m);
    for(auto &[l, r] : queries){
    	cin >> l >> r;
    	--l, --r;
    }
    
    vi pos(m);
    iota(pos.begin(), pos.end(), 0);
    sort(pos.begin(), pos.end(), [&](int i, int j){
    	return queries[i].second < queries[j].second;
    });
    
    int k = 0;
    vi ans(m, INF);
    
    for(auto p : pos){
    	
    	auto [l, r] = queries[p];
    	
    	if(n/(r-l) > BLOCK){
    		vi tmp(vec.begin()+l, vec.begin()+r+1);
    		sort(tmp.begin(), tmp.end());
    		int cans = INF+1;
    		for(int i = 1; i < tmp.size(); i++){
    			cans = min(cans, tmp[i]-tmp[i-1]);
    		}
    		ans[p] = cans;
    		continue;
    	}
    	
    	while(k < n && k <= r){
    		
    		int x = vec[k];
    		for(int i = 1; i <= BLOCK && x+i < n; i++){
    			if(idx[x+i] < k){
    				update(idx[x+i], i);
    			}
    		}
    		
    		for(int i = 1; i <= BLOCK && x-i >= 0; i++){
    			if(idx[x-i] < k){
    				update(idx[x-i], i);
    			}
    		}
    		
    		k++;
    	}
    	
    	ans[p] = query(l, r);
    }
    
    for(auto i : ans){
    	cout << i << endl;
    }
}
