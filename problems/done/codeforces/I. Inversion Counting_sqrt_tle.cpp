// Problem: I. Inversion Counting
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/103940/problem/I
// Memory Limit: 256 MB
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

int n, k, q;
int arr[NMAX];
vi pos[NMAX];
bool is_small[NMAX];
bool is_large[NMAX];
int large_pos[NMAX];
int small_pos[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> k >> q;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    	arr[i]--;
    	pos[arr[i]].push_back(i);
    }
    
    vi small, large;
    for(int i = 0; i < k; i++){
    	if(pos[i].size() < BLOCK){
    		small_pos[i] = small.size();
    		small.push_back(i);
    		is_small[i] = true;
    	}
    	else{
    		large_pos[i] = large.size();
    		large.push_back(i);
    		is_large[i] = true;
    	}
    }
    
    vector<vi> vec(large.size(), vi(large.size()));
    vector<vi> foo(small.size(), vi(large.size()));
    
    FenwickTree tree(k+1);
    vi frq(k+1);
    
    int tot = 0;
    for(int i = 0; i < n; i++){
    	
    	int ai = arr[i];
    	tot += tree.sum(ai+1, k);
    	tree.add(ai, 1);
    	frq[ai]++;
    	
    	if(is_large[ai]){
    		for(auto e : large) if(ai < e){
    			vec[large_pos[ai]][large_pos[e]] += frq[e];
    		}
    	}
    	else{
    		for(auto e : large) if(ai < e){
    			foo[small_pos[ai]][large_pos[e]] += frq[e];				
    		}
    	}
    }
    
	frq = vi(k+1, 0);
	for(int i = n-1; i >= 0; i--){
		int ai = arr[i];
		frq[ai]++;
		if(is_small[ai]){
			for(auto e : large) if(ai > e){
				foo[small_pos[ai]][large_pos[e]] += frq[e];				
			}
		}
	}
    
    vi conv(k);
    iota(conv.begin(), conv.end(), 0);
    
    while(q--){
    	
    	int p;
    	cin >> p;
    	p--;
    	
    	int a = conv[p];
    	int b = conv[p+1];
    	swap(conv[p], conv[p+1]);
    	
    	if(is_large[a] && is_large[b]){
    		if(a > b) swap(a, b);
    		int &cur = vec[large_pos[a]][large_pos[b]];
    		tot -= cur;	
    		cur = int(pos[a].size())*int(pos[b].size()) - cur;
    		tot += cur;
    	}
    	else if(is_large[a] || is_large[b]){
    		if(is_small[b]) swap(a, b);
    		int &cur = foo[small_pos[a]][large_pos[b]];
    		tot -= cur;	
    		cur = int(pos[a].size())*int(pos[b].size()) - cur;
    		tot += cur;
    	}
    	else{
    		int cur = 0;
    		for(auto i : pos[a]){
    			cur += lower_bound(pos[b].begin(), pos[b].end(), i)-pos[b].begin();
    		}
    		tot -= cur;
    		cur = int(pos[a].size())*int(pos[b].size()) - cur;
    		tot += cur;
    	}
    	
    	cout << tot << endl;
    }
}
