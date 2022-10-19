// Problem: F. Mahmoud and Ehab and yet another xor task
// Contest: Codeforces - Codeforces Round #473 (Div. 2)
// URL: https://codeforces.com/contest/959/problem/F
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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

int arr[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    vpii queries(q);
    for(auto &p : queries){
    	cin >> p.first >> p.second;
    	p.first--;
    }
    
    vi pos(q);
    iota(pos.begin(), pos.end(), 0);
    sort(pos.begin(), pos.end(), [&](int i, int j){
    	return queries[i].first < queries[j].first;
    });
    
    vi ans(q);
    
    int i = 0;
    set<int> st;
    st.insert(0);
    int val = 1;
    
    for(int p : pos){
    	
    	int l = queries[p].first;
    	int x = queries[p].second;
    	
    	while(i <= l){
    		
    		if(!st.count(arr[i])){
    			
    			vi tmp(st.size()+1);
    			int idx = 0;
    			int ai = arr[i];
    			for(auto e : st){
    				tmp[idx++] = e^ai;
    			}	
    			
    			tmp.back() = ai;
    			
    			for(auto e : tmp){
    				st.insert(e);
    			}
    		}
    		else{
    			val = mul(val, 2);
    		}
    		
    		i++;
    	}	
    	
    	if(!st.count(x)){
    		ans[p] = 0;
    	}
    	else{
    		ans[p] = val;
    	}
    }
    
    for(auto i : ans){
    	cout << i << endl;
    }
    
}
 