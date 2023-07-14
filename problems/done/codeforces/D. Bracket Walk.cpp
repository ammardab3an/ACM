// Problem: D. Bracket Walk
// Contest: Codeforces - Codeforces Round 877 (Div. 2)
// URL: https://codeforces.com/contest/1838/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

int tree[NMAX<<2];
int lazy[NMAX<<2];

void push(int nd, int l, int r){
	
	if(!lazy[nd]){
		return;
	}	
	
	tree[nd] += lazy[nd];
	
	if(l != r){
		lazy[nd*2] += lazy[nd];
		lazy[nd*2+1] += lazy[nd];
	}
	
	lazy[nd] = 0;
}

void update(int nd, int l, int r, int q_l, int q_r, int d){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}		
	
	if(q_l <= l && r <= q_r){
		lazy[nd] += d;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, d);
	update(nd*2+1, mid+1, r, q_l, q_r, d);
	
	tree[nd] = min(tree[nd*2], tree[nd*2+1]);	
}

int query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return INF;
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	int st_path = query(nd*2, l, mid, q_l, q_r);
	int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return min(st_path, nd_path);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int n, q;
	cin >> n >> q;
	
	string str;
	cin >> str;
	
	vi val(n);
	
	for(int i = 0; i < n; i++){
			
		if(str[i] == '('){
			val[i] = +1;
		}
		else{
			val[i] = -1;
		}
		
		update(1, 0, n-1, i, n-1, val[i]);
	}
	
	// st0 ((
	// st1 ))
	set<int> st0, st1;
	
	for(int i = 0; i+1 < n; i++){
		
		if(val[i]==val[i+1]){
			
			if(val[i]==+1){
				st0.insert(i);
			}
			else{
				st1.insert(-i);
			}
		}
	}
	
	auto check = [&]()->bool{
		
		if(val[0] != 1 || val[n-1] != -1){
			return false;
		}
		
		int lb = tree[1];	
		int ls = query(1, 0, n-1, n-1, n-1);
		
		if(lb >= 0 && ls==0){
			return true;
		}
		
		if(lb < 0){
			
			if(st0.empty()){
				return false;
			}
			
			int p = *st0.begin();
			
			if(!st1.empty()){
				int q = -(*st1.rbegin());
				if(q < p){
					return false;
				}
			}
			
			ls += 2 * ((0-lb+1)/2);
		}
		
		if(ls > 0){
			
			if(st1.empty()){
				return false;
			}
			
			int p = -(*st1.begin());
			
			if(!st0.empty()){
				int q = *st0.rbegin();
				if(p < q){
					return false;
				}			
			}
			
			ls %= 2;
		}
		
		return ls==0;
	};
	
	while(q--){
		
		int i;
		cin >> i;
		i--;
		
		update(1, 0, n-1, i, n-1, -2*val[i]);
		
		if(i+1<n && val[i]==val[i+1]){
			
			if(val[i]==+1){
				st0.erase(i);
			}
			else{
				st1.erase(-i);
			}
		}
		
		if(i && val[i]==val[i-1]){
			
			if(val[i-1]==+1){
				st0.erase(i-1);
			}
			else{
				st1.erase(-(i-1));
			}
		}
		
		val[i] *= -1;
		
		if(i+1<n && val[i]==val[i+1]){
			
			if(val[i]==+1){
				st0.insert(i);
			}
			else{
				st1.insert(-i);
			}
		}
		
		
		if(i && val[i]==val[i-1]){
			
			if(val[i-1]==+1){
				st0.insert(i-1);
			}
			else{
				st1.insert(-(i-1));
			}
		}
		
		// for(auto i : val){
			// if(i==1) cout << '(';
			// else cout << ')';
		// } cout << endl;
// 		
		// for(auto i : st0) cout << i << ' '; cout << endl;
		// for(auto i : st1) cout << -i << ' '; cout << endl;
		
		cout << (check() ? "YES" : "NO") << endl;
	}
}
