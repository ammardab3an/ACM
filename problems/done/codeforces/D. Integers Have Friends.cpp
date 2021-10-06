// Problem: D. Integers Have Friends
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/D
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
 
const int NMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

int arr[NMAX];
int st[NMAX][LOG_MAX + 1];
int lg[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    lg[1] = 0;
    for(int i = 2; i < NMAX; i++){
        lg[i] = lg[i/2] + 1;
    }
    
    int t; cin >> t; while(t--){

        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++) 
            cin >> arr[i];
        
        n--;
        
        int N = n;
        int K = ceil(log2(double(n))) + 1;
        
        for (int i = 0; i < N; i++)
            st[i][0] = abs(arr[i+1] - arr[i]);
        
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = __gcd(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
                
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            
            int l = i;
            int r = n-1;
            
            int cans = i-1;
            
            while(l <= r){
                
                int mid = (l+r)/2;
                
                int L = i;
                int R = mid;
                
                int j = lg[R - L + 1];
                int res = __gcd(st[L][j], st[R - (1 << j) + 1][j]);
                
                if(res != 1){
                    ans = max(ans, mid-i+1);
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        
        cout << ans+1 << endl;        
    }	
}
