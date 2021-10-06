// Problem: C. Pursuit
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/C
// Memory Limit: 512 MB
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
    
    int t; cin >> t; while(t--){

        int n;
        cin >> n;
        
        vi a(n), b(n);
        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        vi pre_a(n), pre_b(n);
        
        pre_a[0] = a[0];
        pre_b[0] = b[0];
        for(int i = 1; i < n; i++){
            pre_a[i] = pre_a[i-1] + a[i];
            pre_b[i] = pre_b[i-1] + b[i];
        }
        
        auto good = [&](int mid){
            
            int tot = mid + n;
            int del = tot/4;
            
            int a_tot = mid * 100ll + pre_a[n-1];
            int b_tot = pre_b[n-1];
            
            if(del)
                a_tot -= pre_a[min(del, n)-1];
            
            int rem_a = max(del-n, (int)0);
            int rem_b = max(del-mid, (int)0);
            
            if(rem_a){
                a_tot -= rem_a * 100;
            }
            
            if(rem_b){
                b_tot -= pre_b[rem_b-1];
            }
            
            return b_tot <= a_tot;
        };
        
        int l = 0;
        int r = 4 * n;
        
        int ans = -1;
        
        while(l <= r){
            
            int mid = (l+r)/2;
            
            if(good(mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        cout << ans << endl;
    }	
}
