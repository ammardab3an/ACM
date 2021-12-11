// Problem: Landscape Generator
// Contest: Kattis
// URL: https://judge.icpc.global/problems/landscape
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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

struct my_st{
	
	multiset<int> mst;
	int sz = 0, sm = 0, water_level = 0;
	
	int get_sum(){
		return sm - water_level * sz;
	}
	
	void insert(int val){
		sz++;
		sm += val+water_level;
		mst.insert(val+water_level);
	}
	
	void raise(){
		water_level++;
		while(mst.size() && ((*mst.begin()) == water_level)){
			sz--;
			sm -= water_level;
			mst.erase(mst.begin());
		}
	}
	
	void clear(){
		sz = sm = water_level = 0;
		mst.clear();
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    vi tmp_0(n+1);
    vi pos_0(n), pos_1(n), neg_0(n), neg_1(n);
    vi poo_0(n), poo_1(n), nee_0(n), nee_1(n);
    
    while(k--){
    	
    	char c;
    	int l, r;
    	cin >> c >> l >> r;
    	l--, r--;
    	
    	if(c == 'R'){
    		tmp_0[l]++;
    		tmp_0[r+1]--;
    	}
    	else if(c == 'D'){
    		tmp_0[l]--;
    		tmp_0[r+1]++;
    	}
    	else if(c == 'H'){
    		
    		if(l==r){
    			tmp_0[l]++;
    			tmp_0[r+1]--;
    		}
    		else if((r-l+1)%2==0){
    			pos_0[(r+l)/2+1] += ((r-l+1)/2);
    			if((r+l)/2+2<n) poo_0[(r+l)/2+2]++;
    			if(r+2<n) poo_0[r+2]--;
    			pos_1[(r+l)/2] += ((r-l+1)/2);
    			if((r+l)/2-1>=0) poo_1[(r+l)/2-1]++;
    			if(l-2>=0) poo_1[l-2]--;
    		}
    		else{
    			pos_0[(r+l)/2] += ((r-l)/2 +1);
    			if((r+l)/2+1<n) poo_0[(r+l)/2+1]++;
    			if(r+2<n) poo_0[r+2]--;
    			pos_1[(r+l)/2-1] += ((r-l)/2);
    			if((r+l)/2-2>=0) poo_1[(r+l)/2-2]++;
    			if(l-2>=0) poo_1[l-2]--;
    		}
    	}
    	else if(c == 'V'){
    		
    		if(l==r){
    			tmp_0[l]--;
    			tmp_0[r+1]++;
    		}
    		else if((r-l+1)%2==0){
    			neg_0[(r+l)/2+1] += ((r-l+1)/2);
    			if((r+l)/2+2<n) nee_0[(r+l)/2+2]++;
    			if(r+2<n) nee_0[r+2]--;
    			neg_1[(r+l)/2] += ((r-l+1)/2);
    			if((r+l)/2-1>=0) nee_1[(r+l)/2-1]++;
    			if(l-2>=0) nee_1[l-2]--;
    		}
    		else{
    			neg_0[(r+l)/2] += ((r-l)/2 +1);
    			if((r+l)/2+1<n)nee_0[(r+l)/2+1]++;
    			if(r+2<n) nee_0[r+2]--;
    			neg_1[(r+l)/2-1] += ((r-l)/2);
    			if((r+l)/2-2>=0) nee_1[(r+l)/2-2]++;
    			if(l-2>=0) nee_1[l-2]--;
    		}
    	}
    }
    
    vi ans(n);
    
    int cur = 0;
    for(int i = 0; i < n; i++){
    	cur += tmp_0[i];
    	ans[i] += cur;	
    }
    
	int cur_pos = 0, cur_neg = 0;
	
	for(int i = 0; i < n; i++){
		if(i) poo_0[i] += poo_0[i-1];
		if(i) nee_0[i] += nee_0[i-1];
		cur_pos += pos_0[i] - poo_0[i];
		cur_neg += neg_0[i] - nee_0[i];
		ans[i] += cur_pos - cur_neg;	
	}
	
	cur_pos = cur_neg = 0;
	
	for(int i = n-1; i >= 0; i--){
		if(i+1<n) poo_1[i] += poo_1[i+1];
		if(i+1<n) nee_1[i] += nee_1[i+1];
		cur_pos += pos_1[i] - poo_1[i];
		cur_neg += neg_1[i] - nee_1[i];
		ans[i] += cur_pos - cur_neg;	
	}
	
    for(int i = 0; i < n; i++){
    	cout << ans[i] << endl;
    }
}
