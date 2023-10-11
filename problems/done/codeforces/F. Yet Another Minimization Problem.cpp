// Problem: F. Yet Another Minimization Problem
// Contest: Codeforces - Codeforces Round 438 by Sberbank and Barcelona Bootcamp (Div. 1 + Div. 2 combined)
// URL: https://codeforces.com/contest/868/problem/F
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int NMAX = 1e5 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, sz;
int arr[NMAX];
vi pos[NMAX];
int ans[20][NMAX];
int frq[NMAX];
int q_l = 1, q_r = 0, q_ans = 0;

int calc(int l, int r){
	
	while(q_r < r){
		q_r++;
		q_ans += frq[arr[q_r]]++;
	}
	while(l < q_l){
		q_l--;
		q_ans += frq[arr[q_l]]++;
	}
	while(r < q_r){
		q_ans -= --frq[arr[q_r]];
		q_r--;
	}
	while(q_l < l){
		q_ans -= --frq[arr[q_l]];
		q_l++;
	}
	
	return q_ans;
}

void go(int k, int i, int j, int l, int r){
	
	if(i > j) return;
	
	int mid = (i+j)/2;
	pii cans = {INFLL, -1};
	
	for(int m = r; m >= l; m--){
		cans = min(cans, (pii){calc(m, mid) + (m ? (k ? ans[k-1][m-1] : INFLL) : 0), m});
	}
	
	ans[k][mid] = cans.first;
	int opt = cans.second;
	assert(opt != -1);
	
	go(k, i, mid-1, l, opt);
	go(k, mid+1, j, opt, r);
}

int32_t main(){
    
    fastIO;
	
	int k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    
    if(n==0){
    	n = 1e5;
    	k = 20;
    	for(int i = 0; i < n; i++){
    		arr[i] = 1;
    	}
    }
    
    for(int i = 0; i < n; i++){
    	pos[arr[i]].push_back(i);
    }
    
    for(int i = 0; i < k; i++){
    	go(i, 0, n-1, 0, n-1);
    }
    
    cout << ans[k-1][n-1] << endl;
}

