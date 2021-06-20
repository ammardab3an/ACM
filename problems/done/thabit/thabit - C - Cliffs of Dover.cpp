
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>      iii;
typedef pair<ll, pll>      lll;
typedef vector<int>         vi;
typedef vector<ll>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

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
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
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
    
    int n, k, m;
    cin >> n >> k >> m;
    
    int sum = 0;
    bool found_0 = false;
    bool found_1 = false;
    bool all = true;
    
    for(int i = 0; i < n; i++){
        int ai, bi;
        cin >> ai >> bi;
        found_0 |= (ai%2) != (bi%2);
        found_1 |= (ai%2) == (bi%2);
        all &= (ai%2) != (bi%2);
        sum = (sum+(ai%2))%2;
    }
    
    if(!found_0){
        cout << (sum%2==m ? 1 : 2) << endl;
    }
    else if(all){
        cout << ((sum+k)%2==m ? 1 : 2) << endl;
    }
    else{
        
        if(sum%2==m){
            cout << ((sum+k-1)%2==m ? 1 : 2) << endl;
        }
        else{
            cout << ((sum+k)%2==m ? 1 : 2) << endl;
        }
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
