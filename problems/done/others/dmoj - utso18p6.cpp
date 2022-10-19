// Problem: P6 - Subset Sum
// Contest: DMOJ - UTS Open '18
// URL: https://dmoj.ca/problem/utso18p6
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

const int NMAX = 1e5 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);

    int n, q;
    cin >> n >> q;

    vi A(1<<n);
    for(auto &i : A) cin >> i;

    vi F(1<<n), iF(1<<n);

    auto build = [&](){

    	int N = n;

    	for(int i = 0; i<(1<<N); ++i)
			F[i] = A[i];
		for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
			if(mask & (1<<i))
				F[mask] += F[mask^(1<<i)];
		}

    	for(int i = 0; i<(1<<N); ++i)
			iF[i] = A[(~i) & ((1<<N)-1)];
		for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
			if(mask & (1<<i))
				iF[mask] += iF[mask^(1<<i)];
		}
    };

    build();

   unordered_map<int, int> queries;

    while(q--){

    	int k, a, b;
    	cin >> k >> a >> b;

    	if(k==1){
	   		queries[a] = b;
    	}
    	else{

    		if((b&a) != a){
    			cout << 0 << endl;
    			continue;
    		}

    		int ans = 0;
    		vi *f = &F;
    		int _a = a, _b = b;

    		if(__builtin_popcount(a) > n/2){
    			a = (~a) & ((1<<n)-1);
    			b = (~b) & ((1<<n)-1);
    			swap(a, b);
    			f = &iF;
    		}

    		int cnt = 0;

    		bool bo = __builtin_popcount(a)%2;

    		for(int mask = a; ; mask = (mask-1)&a){

                cnt++;

    			if(__builtin_popcount(mask)%2==bo){
    				ans += (*f)[b^a^mask];
    			}
    			else{
    				ans -= (*f)[b^a^mask];
    			}

    			if(!mask){
    				break;
    			}
    		}

    		for(auto [s, v] : queries){
    			if((_b&s)==s && (s&_a)==_a){
    				ans -= A[s];
    				ans += v;
    			}
    		}

    		cout << ans << endl;
//    		cout << cnt << ' ' << queries.size() << ' ' << cnt+queries.size() << endl;
    	}

    	if(queries.size() >= 2500){
    		for(auto [s, v] : queries){
    			A[s] = v;
    		}
    		build();
    		queries.clear();
    	}
    }
}