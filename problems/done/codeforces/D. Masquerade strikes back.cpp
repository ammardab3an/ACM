// Problem: D. Masquerade strikes back
// Contest: Codeforces - 2018-2019 ACM-ICPC, NEERC, Southern Subregional Contest, Qualification Stage
// URL: https://codeforces.com/gym/101911/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
    
    vi vec(n);
    for(auto &i : vec) cin >> i;
    
    vi pos(n);
    iota(pos.begin(), pos.end(), 0);
    sort(pos.begin(), pos.end(), [&](int i, int j){
        return vec[i] < vec[j];
    });
    
    vpii ans(n);
    
    bool bad = false;
    for(int i = 0; (i < n) && !bad; ){
        
        int sz = 0;
        int ai = vec[pos[i]];
        
        for(; (i < n) && (vec[pos[i]] == ai); i++){
            sz++;
        }
        
        vi tmp;
        for(int p = 1; (p*p <= ai) && (tmp.size() < sz); p++){
            if(ai%p==0){
                tmp.push_back(p);
                if(p*p != ai) tmp.push_back(ai/p);
            }
        }
        
        int j = i-1;
        while(sz--){
            if(tmp.empty()){
                bad = true;
                break;
            }
            ans[pos[j]] = {ai/tmp.back(), tmp.back()};
            tmp.pop_back();
            j--;
        }
    }
    
    if(!bad){
        cout << "YES" << endl;
        for(auto p : ans){
            cout << p.first << ' ' << p.second << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }
}
