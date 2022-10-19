// Problem: F. Kazaee
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int RCNT = 32;

struct FenwickTree {
	
    int n;
    vector<int> bit;  // binary indexed tree

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vi comp = vec;
    
    vector<array<int, 4>> queries(m);
    for(auto &[k, a, b, c] : queries){
    	cin >> k;
    	if(k==1){
    		cin >> a >> b;
    		a--;
    		comp.push_back(b);
    	}
    	else{
    		cin >> a >> b >> c;
    		a--, b--;
    	}
    }
    
    {
    	sort(comp.begin(), comp.end());
    	comp.resize(unique(comp.begin(), comp.end())-comp.begin());
    	for(auto &i : vec){
    		i = lower_bound(comp.begin(), comp.end(), i)-comp.begin();
    	}
    	for(auto &[k, a, b, c] : queries) if(k==1){
    		b = lower_bound(comp.begin(), comp.end(), b)-comp.begin();
    	}
    }
    
    vector<vector<char>> sub(RCNT, vector<char>(comp.size()));
    for(auto &v : sub){
    	for(auto &i : v){
    		i = rand(0, 1);
    	}
    }
    
    vector<FenwickTree> trees(RCNT, FenwickTree(n));
    
    for(int i = 0; i < RCNT; i++){
    	for(int j = 0; j < n; j++) if(sub[i][vec[j]]){
    		trees[i].add(j, 1);
    	}	
    }
    
    for(auto [k, a, b, c] : queries){
    	
    	if(k==1){
    		
    		int p = a;
    		int _old = vec[p];
    		int _new = b;
    		
    		for(int i = 0; i < RCNT; i++){
				trees[i].add(p, sub[i][_new]-sub[i][_old]);
    		}	
    		
    		vec[p] = _new;
    	}
    	else{
    		
    		int l = a;
    		int r = b;
    		int x = c;
    		
    		bool good = true;
    		for(int i = 0; i < RCNT; i++){
    			int cur_sum = trees[i].sum(l, r);
    			if(cur_sum%x != 0){
    				good = false;
    				break;
    			}
    		}
    		
    		cout << (good ? "YES" : "NO") << endl;
    	}
    }
}
