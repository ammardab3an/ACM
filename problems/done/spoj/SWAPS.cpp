// Problem: Counting inversions
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/SWAPS/en/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}

const int NMAX = 250000 + 10;
const int AMAX = 50000 + 10;

struct FenwickTree{
    
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
    
    int n;
    cin >> n;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    int sqrt_n = ceil(sqrt(double(n)));
    int sz = ((n-1)/sqrt_n) + 1;
    
    vector<FenwickTree> trees(sz, FenwickTree(AMAX+1));
        
    int ans = 0;
    
    {
        FenwickTree pst(AMAX+1);
        
        for(int i = 0; i < n; i++){
            
            int ai = vec[i];
            ans += pst.sum(vec[i]+1, AMAX);
            trees[i/sqrt_n].add(ai, +1);
            pst.add(vec[i], +1);
        }
    }
    
    int m; cin >> m; while(m--){
        
        int idx, val;
        cin >> idx >> val;
        idx--;
        
        int s_idx = idx/sqrt_n;
        
        for(int j = (s_idx)-1; j >= 0; j--){
            if(vec[idx] <= val){
                ans -= trees[j].sum(vec[idx]+1, val);    
            }
            else{
                ans += trees[j].sum(val+1, vec[idx]);
            }
        }    
        
        for(int j = (s_idx)+1; j < sz; j++){
            if(vec[idx] <= val){
                ans += trees[j].sum(vec[idx], val-1);
            }
            else{
                ans -= trees[j].sum(val, vec[idx]-1);
            }
        }
        
        for(int i = idx+1; (i < n) && (s_idx == i/sqrt_n); i++){
            ans -= vec[i] < vec[idx];
            ans += vec[i] < val;
        }
        
        for(int i = idx-1; (i >= 0) && (s_idx == i/sqrt_n); i--){
            ans -= vec[i] > vec[idx];
            ans += vec[i] > val;
        }
        
        trees[s_idx].add(vec[idx], -1);
        trees[s_idx].add(val, +1);
        vec[idx] = val;
        
        cout << ans << endl;
    }
    
}
