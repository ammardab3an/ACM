// Problem: E. Pchelyonok and Segments
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/E
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
        
        reverse(vec.begin(), vec.end());
        
        vi pre(n);
        pre[0] = vec[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + vec[i];
        }
        
        vpii lst(n);
        for(int i = 0; i < n; i++){
            lst[i] = {vec[i], i};
        }
        
        auto go = [](vpii &vec) -> void {
            
            sort(vec.begin(), vec.end(), [&](const pii &a, const pii &b){
                return a.first > b.first;
            });
            
            for(int i = 1; i < vec.size(); i++){
                vec[i].second = min(vec[i-1].second, vec[i].second);
            }
        };
        
        auto lb = [](vpii &vec, int val) -> int{
            
            int l = 0;
            int r = vec.size()-1;
            
            int ans = -1;
            
            while(l <= r){
                
                int mid = (l+r)/2;
                
                if(vec[mid].first > val){
                    ans = mid;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            
            return ans;
        };
        
        int len;
        for(len = 2; (len*(len+1))/2 <= n; len++){
            
            go(lst);
            
            vpii nlst;
            
            for(int i = 0; i+len-1 < n; i++){
                
                int csum = pre[i+len-1] - pre[i] + vec[i];
                int it = lb(lst, csum);
                if(it == -1) continue;
                
                if(lst[it].second < i){
                    nlst.push_back({csum, i+len-1});
                }
            }
            
            lst = nlst;
            
            if(lst.empty()){
                break;
            }
        }
        
        cout << len-1 << endl;
    }	
}
