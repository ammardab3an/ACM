// Problem: C. Ela and Crickets
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

		int n;
		cin >> n;
		
		vpii vec(4);
		for(auto &[x, y]: vec){
			cin >> y >> x;
			x--, y--;
		}
		
		int l, r;
		l=r=-1;
		
		for(int i = 0; i < 3; i++)
		for(int j = i+1; j < 3; j++){
			if(vec[i].first==vec[j].first){
				l = vec[i].first;
			}
			if(vec[i].second==vec[j].second){
				r = vec[i].second;
			}
		}
		
		pii p = {l, r};
		
		bool found = false;
		
		found |= l==vec[3].first;
		found |= r==vec[3].second;
		
		bool b0 = abs(l-vec[3].first)%2==0;
		bool b1 = abs(r-vec[3].second)%2==0;
		
		if(p != (pii){0, 0} && p != (pii){n-1, n-1} && p != (pii){0, n-1} && p != (pii){n-1, 0}){
			found |= b0 || b1;
		}
		
		if((r!=0 && r!=n-1) && (l!=0 && l!=n-1)){
			found |= abs((p.first-p.second+1)-(vec[3].first-vec[3].second))%2==0;
			found |= abs((p.first+p.second+1)-(vec[3].first+vec[3].second))%2==0;
		}
		
		cout << (found ? "YES" : "NO") << endl;
    }	
}
