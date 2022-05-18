// Problem: F. Desktop Rearrangement
// Contest: Codeforces - Codeforces Round #786 (Div. 3)
// URL: https://codeforces.com/contest/1674/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    vector<int> bit;  // binary indexed tree
    int n;

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
    
    // fastIO;
    #undef endl
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<string> grid(n);
    vector<FenwickTree> trees(m, FenwickTree(n));
    FenwickTree hlp(m);
    
    int cnt = 0;
    
    for(int i = 0; i < n; i++){
    	
    	string str;
    	cin >> str;
    	
    	grid[i] = str;
    	
    	int ccnt = 0;
    	for(int j = 0; j < m; j++) if(str[j]=='*'){
    		cnt++;
    		ccnt++;
    		trees[j].add(i, 1);
    	}
    }
	
	for(int i = 0; i < m; i++){
		hlp.add(i, trees[i].sum(0, n-1));
	}    
	
    while(q--){
    	
    	int i, j;
    	cin >> i >> j;
    	i--, j--;
    	
    	if(grid[i][j]=='.'){
	    	cnt++;
	    	trees[j].add(i, 1);
	    	grid[i][j] = '*';
	    	hlp.add(j, +1);
    	}
    	else{
    		cnt--;
    		trees[j].add(i, -1);
    		grid[i][j] = '.';
    		hlp.add(j, -1);
    	}
    	
    	int cans = cnt;
    	
    	if(cnt >= n){		
	    	cans -= hlp.sum(0, cnt/n-1);
    	}
    	
    	if(cnt%n!=0){		
	    	cans -= trees[cnt/n].sum(0, cnt%n-1);
    	}
    	
    	cout << cans << endl;
    }
}
