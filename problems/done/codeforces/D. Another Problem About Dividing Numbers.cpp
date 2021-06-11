// Problem: D. Another Problem About Dividing Numbers
// Contest: Codeforces - Codeforces Round #725 (Div. 3)
// URL: https://codeforces.com/contest/1538/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
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

vi primes;
bool notPrime[NMAX];
 
void init(){
    
    for(int i = 2; i < NMAX; i++) if(!notPrime[i]){
        primes.push_back(i);
        for(int j = i*i; j < NMAX; j += i)
            notPrime[j] = true;
    }    
}
 
 
int go(int a){
    
    int ret = 0;
    
    for(auto i : primes){
            
        if(i*i > a) break;
            
        while(a%i==0){
            ret++;
            a /= i;
        }
    }

    if(a != 1) ret++;
    
    return ret;
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
    
    int t; cin >> t; while(t--){

        int a, b, k;
        cin >> a >> b >> k;
        
        int cnt_a = go(a);
        int cnt_b = go(b);
        
        if(k > cnt_a+cnt_b){
            cout << "NO" << endl;
            continue;
        }
        
        if(k >= 2){
            cout << "YES" << endl;
            continue;
        }
        
        if((a%b==0 || b%a==0) && (a!=b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    
