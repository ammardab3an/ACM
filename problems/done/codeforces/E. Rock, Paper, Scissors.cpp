// Problem: E. Rock, Paper, Scissors
// Contest: Codeforces - Codeforces Round #674 (Div. 3)
// URL: https://codeforces.com/contest/1426/problem/E
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
    
    int n;
    cin >> n;
    
    vi vec_a(3), vec_b(3);
    
    for(auto &i : vec_a) cin >> i;
    for(auto &i : vec_b) cin >> i;
    
    int mn = 0, mx = 0;
    
    {
        // mx
        
        vi a = vec_a, b = vec_b;
        
        for(int i = 0; i < 3; i++){
            int cmn = min(a[i], b[(i+1)%3]);
            mx += cmn;
            a[i] -= cmn;
            b[(i+1)%3] -= cmn;
        }
    }
    {
        // mn
        vpii tmp;
        for(int i = 0; i < 3; i++){
            tmp.push_back({i, i});
            tmp.push_back({i, (i+2)%3});
        }
        
        sort(tmp.begin(), tmp.end());
        
        mn = INF;
        
        do{
            
            vi a = vec_a, b = vec_b;
            
            for(auto p : tmp){
                
                int i = p.first;
                int j = p.second;
                int cmn = min(a[i], b[j]);
                a[i] -= cmn;
                b[j] -= cmn;
                    
            }   
            
            int cans = 0;
            for(int i = 0; i < 3; i++) cans += a[i];
            
            mn = min(mn, cans);
               
        } while(next_permutation(tmp.begin(), tmp.end()));
        
    }
    
    cout << mn << ' ' << mx << endl;
}
