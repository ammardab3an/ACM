// Problem: C. Ranom Numbers
// Contest: Codeforces - Educational Codeforces Round 150 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1841/problem/C
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	vi p10(8);
	
	p10[0] = 1;
	for(int i = 1; i < 8; i++){
		p10[i] = p10[i-1] * 10;
	}
	
    int t; cin >> t; while(t--){

		string str;
		cin >> str;
		
		int n = str.size();
		
		vi suf(n);
		char mx = 'A';
		for(int i = n-1; i >= 0; i--){
			
			if(i+1 < n){
				suf[i] = suf[i+1];
			}
			
			if(str[i] >= mx){
				mx = str[i];
				suf[i] += p10[str[i]-'A'];
			}
			else{
				suf[i] -= p10[str[i]-'A'];
			}
		}
		
		vi suf_msk(n);
		for(int i = n-1; i >= 0; i--){
			
			if(i+1 < n){
				suf_msk[i] = suf_msk[i+1];
			}	
			
			suf_msk[i] |= 1 << (str[i]-'A');
		}
		
		int ans = suf[0];
		
		vi frq(5);
		int pre_neg = 0;
		
		for(int i = 0; i < n; i++){
			
			for(int j = 0; j < 5; j++){
				
				int cans = pre_neg;
				if(i+1 < n) cans += suf[i+1];
				
				int cur_msk = 1<<j;
				if(i+1 < n) cur_msk |= suf_msk[i+1];
				
				for(int k = 0; k < 5; k++){
					if((cur_msk>>(k+1))==0){
						cans += frq[k] * p10[k];
					}
					else{
						cans -= frq[k] * p10[k];
					}
				}
				
				int x = cans;
				if(i+1 < n) x -= suf[i+1];
				
				if(i==n-1 || (suf_msk[i+1]>>(j+1))==0){
					cans += p10[j];
				}
				else{
					cans -= p10[j];
				}
				
				ans = max(ans, cans);
			}
			
			int j = str[i]-'A';
			
			for(int k = 0; k < j; k++){
				pre_neg -= frq[k] * p10[k];
				frq[k] = 0;
			}
			
			frq[j]++;
		}
		
		cout << ans << endl;
    }	
}
