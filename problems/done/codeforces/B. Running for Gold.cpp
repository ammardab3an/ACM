// Problem: B. Running for Gold
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/B
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
        
        vector<vi> vec(n, vi(5));
        
        for(auto &v : vec)
        for(auto &i : v) cin >> i;
        
        int ans = -1;
        vi ans_vec;
        
        vector<vi> cur = vec;
        
        while(true){
            
            int n = cur.size();
            int r = rand(0, n-1);
            
            vector<vi> ncur;
            
            for(int i = 0; i < n; i++) if(i != r){
                
                int cnt = 0;
                for(int j = 0; j < 5; j++) 
                    cnt += cur[i][j] < cur[r][j];
                
                if(cnt >= 3){
                    ncur.push_back(cur[i]);
                }
            }
            
            if(ncur.size()==0){
                ans = r+1;
                ans_vec = cur[r];
                break;
            }
            else{
                cur = ncur;
            }
        }
        
        if(ans != -1){
            
            int ans_pos = 0;
            while(vec[ans_pos] != ans_vec) ans_pos++;
        
            assert(ans_pos < n);
            
            for(int i = 0; i < n; i++) if(i != ans_pos){
                
                int ccnt = 0;
                for(int j = 0; j < 5; j++) 
                    ccnt += vec[i][j] < vec[ans_pos][j];
                 
                if(ccnt >= 3){
                    ans = -1;
                    break;
                }
            }
            
            if(ans != -1) ans = ans_pos+1;
        }
        
        cout << ans << endl;
    }	
}
