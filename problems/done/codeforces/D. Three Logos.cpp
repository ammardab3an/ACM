// Problem: D. Three Logos
// Contest: Codeforces - Codeforces Round #322 (Div. 2)
// URL: https://codeforces.com/contest/581/problem/D
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
    
    int w[3], h[3];
    int tot_area = 0;
    
    for(int i = 0; i < 3; i++){
        cin >> w[i] >> h[i];
        if(w[i] > h[i]) swap(w[i], h[i]);
        tot_area += w[i] * h[i];
    }
    
    int d = sqrt(tot_area);
    
    if((d*d != tot_area) || (h[0] > d) || (h[1] > d) || (h[2] > d) || !(h[0]==d || h[1]==d || h[2]==d)){
        cout << -1 << endl;
        return 0;
    }
    else{
        cout << d << endl;
    }
    
    vi pos = {0, 1, 2};
    
    sort(pos.begin(), pos.end(), [&](int i, int j){
        if(h[i] != h[j])
            return h[i] < h[j];
        return w[i] < w[j];
    });
    
    for(int i = 0; i < w[pos[2]]; i++){
        for(int j = 0; j < h[pos[2]]; j++){
            cout << char('A'+pos[2]);
        }
        cout << endl;
    }
    
    if((h[pos[1]] == d) && (h[pos[0]] == d)){
        for(int k : {0, 1})
        for(int i = 0; i < w[pos[k]]; i++){
            for(int j = 0; j < h[pos[k]]; j++){
                cout << char('A'+pos[k]);
            }
            cout << endl;
        }
    }
    else{
        
        if(h[pos[0]]+h[pos[1]] != d){
            swap(h[pos[0]], w[pos[0]]);
        }
        
        if(h[pos[0]]+h[pos[1]] != d){
            swap(h[pos[1]], w[pos[1]]);
        }
        
        if(h[pos[0]]+h[pos[1]] != d){
            swap(h[pos[0]], w[pos[0]]);
        }
        
        for(int i = 0; i < (d-w[pos[2]]); i++){
            
            for(int j = 0; j < d; j++){
                
                if(j < h[pos[1]]){
                    cout << char('A'+pos[1]);
                }
                else{
                    cout << char('A'+pos[0]);
                }
            }
            
            cout << endl;
        }
    }
}
