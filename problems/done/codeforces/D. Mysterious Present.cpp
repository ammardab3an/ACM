// Problem: D. Mysterious Present
// Contest: Codeforces - Codeforces Beta Round 4 (Div. 2 Only)
// URL: https://codeforces.com/contest/4/problem/D
// Memory Limit: 64 MB
// Time Limit: 1000 ms
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

int inv(int x){
	return pow_exp(x, MOD-2);
}

const int AMAX = 1e6 + 10;

struct FenwickTreeMax {
	
    int n;
    vector<pii> bit;
    
    FenwickTreeMax(int n) {
        this->n = n;
        bit.assign(n, (pii){-1, -1});
    }

    pii getmax(int r) {
        pii ret = {-1, -1};
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, pii val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};

int32_t main(){
    
    fastIO;
    
    int n, w, h;
    cin >> n >> w >> h;
    
    vpii vec(n);
    for(auto &[a, b] : vec){
    	cin >> a >> b;
    	b *= -1;
    }
    
    vi pos(n);
    iota(pos.begin(), pos.end(), 0);
    sort(pos.begin(), pos.end(), [&](int i, int j){
    	return vec[i] < vec[j];
    });
    
    pii ans = {-1, -1};
    FenwickTreeMax bit(AMAX);
    vi par(n);
    
    for(auto p : pos){
    	auto [a, b] = vec[p];
    	b *= -1;
    	if(a <= w || b <= h) continue;
    	pii cans = bit.getmax(b-1);
    	par[p] = cans.second;
    	cans.first++;
    	cans.second = p;
    	ans = max(ans, cans);
    	bit.update(b, cans);
    }
    
    vi tmp;
    int cur = ans.second;
    while(cur != -1){
    	tmp.push_back(cur);
    	cur = par[cur];
    }
    
    cout << tmp.size() << endl;
    reverse(tmp.begin(), tmp.end());
    for(auto e : tmp) cout << e+1 << ' '; cout << endl;
}
