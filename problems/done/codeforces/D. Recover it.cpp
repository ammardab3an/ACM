// Problem: D. Recover it!
// Contest: Codeforces - Codeforces Round #565 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1176/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

const int N = 10000000;

int lp[N+1];
vector<int> pr;

void init(){
    
    for (int i=2; i<=N; ++i) {
    
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j){
            lp[i * pr[j]] = pr[j];
        }
    }
}    
    
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    n *= 2;
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    init();
    
    multiset<int> mst, nmst;
    for(auto i : vec) mst.insert(i);
    
    vi ans;
    
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    
    while(!mst.empty()){
        
        int ai = *mst.rbegin();
        mst.erase(mst.find(ai));
        
        if(*lower_bound(pr.begin(), pr.end(), ai) != ai){
            
            ans.push_back(ai);
            
            for(auto p : pr){
                
                if(p*p > ai) break;
                
                if(ai%p==0){    
                    mst.erase(mst.find(ai/p));
                    break;
                }
            }
        }
        else{
            nmst.insert(ai);
        }
    }
    
    mst = nmst;
    
    while(!mst.empty()){
        
        int ai = *mst.begin();
        mst.erase(mst.begin());
        
        ans.push_back(ai);
        
        mst.erase(mst.find(pr[ai-1]));
    }
    
    for(auto i : ans) cout << i << ' ' ; cout << endl;
}
