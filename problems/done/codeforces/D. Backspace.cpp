// Problem: D. Backspace
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/D
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
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 1e3 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        string str_a, str_b;
        cin >> str_a >> str_b;
        
        int n = str_a.size();
        int m = str_b.size();
        
        int lst[2] = {-1, -1};
        
        for(int i = 0; i < n; i+=2) if(str_a[i] == str_b[0]){
            lst[0] = i;
            break;
        }
        
        for(int i = 1; i < n; i+=2) if(str_a[i] == str_b[0]){
            lst[1] = i;
            break;
        }
        
        for(int i = 1; i < m; i++){
            
            int nlst[2] = {-1, -1};
            
            if(lst[0] != -1)
            for(int j = lst[0]+1; j < n; j+=2) if(str_a[j]==str_b[i]){
                nlst[1] = j;
                break;
            }    
            
            if(lst[1] != -1)
            for(int j = lst[1]+1; j < n; j+=2) if(str_a[j]==str_b[i]){
                nlst[0] = j;
                break;
            }
            
            lst[0] = nlst[0];
            lst[1] = nlst[1];
        }
        
        bool b0 = (lst[0] != -1) && ((n-lst[0]+1)%2==0);
        bool b1 = (lst[1] != -1) && ((n-lst[1]+1)%2==0);
        
        cout << (b0||b1 ? "YES" : "NO") << endl;
    }	
}
