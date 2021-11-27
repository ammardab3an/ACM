// Problem: C. Creating Multiples
// Contest: Codeforces - 2021-2022 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/103388/problem/C
// Memory Limit: 1024 MB
// Time Limit: 250 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include "bits/stdc++.h"

using namespace std;

#define ll  int64_t
#define int ll

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
const int MOD = 998244353;
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

const int  MAX = 5e5 + 10;
const int NMAX = 2e7 + 10;
const int MMAX = 2e7 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

        int a[MAX];

int32_t main(){
    fastIO
    
    int n, k;
    cin >> n >> k;
    
    vector <int> v(k);
    
    int s = 0;
    for (int i = 0;i < k; i++)
        cin >> v[i], s += (i % 2 == 0 ? 1 : -1) *  v[i];    
        
    s %= (n + 1);
    s = (s+n+1)%(n+1);
    
    if (s == 0) {
        cout << "0 0\n";
        return 0;
    }
    
    cout << s << endl;
    for (int i = 0; i < k;i++){
        
        if(i%2==0){
            if(v[i] >= s){
                cout << i+1 << ' ' << v[i]-s << endl;
                return 0;
            }
        }
        else{
            
            if(v[i] >= (n+1-s)){
                cout << i+1 << ' ' << v[i]-(n+1-s) << endl;
                return 0;
            }
        }
    }
    
    cout << "-1 -1";

}