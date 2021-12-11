// Problem: C - Swiss-System Tournament
// Contest: AtCoder - Exawizards Programming Contest 2021（AtCoder Beginner Contest 222）
// URL: https://atcoder.jp/contests/abc222/tasks/abc222_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

int test(char a, char b){
	
	if((a == 'G') && (b == 'C')){
		return 0;
	}	
	
	if((a == 'C') && (b == 'P')){
		return 0;
	}	
	
	if((a == 'P') && (b == 'G')){
		return 0;
	}	
	
	if((b == 'G') && (a == 'C')){
		return 1;
	}
	
	if((b == 'C') && (a == 'P')){
		return 1;
	}
	
	if((b == 'P') && (a == 'G')){
		return 1;
	}
	
	return 2;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(2*n);
    for(auto &s : grid) cin >> s;
    
    vi pos(2*n);
    iota(pos.begin(), pos.end(), 0);
    
    vi rank(2*n);
    
    for(int i = 0; i < m; i++){
    	
    	for(int j = 0; j < n; j++){
    		
    		int l = 2*j;
    		int r = 2*j+1;
    		
    		char c_l = grid[pos[l]][i];
    		char c_r = grid[pos[r]][i];
    		
    		int que = test(c_l, c_r);
    		
    		// cout << pos[l]+1 << ' ' << pos[r]+1 << ' ' << c_l << ' ' << c_r << ' ' << que << endl;
    		
    		if(que == 0){
    			rank[pos[l]]++;
    		}
    		else if(que == 1){
    			rank[pos[r]]++;
    		}
    	}
    	
    	sort(pos.begin(), pos.end(), [&](int i, int j){
    		if(rank[i] != rank[j]){
    			return rank[i] > rank[j];
    		}
    		return i < j;
    	});
    	
    	// for(auto i : pos) cout << i+1 << ' '; cout << endl;
    	// for(auto i : pos) cout << rank[i] << ' '; cout << endl;
    }
    
    for(auto i : pos){
    	cout << i+1 << endl;
    }
}
