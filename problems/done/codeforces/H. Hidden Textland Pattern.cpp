// Problem: H. Hidden Textland Pattern
// Contest: Codeforces - First Masters Championship LATAM 2024
// URL: https://codeforces.com/gym/104990/problem/H
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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


struct hash_struct{
	
	int n;
	string str;
	
	array<int, 2> p, m;
	vector<array<int, 2>> pre;
	vector<array<int, 2>> pow_m;
	
	hash_struct(){}
	
	hash_struct(string _str){
		str = _str;
		n = str.size();
		init();
		build();
	}
	
	bool is_prime(int x){
		for(ll i = 2; i*i <= x; i++) if(x%i==0){
			return false;
		}
		return true;
	}
	
	void init(){
		
		p = {130807, 1250284429}; //{rand(1e5, 2e5), rand(1e9, 2e9)};
		m = {53, 79}; //{rand(30, 50), rand(50, 100)};
		
		for(int j = 0; j < 2; j++){
			while(!is_prime(p[j])) p[j]++;
			while(!is_prime(m[j])) m[j]++;
		}
		
		// for(auto i : p) cout << i << ' '; cout << endl;
		// for(auto i : m) cout << i << ' '; cout << endl;
		
		pow_m.resize(n, array<int, 2>({0, 0}));
		
		pow_m[0][0] = pow_m[0][1] = 1;
		for(int i = 1; i < n; i++)
		for(int j = 0; j < 2; j++){
			pow_m[i][j] = (pow_m[i-1][j] *1ll* m[j])%p[j];
		}
	}
	
	void build(){
		
		pre.resize(n);
		
		array<int, 2> cval = {0, 0};
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 2; j++){
				cval[j] = ((cval[j] *1ll* m[j])%p[j] + (str[i]-'a'+1))%p[j];
			}
			pre[i] = cval;
		}
	}
	
	array<int, 2> query(int l, int r){
		array<int, 2> ret = pre[r];
		if(l) for(int j = 0; j < 2; j++){
			ret[j] = (ret[j] - (pre[l-1][j] *1ll* pow_m[r-l+1][j])%p[j] + p[j])%p[j];
		}
		return ret;
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
	
	int n;
	cin >> n;
	
	string str;
	cin >> str;
	
	int mx = 0;
	{
		map<char, int> mp;
		for(auto c : str) mp[c]++;
		
		for(auto [v, f] : mp){
			mx = max(mx, f);
		}
	}
	
	hash_struct hs(str);
	
	auto calc = [&](int ln){
		
		map<array<int, 2>, int> mp;
		
		for(int i = 0; i+ln-1 < n; i++){
			auto tmp = hs.query(i, i+ln-1);
			mp[tmp]++;
		} 	
		
		int mx = 0;
		for(auto &[v, f] : mp){
			mx = max(mx, f);
		}
		
		return mx;
	};
	
	int l = 1;
	int r = n;
	
	int bs_ans = 0;
	
	while(l <= r){
		
		int mid = (l+r)/2;
		
		if(calc(mid)==mx){
			bs_ans = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	
	assert(bs_ans > 0);
	
	int ln = bs_ans;
	map<array<int, 2>, pair<int, int>> mp;
	
	for(int i = 0; i+ln-1 < n; i++){
		auto tmp = hs.query(i, i+ln-1);
		mp[tmp].first = i;
		mp[tmp].second++;
	}
	
	string ans;
	
	for(auto &[v, f] : mp){
		if(f.second==mx){
			string cur = str.substr(f.first, ln);
			if(ans.empty() || ans > cur) ans = cur;
		}
	}
	
	cout << ans << endl;
}
