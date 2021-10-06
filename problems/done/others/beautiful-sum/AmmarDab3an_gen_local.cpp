
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"
#include "testlib.h"

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

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//  
// int rand(int x, int y) {
	// return uniform_int_distribution<int>(x, y)(rng);
// }

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

ll rn(ll l,ll r){
    return rnd.next(l,r);
}

int32_t main(int32_t argc, char* argv[]){

    registerGen(argc, argv, 1);
    
    int t, n, ones_l, ones_r, vl, vr;
    
#ifdef CPEDU
    cin >> t >> n >> ones_l >> ones_r >> vl >> vr;
#else
    t = atoi(argv[1]);
    n = atoi(argv[2]);
    ones_l = atoi(argv[3]);
    ones_r = atoi(argv[4]);
    vl = atoi(argv[5]);
    vr = atoi(argv[6]);
#endif
    
    assert(t*n <= 1e5);
    assert(ones_r <= n);
    assert(ones_l <= ones_r);
    assert(vr <= 1e9);
    assert(vl < vr);
    assert(vr-vl+1 >= n);
    
    cout << t << endl;
    
    while(t--){
        
        cout << n << endl;
        
        int cnt[2];
        cnt[1] = rn(ones_l, ones_r);
        cnt[0] = n - cnt[1];
        
        vi tmp = rnd.distinct(n, vl, vr);
        
        int idx = 0;
        for(auto i : tmp){
            
            int j;
            
            if(cnt[0]){
                cnt[0]--;
                j = i*2;
            }
            else if(cnt[1]){
                cnt[1]--;
                j = i*2+1;
            }
                
            cout << j << " \n"[idx++==n-1];    
        }
    }
}
