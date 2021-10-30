// Problem: D. Vupsen, Pupsen and 0
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/D
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
    
    int t; cin >> t; while(t--){

        int n; 
        cin >> n;
        
        vi vec(n);
        for(auto &i : vec) cin >> i;
        
        map<int, vi> mp;
        for(int i = 0; i < n; i++){
            mp[abs(vec[i])].push_back(i);
        }
        
        vi pos(n);
        
        {
            vi rst;
            int l = 0;
            int r = n-1;    
            
            for(auto p : mp){
                
                int ai = p.first;
                vi &v = p.second;
                
                for(int i = 0; i+1 < v.size(); i+=2){
                    
                    pos[l] = v[i];
                    pos[r] = v[i+1];
                    
                    l++, r--;
                }
                
                if(v.size()%2==1){
                    rst.push_back(v.back());
                }
            }    
            
    
            sort(rst.begin(), rst.end(), [&](int i, int j){
                return abs(vec[i]) < abs(vec[j]);
            });
            
            for(int i = 0; i+1 < rst.size(); i+=2){
                pos[l] = rst[i];
                pos[r] = rst[i+1];
                l++, r--;
            }
            
            if(rst.size()%2==1){
                pos[l] = rst.back();
            }
        }
        
        // for(auto i : pos) cout << vec[i] << ' '; cout << endl;
        
        vi ans(n);
        
        for(int i = 0; i < n/2; i++){
            
            int lcm = abs(vec[pos[n-i-1]]*vec[pos[i]]) / __gcd(abs(vec[pos[i]]), abs(vec[pos[n-i-1]]));
            
            ans[pos[i]] = lcm / vec[pos[i]];
            ans[pos[n-1-i]] = lcm / vec[pos[n-i-1]];
            
            int sm = ans[pos[i]]*vec[pos[i]] + ans[pos[n-1-i]]*vec[pos[n-i-1]];
            
            if(sm){
                ans[pos[i]] *= -1;
            }
        }
        
        if(n%2==1){
            
            int i = n/2;   
            int j = i-1;
            
            int lcm = abs(vec[pos[i]] * vec[pos[j]]) / __gcd(abs(vec[pos[i]]), abs(vec[pos[j]]));
            
            int a = lcm / vec[pos[i]];
            int b = lcm / vec[pos[j]];
            
            ans[pos[i]] += a;
            ans[pos[j]] -= b;
            
        }
        
        int sm = 0;
        int ms = 0;
        for(int i = 0; i < n; i++){
            sm += abs(ans[i]);
            ms += vec[i] * ans[i];
            assert(ans[i] != 0);
        }
        
        assert(sm <= 1e9);
        assert(ms == 0);
        
        for(auto i : ans) cout << i << ' '; cout << endl;
    }	
}
