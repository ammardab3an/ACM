// Problem: D. Serega and Fun
// Contest: Codeforces - Codeforces Round #260 (Div. 1)
// URL: https://codeforces.com/problemset/problem/455/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
 
const int NMAX = 1e5 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
int arr[NMAX];
deque<int> blk[BLOCK];
int frq[BLOCK][NMAX];

void update(int l, int r){
	
	int lb = l/BLOCK;
	int rb = r/BLOCK;
	
	l %= BLOCK;
	r %= BLOCK;
	
	if(lb==rb){
		int tmp = blk[lb][r];
		for(int i = r; i > l; i--){
			blk[lb][i] = blk[lb][i-1];
		}
		blk[lb][l] = tmp;
		return;
	}	
	
	//else
	int ar = blk[rb][r];
	
	for(int i = r; i > 0; i--){
		blk[rb][i] = blk[rb][i-1];
	}
	blk[rb].pop_front();
	frq[rb][ar]--;
	
	for(int i = lb; i < rb; i++){
		int tmp = blk[i].back();
		blk[i].pop_back();
		frq[i][tmp]--;
		blk[i+1].push_front(tmp);
		frq[i+1][tmp]++;
	}
	
	blk[lb].push_back(0);
	assert(blk[lb].size() >= 1);
	for(int i = blk[lb].size()-1; i > l; i--){
		blk[lb][i] = blk[lb][i-1];
	}
	
	blk[lb][l] = ar;
	frq[lb][ar]++;
}

int query(int l, int r, int k){
	
	int lb = l/BLOCK;
	int rb = r/BLOCK;
	
	l %= BLOCK;
	r %= BLOCK;
	
	if(lb==rb){
		int frq = 0;
		for(int i = l; i <= r; i++){
			frq += blk[lb][i]==k;
		}	
		return frq;
	}
	
	//else
	int ret = 0;
	
	for(int i = r; i >= 0; i--){
		ret += blk[rb][i]==k;
	}
	
	for(int i = lb+1; i < rb; i++){
		ret += frq[i][k];
	}
	
	assert(blk[lb].size() >= 1);
	for(int i = blk[lb].size()-1; i >= l; i--){
		ret += blk[lb][i]==k;
	}
	
	return ret;
}

void print(){
	for(int i = 0; i <= (n-1)/BLOCK; i++){
		cout << i << endl;
		for(auto j : blk[i]) cout << j+1 << ' '; cout << endl;
	}
	cout << endl;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    	--arr[i];
    	blk[i/BLOCK].push_back(arr[i]);
    	frq[i/BLOCK][arr[i]]++;
    }
    
    int last = 0;
    
    // print();
    
    int m; cin >> m; while(m--){
    	
    	int k;
    	cin >> k;
    	
    	if(k==1){
    		int l, r;
    		cin >> l >> r;
    		l = (l+last-1)%n;
    		r = (r+last-1)%n;
    		if(l > r) swap(l, r);
    		
    		update(l, r);
    		
    		// cout << "UPDATE" << endl;
    		// print();
    	}
    	else{
    		int l, r, k;
    		cin >> l >> r >> k;
    		l = (l+last-1)%n;
    		r = (r+last-1)%n;
    		k = (k+last-1)%n;
    		if(l > r) swap(l, r);
    		
    		int q = query(l, r, k);
    		cout << q << endl;
    		
    		last = q;
    	}
    }
}
