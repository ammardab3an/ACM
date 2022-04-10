// Problem: E. MinimizOR
// Contest: Codeforces - Codeforces Round #781 (Div. 2)
// URL: https://codeforces.com/contest/1665/problem/E
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

int n;
int arr[NMAX];
vi tree[NMAX << 2];

vi merge(const vi &a, const vi &b){
	
	vi ret;
	
	int i = 0, j = 0;
	while(i < a.size() && j < b.size()){
		if(a[i] < b[j]){
			ret.push_back(a[i++]);
		}
		else{
			ret.push_back(b[j++]);
		}
	}	
	
	while(i < a.size()){
		ret.push_back(a[i++]);
	}
	
	while(j < b.size()){
		ret.push_back(b[j++]);
	}
	
	return ret;
}

void build(int nd, int l, int r){
	
	if(l==r){
		tree[nd] = {arr[l]};
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
	if(tree[nd].size() > 40) tree[nd].resize(40);
}

vi query(int nd, int l, int r, int q_l, int q_r){
	
	if(r < q_l || q_r < l){
		return {};
	}	
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	vi st_path = query(nd*2, l, mid, q_l, q_r);
	vi nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	vi ret = merge(st_path, nd_path);
	if(ret.size() > 40) ret.resize(40);
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		build(1, 0, n-1);
		
		int q; cin >> q; while(q--){
			
			int l, r;
			cin >> l >> r;
			l--, r--;
			
			vi tmp = query(1, 0, n-1, l, r);
			
			// for(auto i : tmp) cout << i << ' '; cout << endl;
			
			int ans = INFLL;
			
			for(int i = 0; i < tmp.size(); i++)
			for(int j = 0; j < i; j++){
				ans = min(ans, tmp[i] | tmp[j]);
			}
			
			cout << ans << endl;
		}
    }	
}
