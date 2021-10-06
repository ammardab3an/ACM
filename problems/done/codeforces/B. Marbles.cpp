// Problem: B. Marbles
// Contest: Codeforces - 2018-2019 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/101908/problem/B
// Memory Limit: 1024 MB
// Time Limit: 500 ms
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

int mem[111][111];

int go(int i, int j){
    
    if(!i && !j) return 0;
    if(i==0 || j==0 || i==j) return 1;
    
    int &ret = mem[i][j];
    if(ret+1) return ret;
    
    set<int> st;
    
    for(int ni = i-1; ni >= 1; ni--) if(ni != j){
        st.insert(go(ni, j));
    }
    
    for(int nj = j-1; nj >= 1; nj--) if(i != nj){
        st.insert(go(i, nj));
    }
    
    {
        int ni = i-1;
        int nj = j-1;
        while(ni >= 1 && nj >= 1){
            st.insert(go(ni, nj));
            ni--, nj--;
        }
    }
    
    int ans = 0;
    while(st.size() && (*st.begin() == ans)){
        st.erase(st.begin());
        ans++;
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
    
    int n;
    cin >> n;
    
    memset(mem, -1, sizeof mem);
    
    int Xor = 0;
    
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        if(l==0 || r==0 || l==r){
            Xor = 1;
            break;
        }
        Xor ^= go(l, r);
    }
    
    cout << (Xor ? "Y" : "N") << endl;
}
