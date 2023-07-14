// Problem: F1. Survival of the Weakest (easy version)
// Contest: Codeforces - Codeforces Round 862 (Div. 2)
// URL: https://codeforces.com/contest/1805/problem/F1
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

const int BLK = 55;

struct bset{
	
	int mx;
	int blks[BLK];
	
	bset(){
		mx = 0;
		memset(blks, 0, sizeof blks);
	}
	
	bset(int x) : bset(){
		assert(x < (1ll<<61));
		blks[0] = x;
	}
	
	bset operator + (const bset &other){
		
		bset ret;
		
		int c = 0;
		int r = max(mx, other.mx)+1;
		for(int i = 0; i <= r; i++){
			int cur = blks[i] + other.blks[i] + c;
			if(cur & (1ll<<61)) cur ^= 1ll<<61, c = 1;
			else c = 0;
			ret.blks[i] = cur;
		}
		
		ret.mx = r - !ret.blks[r];
		return ret;
	}
	
	bool operator < (const bset &other){
		
		if(mx != other.mx){
			return mx < other.mx;
		}
		
		for(int i = mx; i >= 0; i--){
			if(blks[i] != other.blks[i]){
				return blks[i] < other.blks[i];
			}
		}	
		
		return false;
	}
	
	int calc_val(){
		
		int ret = 0;
		for(int i = BLK-1; i >= 0; i--){
			ret = mul(ret, 1ll<<61);
			ret = add(ret, blks[i]);
		}
		
		return ret;
	}	
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
	
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    sort(vec.begin(), vec.end());
    
    vector<bset> tmp(n);
    for(int i = 0; i < n; i++){
    	tmp[i] = bset(vec[i]);
    } 
    
    while(tmp.size() > 1){
    	
    	vi pos(tmp.size()-1);
    	iota(pos.begin(), pos.end(), 1);
    	
    	vector<bset> cur(pos.size());
    	for(int i = 0; i < cur.size(); i++){
    		cur[i] = tmp[i] + tmp[pos[i]];
    	}
    	
    	auto cmp = [&](int i, int j){
    		return cur[i] < cur[j];	
    	};
    	
    	multiset<int, decltype(cmp)> st(cmp);
    	
    	for(int i = 0; i < cur.size(); i++){
    		st.insert(i);
    	}
    	
    	vector<bset> ntmp;
    	while(ntmp.size()+1 < tmp.size()){
    		
    		int p = *st.begin();
    		st.erase(st.begin());
    		
    		ntmp.push_back(cur[p]);
    		
    		if(++pos[p] < tmp.size()){
	    		cur[p] = tmp[p] + tmp[pos[p]];
	    		st.insert(p);
    		}
    	}
    	
    	tmp = ntmp;
    }
    
    assert(tmp.size()==1);
    cout << tmp[0].calc_val() << endl;
}
