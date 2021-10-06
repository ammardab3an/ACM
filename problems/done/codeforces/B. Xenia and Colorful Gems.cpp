// Problem: B. Xenia and Colorful Gems
// Contest: Codeforces - Codeforces Round #635 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1336/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
        
        int n[3];
        for(int i = 0; i < 3; i++)
            cin >> n[i];
        
        vpii vec;
        for(int i = 0; i < 3; i++)
        for(int j = 0; j < n[i]; j++){
            int xi;
            cin >> xi;   
            vec.push_back({xi, i});
        }
        
        sort(vec.begin(), vec.end());
        
        int ans = INFLL;
        
        int sz = vec.size();
        
        int cnt = 0;
        deque<int> que[3];
        
        int r = 0;
        for(int l = 0; l < sz; l++){
             
         if(l){
             que[vec[l-1].second].pop_front();
             if(que[vec[l-1].second].size()==0) cnt--;
         }
         
         while(cnt < 3 && r < sz){
             pii nxt = vec[r];
             if(!que[nxt.second].size()) cnt++;
             que[nxt.second].push_back(nxt.first);
             r++;
         }
         
         if(cnt != 3) break;
         
         int a = que[vec[l].second].back();
         int c = vec[r-1].first;
         
         int q = (vec[l].second+1)%3;
         if(q == vec[r-1].second) q = (q+1)%3;
         
         if(que[q].back() < a){
             a = que[q].back();
             q = vec[l].second;
         }
         
         int b = que[q].back();
         
         auto it = lower_bound(que[q].begin(), que[q].end(), (a+c)/2);
         
         if(it != que[q].end()){ 
            b = *it;
         }
         
         if(it != que[q].begin()){
             int nb = *(it-1);
             if(abs(2ll*nb-a-c) < abs(2ll*b-a-c)){
                 b = nb;
             }
         }    
         
         int cans = (a-b)*(a-b) + (a-c)*(a-c) + (b-c)*(b-c);     
         ans = min(ans, cans);
         
        }
        
        cout << ans << endl;
    }	
}
