// Problem: G. Anya and the Mysterious String
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int NMAX = 2e5 + 10;
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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int n, m;
		cin >> n >> m;
		
		string str;
		cin >> str;
		
		set<pii> st;
		FenwickTree bit(n);
		
		auto check = [&](int l, int r, bool b){
			
			assert(l <= r);
			string cur(str.begin()+l, str.begin()+r+1);
			for(int i = l; i <= r; i++){
				cur[i-l] = 'a' + (((cur[i-l]-'a') + bit.sum(0, i))%26);
			}
			
			if(b) cout << cur << endl;
			
			string tmp = cur;
			reverse(tmp.begin(), tmp.end());
			
			// if(tmp==cur) cout << ' ' << l << ' ' << r << ' ' << cur << endl;
			
			return tmp==cur;
		};
		
		auto calc = [&](int p, bool b=false){
			
			if(p < 0 || n <= p) return;
			
			for(int i = p-2; i <= p; i++){
				
				{
					int l = i;
					int r = i+2;
					
					if(0 <= l && r < n){
						if(check(l, r, b)){
							st.insert({l, r});
						}
						else{
							st.erase({l, r});
						}
					}
				}
				{
					int l = i;
					int r = i+1;
					
					if(0 <= l && r < n){
						if(check(l, r, b)){
							st.insert({l, r});
						}
						else{
							st.erase({l, r});
						}
					}
				}
			}
		};
		
		for(int i = 0; i < n; i++){
			calc(i);
		}
		
		// for(auto [l, r] : st) cout << l << ' ' << r << endl;
		
		while(m--){
			
			int k, l, r;
			cin >> k >> l >> r;
			l--, r--;
			
			if(k==1){
				
				int x;
				cin >> x;
				
				bit.add(l, x);
				bit.add(r+1, -x);
				
				calc(l-1);
				calc(l);
				calc(l+1);
				
				calc(r-1);
				calc(r);
				calc(r+1);
			}
			else{
				
				bool ans = true;
				auto it = st.lower_bound({l, -1});
				
				if(it != st.end() && it->second <= r){
					ans = false;
					it++;
					if(it != st.end() && it->second <= r){
						ans = false;
					}
				}
				
				cout << (ans ? "YES" : "NO") << endl;
			}
		}
    }	
}
