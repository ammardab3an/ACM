// Problem: G. Magic Number Group
// Contest: Codeforces - 2021 Jiangxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103366/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
 
const int NMAX = 5e4 + 10;
const int QMAX = 5e4 + 10;
const int AMAX = 1e6 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

struct query{
    int lo, hi, idx;
    bool operator < (query other){
        if(lo/BLOCK != other.lo/BLOCK) return lo < other.lo;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
} queries[QMAX];

int spf[AMAX];
int arr[NMAX], ans[NMAX];
int cnt[AMAX], frq[AMAX], cans;
vi pre[NMAX];

void init_sieve(){
    
    spf[1] = 1;
    
    for(int i = 2; i < AMAX; i++){
        spf[i] = i;
    }   
    
    for(int i = 4; i < AMAX; i+=2){
        spf[i] = 2;
    }
    
    for(int i = 3; i*i < AMAX; i++){
        if(spf[i]==i){
            for(int j = i*i; j < AMAX; j+=i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }
        }
    }
}

void add(int idx){
    
    for(auto i : pre[idx]){
        frq[cnt[i]]--;
        frq[++cnt[i]]++;
        if(frq[cans+1]) cans++;
    }
}

void rem(int idx){
    
    for(auto i : pre[idx]){
        frq[cnt[i]--]--;
        frq[cnt[i]]++;
        if(frq[cans]==0) cans--;
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init_sieve();
    
    int t; cin >> t; while(t--){

        int n, q;
        cin >> n >> q;
        
        for(int i = 0; i < n; i++){
            
            cin >> arr[i];
            
            pre[i].clear();
            int ai = arr[i];
            while(ai != 1){
                if(pre[i].empty() || pre[i].back() != spf[ai]){                
                    pre[i].push_back(spf[ai]);
                }
                ai /= spf[ai];
            }
        }
        
        for(int i = 0; i < q; i++){
            auto &que = queries[i];
            cin >> que.lo >> que.hi;
            que.lo--, que.hi--;
            que.idx = i;
        }
        
        sort(queries, queries+q);
        
        int l = 1, r = 0;
        
        for(int i = 0; i < q; i++){
            
            auto &que = queries[i];
            
            int cl = que.lo;
            int cr = que.hi;
            int ci = que.idx;
            
            while(r < cr) add(++r);
            while(cl < l) add(--l);
            while(cr < r) rem(r--);
            while(l < cl) rem(l++);
            
            ans[ci] = cans;
        }
        
        while(l <= r) rem(r--);
        
        for(int i = 0; i < q; i++) 
            cout << ans[i] << endl;
    }	
}
