// Problem: 1099 - Sharing Chocolate
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3540
// Memory Limit: 32 MB
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
 
const int NMAX = (1 << 15) + 10;

int n;
int lg[NMAX];
int sm[NMAX];
int arr[22];
int mem[NMAX][111];

int go(int h, int w, int msk){
	
	if((msk&(msk-1))==0){
		return sm[msk]==h*w;	
	}
	
	int &ret = mem[msk][h];
	if(ret+1) return ret;
	
	bool ans = false;
	
	for(int i = (msk-1)&msk; i; i = (i-1)&msk){
	
		int msk_0 = i;
		int msk_1 = (~i)&msk;
		
		int sm_0 = sm[msk_0];
		int sm_1 = sm[msk_1];
		
		if(sm_0%h==0 && sm_1%h==0 && ((sm_0+sm_1)==h*w)){
			
			int st_path = go(h, sm_0/h, msk_0);
			int nd_path = go(h, sm_1/h, msk_1);
			
			if(st_path && nd_path){
				ans = true;
				break;
			}
		}		
		
		if(sm_0%w==0 && sm_1%w==0 && ((sm_0+sm_1)==h*w)){
			
			int st_path = go(sm_0/w, w, msk_0);
			int nd_path = go(sm_1/w, w, msk_1);
			
			if(st_path && nd_path){
				ans = true;
				break;
			}
		}		
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    lg[1] = 0;
    for(int i = 2; i < NMAX; i++){
    	lg[i] = lg[i/2]+1;	
    }
    
    int tt = 1;
    while(cin >> n, n){
		cout << "Case " << tt++ << ": ";
		
		int h, w;
		cin >> h >> w;
		
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		for(int i = 1; i < (1<<n); i++){
			sm[i] = sm[i-(1<<lg[i])] + arr[lg[i]];
		}
		
		memset(mem, -1, sizeof mem);
		
		int ans = go(h, w, (1<<n)-1);
		cout << (ans ? "Yes" : "No") << endl;
    }	
}
