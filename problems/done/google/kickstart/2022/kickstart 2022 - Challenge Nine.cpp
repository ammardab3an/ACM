// Problem: Challenge Nine
// Contest: Google Coding Competitions - Round A 2022 - Kick Start 2022
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e7997
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
	
	int tt = 1;    
    int t; cin >> t; while(t--){
    	
		cout << "Case #" << tt++ << ": ";
		
		string num;
		cin >> num;
		
		int n = num.size();
		
		int sm = 0;
		for(auto c : num) sm = (sm + c - '0')%9;
		int nd = (9-sm)%9;
		
		bool found = false;
		
		if(!nd) cout << num[0];
		
		for(int i = nd ? 0 : 1; i < n; i++){
		
			if(!found && num[i]-'0' > nd){
				found = true;
				cout << nd << num[i];
			}
			else{			
				cout << num[i];
			}
		}
		
		if(!found){
			cout << char('0'+nd);
		}
		
		cout << endl;
    }	
}
