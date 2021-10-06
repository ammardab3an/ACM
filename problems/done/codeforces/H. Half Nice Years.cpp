// Problem: H. Half Nice Years
// Contest: Codeforces - Egyptian Collegiate Programming Contest 2017 (ACM ECPC 2017) - original tests edition
// URL: https://codeforces.com/gym/101856/problem/H
// Memory Limit: 1024 MB
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

    freopen("halfnice.in", "r", stdin);
    
    int tt = 0;
    int t; cin >> t; while(t--){
        
        cout << "Case " << ++tt << ": ";
        
        int a, b;
        cin >> a >> b;
        
        string b_str = to_string(b);
        
        int len = b_str.size();
        
        int x, y;
        x = stoll(b_str.substr(0, len/2));
        y = stoll(b_str.substr(len/2));
        
        // cout << x << ' ' << y << endl;
        
        beg:;
        
        if(y==0){
            x--;
            int tmp = (len+1)/2;
            int ny = 0;
            while(tmp--) ny *= 10, ny += 9;
            y = ny;
        }
        
        if(x%2==0){
            if(__gcd(x, y)==1) y--;
            if(y==0) goto beg;
            int sm = x*pow(10, (len+1)/2) + y;
            a <= sm ? cout << sm : cout << "impossible";
            cout << endl;
        }
        else{
            
            int mx = 0;
            
            for(int i = 2; i*i <= x; i++) if(x%i==0){
                
                for(auto d : {i, x/i}){
                    int ny = (y/d) * d;
                    mx = max(mx, ny);
                }
            }
            
            if(x > 1)
            for(auto d : {x}){
                int ny = (y/d) * d;
                mx = max(mx, ny);
            }
            
            if(mx==0){
                
                x--;
                
                int tmp = (len+1)/2;
                
                int ny = 0;
                while(tmp--) ny *= 10, ny += 9;
                y = ny;
                
                if(__gcd(x, y)==1) y--;
                int sm = x*pow(10, (len+1)/2) + y;
                a <= sm ? cout << sm : cout << "impossible";
                cout << endl;
            }
            else{
                int sm = x*pow(10, (len+1)/2) + mx;
                a <= sm ? cout << sm : cout << "impossible";
                cout << endl;
            }
        }
    }	
}
