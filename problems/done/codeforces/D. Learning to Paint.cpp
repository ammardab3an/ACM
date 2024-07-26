// Problem: D. Learning to Paint
// Contest: Codeforces - CodeTON Round 8 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1942/problem/D
// Memory Limit: 512 MB
// Time Limit: 4500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

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
const int NMAX = 1e3 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

int n, k;
int arr[NMAX][NMAX];
vi* mem[NMAX];

vi* go(int i){
	
	if(i >= n){
		return new vi(1, 0);
	}	
	
	auto &ret = mem[i];
	if(ret) return ret;
	ret = new vi();
	
	vector<pair<int, vi*>> tmp;
	
	{
		vi *nxt = go(i+1);
		tmp.push_back({0, nxt});
	}
	
	for(int j = i; j < n; j++){
		vi *nxt = go(j+2);
		tmp.push_back({arr[i][j], nxt});
	}
	
	priority_queue<iii> que;
	for(int i = 0; i < tmp.size(); i++){
		auto &[inc, nxt] = tmp[i];
		assert(!nxt->empty());
		que.push({inc+nxt->back(), {i, nxt->size()-1}});
	}
	
	while(!que.empty() && ret->size() < k){
		
		auto [val, inds] = que.top();
		auto [ind_tmp, ind_nxt] = inds;
		que.pop();
		
		ret->push_back(val);
		
		auto &[inc, nxt] = tmp[ind_tmp];
		
		if(--ind_nxt >= 0){
			que.push({inc+(*nxt)[ind_nxt], {ind_tmp, ind_nxt}});
		}
	}
	
	reverse(ret->begin(), ret->end());
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		cin >> n >> k;
		for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++){
			cin >> arr[i][j];
		}
		
		if(n==0){
			n = 1e3;
			k = 5e3;
			for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++){
				arr[i][j] = rand(1e5, 2e5);
			}
		}
		memset(mem, 0, sizeof mem);
		
		vi ans = *go(0);
		reverse(ans.begin(), ans.end());
		for(auto e : ans) cout << e << ' ';
		cout << endl;
    }	
}
