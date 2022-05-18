// Problem: A. Going Home
// Contest: Codeforces - Codeforces Round #707 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/problemset/problem/1500/A
// Memory Limit: 256 MB
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

vpii mp[(int) 5e6 + 100];

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
    
    vi pos(n);
    iota(pos.begin(), pos.end(), 0);
    sort(pos.begin(), pos.end(), [&](int i, int j){
    	return vec[i] < vec[j];
    });
    
    if(n <= 3200){
    	
    	for(int i = 0; i < n; i++)
    	for(int j = 0; j < i; j++){
    		mp[vec[pos[i]]+vec[pos[j]]].push_back({i, j});
    	}
    	
    	bool found = false;
    	
    	for(auto &v : mp) if(!v.empty()){
    		
    		pii p = v.back();
			int x = p.first;
			int y = p.second;
    		
    		for(auto cp : v){
    			
    			int z = cp.first;
    			int w = cp.second;
    			
    			if(x!=z && x!=w && y!=z && y!=w){
    				
    				cout << "YES" << endl;
    				cout << pos[x]+1 << ' ' << pos[y]+1 << ' ' << pos[z]+1 << ' ' << pos[w]+1 << endl;
    				found = true;
    				break;
    			}
    		}
    		
    		if(found) break;
    	}
    	
    	if(!found){
    		cout << "NO" << endl;
    	}
    }
    else{
    	
    	bool found = false;
    	
    	for(int i = 0; i+3 < n; i++){
    		if(vec[pos[i]]+vec[pos[i+3]] == vec[pos[i+1]]+vec[pos[i+2]]){
				cout << "YES" << endl;
				for(auto k : {i, i+3, i+1, i+2}){
					cout << pos[k]+1 << ' ';
				}
				cout << endl;
    			found = true;
    			break;
    		}
    	}
    	
    	assert(found);
    }
    
}
