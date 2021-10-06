// Problem: E. Two Small Strings
// Contest: Codeforces - Codeforces Round #582 (Div. 3)
// URL: https://codeforces.com/contest/1213/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    
    string c0, c1;
    cin >> c0 >> c1;
    
    bool found = false;
    
    if(c1[0]==c1[1]) swap(c0, c1);
    
    if(c0[0]==c0[1] && c1[0]==c1[1]){
        
        if(c0[0] != c1[0]){
            
            char c = 'a';
            while(c==c0[0] || c==c1[0]) c++;
            
            found = true;
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                cout << c0[0] << c1[0] << c;
            }    
        }
        else{
            
            found = true;
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                cout << c0[0] << char('a' + (c0[0]-'a'+1)%3) << char('a' + (c0[0]-'a'+2)%3);
            }
        }
    }
    else if(c0[0]==c0[1]){
        
        char c = 'a';
        while(c == c1[0] || c == c1[1]) c++;
        
        found = true;
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            cout << c1[0] << c << c1[1];
        }
    }
    else{
        
        string abc = "abc";
        
        do{
            
            if(abc[0] == c0[0] && abc[1] == c0[1]) continue;
            if(abc[1] == c0[0] && abc[2] == c0[1]) continue;
            if(abc[0] == c1[0] && abc[1] == c1[1]) continue;
            if(abc[1] == c1[0] && abc[2] == c1[1]) continue;
            
            found = true;    
            cout << "YES" << endl;
            cout << string(n, abc[0])+string(n, abc[1])+string(n, abc[2]) << endl;
            break;
            
        } while(next_permutation(abc.begin(), abc.end()));
    }
    
    assert(found);
}
