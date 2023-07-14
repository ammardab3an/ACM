// Problem: E. Character Blocking
// Contest: Codeforces - Codeforces Round 878 (Div. 3)
// URL: https://codeforces.com/contest/1840/problem/E
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


array<int, 2> p, m;
vector<array<int, 2>> pre;
vector<array<int, 2>> pow_m;

bool is_prime(int x){
	for(ll i = 2; i*i <= x; i++) if(x%i==0){
		return false;
	}
	return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	{
		int n = NMAX;
		
		p = {130807, 1250284429}; //{rand(1e5, 2e5), rand(1e9, 2e9)};
		m = {53, 79}; //{rand(30, 50), rand(50, 100)};
		
		for(int j = 0; j < 2; j++){
			while(!is_prime(p[j])) p[j]++;
			while(!is_prime(m[j])) m[j]++;
		}
		
		pow_m.resize(n, array<int, 2>({0, 0}));
		
		pow_m[0][0] = pow_m[0][1] = 1;
		for(int i = 1; i < n; i++)
		for(int j = 0; j < 2; j++){
			pow_m[i][j] = (pow_m[i-1][j] *1ll* m[j])%p[j];
		}
	}
	
    int tt; cin >> tt; while(tt--){

		vector<string> str(2);
		cin >> str[0] >> str[1];
		
		int n = str[0].size();
		
		vector<array<int, 2>> str_hash(2);
		
		for(int k = 0; k < 2; k++){
			
			array<int, 2> cval = {0, 0};
			for(int i = 0; i < n; i++){
				for(int j = 0; j < 2; j++){
					cval[j] = ((cval[j] *1ll* m[j])%p[j] + (str[k][i]-'a'+1))%p[j];
				}
			}
			
			str_hash[k] = cval;
		}
		
		auto add = [&](int i, int j){
			
			auto &cstr = str[i];
			auto &cval = str_hash[i];
			
			for(int k = 0; k < 2; k++){
				cval[k] = (cval[k] + (cstr[j]-'a'+1)*pow_m[n-j-1][k])%p[k];
				cval[k] += p[k];
				cval[k] %= p[k];
			}
		};
		
		auto del = [&](int i, int j){
			
			auto &cstr = str[i];
			auto &cval = str_hash[i];
			
			for(int k = 0; k < 2; k++){
				cval[k] = (cval[k] - (cstr[j]-'a'+1)*pow_m[n-j-1][k])%p[k];
				cval[k] += p[k];
				cval[k] %= p[k];
			}
		};
		
		int t, q;
		cin >> t >> q;
		
		set<pii> st;
		vector<vi> queries(q);
		
		for(int i = 0; i < q; i++){
			
			int k;
			cin >> k;
			
			while(!st.empty() && (st.begin()->first==i)){
				int p = st.begin()->second;
				st.erase(st.begin());
				add(0, p);
				add(1, p);
			}
			
			if(k==1){
				
				int p;
				cin >> p;
				p--;
				
				del(0, p);
				del(1, p);
				
				st.insert({i+t, p});
			}
			else if(k==2){
				
				int i0, j0, i1, j1;
				cin >> i0 >> j0 >> i1 >> j1;
				i0--, j0--, i1--, j1--;
				
				del(i0, j0);
				del(i1, j1);
				
				swap(str[i0][j0], str[i1][j1]);
				
				add(i0, j0);
				add(i1, j1);
			}
			else if(k==3){
				cout << (str_hash[0]==str_hash[1] ? "YES" : "NO") << endl;
			}
		}
		
    }	
}
