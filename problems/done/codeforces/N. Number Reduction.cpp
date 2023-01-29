// Problem: N. Number Reduction
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/N
// Memory Limit: 512 MB
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
    
    int t; cin >> t; while(t--){


		string num;
		cin >> num;
		
		int k;
		cin >> k;
		
		int n = num.size();
		
		vector<vi> lst(n+1, vi(10));
		lst.back() = vi(10, n);
		
		for(int i = n-1; i >= 0; i--){
			lst[i] = lst[i+1];
			lst[i][num[i]-'0'] = i;
		}
		
		vector<bool> del(n);
		
		int p = 0;
		
		while(k && p < n){
			
			int np = -1;
			for(int i = (p==0 ? 1 : 0); i < 10; i++){
				if(lst[p][i] < n && lst[p][i]-p <= k){
					np = lst[p][i];
					break;
				}
			}	
			
			if(np==-1) break;
			
			for(int i = p; i < np; i++){
				del[i] = true;
			}
			
			k -= np-p;
			p = np+1;
		}
		
		string res;
		for(int i = 0; i < n; i++) if(!del[i]){
			res.push_back(num[i]);
		}
		
		while(k) res.pop_back(), k--;
		
		cout << res << endl;
    }	
}
