// Problem: E. Let Them Slide
// Contest: Codeforces - Manthan, Codefest 19 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1208/problem/E
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
// int add(int a, int b){
	// return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
// }
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 1e6 + 10;

vpii add[NMAX], rem[NMAX];
multiset<int> st[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, w;
    cin >> n >> w;
    
    for(int i = 0; i < n; i++){
        
        int m;
        cin >> m;
        
        for(int j = 0; j < m; j++){
            
            int aij; 
            cin >> aij;
            
            add[j].push_back({i, aij});
            rem[j+w-m +1].push_back({i, aij});    
        }
        
        add[0].push_back({i, 0});
        rem[w-m-1 +1].push_back({i, 0});
        add[m].push_back({i, 0});
        rem[w-1 +1].push_back({i, 0});
    }
    
    int ans = 0;
    
    for(int j = 0; j < w; j++){
        
        for(auto p : add[j]){
            
            int i = p.first;
            int aij = p.second;
            
            ans -= (st[i].empty() ? 0 : *st[i].rbegin());
            st[i].insert(aij);
            ans += *st[i].rbegin();
        }
        
        for(auto p : rem[j]){
            
            int i = p.first;
            int aij = p.second;
            
            ans -= *st[i].rbegin();
            st[i].erase(st[i].find(aij));
            ans += (st[i].empty() ? 0 : *st[i].rbegin());
        }
        
        cout << ans << ' ';
    }
    
}
