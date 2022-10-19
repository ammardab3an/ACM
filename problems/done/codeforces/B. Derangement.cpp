// Problem: B. Derangement
// Contest: Codeforces - 2016, IX Samara Regional Intercollegiate Programming Contest
// URL: https://codeforces.com/gym/100971/problem/B
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
    for(auto &i : vec) cin >> i, --i;
    
    vi tmp;
    for(int i = 0; i < n; i++){
    	if(vec[i]==i){
    		tmp.push_back(i);
    	}
    }
    
    if(tmp.empty()){
    	cout << 0 << endl;
    }
    else if(tmp.size()==1){
    	cout << 1 << endl;
    	cout << tmp[0]+1 << ' ' << (tmp[0]+1)%n+1 << endl;
    }
    else{
	    
	    int tt = 0;
	    vpii tt_ans;
	    
	    if(tmp.size()%2==1){
	    	assert(tmp.size()>=3);
	    	vi ttt(tmp.end()-3, tmp.end());
	    	tmp.resize(tmp.size()-3);
	    	tt_ans.emplace_back(ttt[0]+1, ttt[1]+1);
	    	tt_ans.emplace_back(ttt[1]+1, ttt[2]+1);
	    	tt += 2;
	    }
	    
    	cout << tt + tmp.size()/2 << endl;
    	
    	for(int i = 0; i < tmp.size()/2; i++){
    		cout << tmp[i]+1 << ' ' << tmp[(int)tmp.size()-i-1]+1 << endl;
    	}
    	
    	for(auto [l, r] : tt_ans){
    		cout << l << ' ' << r << endl;
    	}
    }
}
