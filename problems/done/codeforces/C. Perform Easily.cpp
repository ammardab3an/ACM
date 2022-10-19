// Problem: C. Perform Easily
// Contest: Codeforces - Technocup 2021 - Elimination Round 1
// URL: https://codeforces.com/problemset/problem/1413/C
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
    
    vi vec(6);
    for(auto &i : vec) cin >> i;
    
    sort(vec.begin(), vec.end());
    
    int n;
    cin >> n;
    
    vi notes(n);
    for(auto &i : notes){
    	cin >> i;
    }
    
    if(n==1){
    	cout << 0 << endl;
    	return 0;
    }
    
    sort(notes.begin(), notes.end());
    
    int ans = INFLL;
    
    for(int i = 0; i < 6; i++){
    	
    	vi cur(6);
    	for(int j = 0; j < 6; j++){
    		cur[j] = vec[j]-vec[i];
    	}
    	
    	assert(is_sorted(cur.begin(), cur.end()));
    	
    	multiset<pii> mst;
    	int water_level = 0;
    	
    	for(int k = 0; k < n; k++){
    		
    		int dif = notes[n-1]-notes[k];
    		
    		pii p = {dif, i};
    		while(p.second>0 && dif+cur[p.second-1] >= 0){
    			p.first = dif+cur[--p.second];
    		}
    		
    		mst.insert(p);	
    	}
    	
    	multiset<pii> foo;
    	
    	int cans = mst.rbegin()->first;
    	
    	for(int k = n-2; k >= 0; k--){
    		
    		water_level += notes[k+1]-notes[k];
    		
    		while(!mst.empty() && ((mst.begin()->first-water_level) < 0)){
    			
    			pii tt = *mst.begin();
    			mst.erase(mst.begin());
    			
    			if(tt.second==5){
    				foo.insert(tt);
    			}
    			else{
	    			tt.first -= cur[tt.second];
	    			tt.first += cur[++tt.second];	
	    			mst.insert(tt);
    			}
    		}
    		
    		assert(!mst.empty());
    		
    		int r = (mst.rbegin()->first)-water_level;
    		int l = 0;
    		
    		if(!foo.empty()){
    			l = (foo.begin()->first)-water_level;
    		}
    		
    		ans = min(ans, r-l);
    	}
    }
    
    cout << ans << endl;
}
