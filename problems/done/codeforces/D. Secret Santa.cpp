// Problem: D. Secret Santa
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/D
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
        
        vi vis(n);
        vi vec(n);
        vi org(n);
        
        for(int i = 0; i < n; i++){
            
            int ai;
            cin >> ai;
            ai--;
            
            org[i] = ai;
            
            if(vis[ai]){
                vec[i] = -1;
            }
            else{
                vec[i] = ai;
                vis[ai] = true;
            }
        }
        
        vi not_gift_rec_v;
        vi not_gift_v, not_rec_v;
        
        for(int i = 0; i < n; i++){
            
            if(vec[i]==-1 && !vis[i]){
                not_gift_rec_v.push_back(i);
            }
            else if(vec[i]==-1){
                not_gift_v.push_back(i);
            }
            else if(!vis[i]){
                not_rec_v.push_back(i);
            }
        }
        
        if(not_gift_rec_v.size() == 1){       
            
            if(!not_gift_v.size()){
                
                int f = not_gift_rec_v[0];
                int t = org[f];
                
                for(int j = 0; j < n; j++) if(vec[j] == t){
                    vec[j] = f;
                    break;
                }
                
                vec[f] = t;
            } 
            else{
                
                int f = not_gift_v.back();
                int t = not_rec_v.back();
                
                not_gift_v.pop_back();
                not_rec_v.pop_back();
                
                int m = not_gift_rec_v.back();
                
                vec[f] = m;
                vec[m] = t;
            }
            
        }
        
        int sz = not_gift_v.size();
        for(int i = 0; i < sz; i++){
            vec[not_gift_v[i]] = not_rec_v[i];
        }
        
        if(not_gift_rec_v.size() >= 2){
            int sz = not_gift_rec_v.size();
            for(int i = 0; i < sz; i++){
                vec[not_gift_rec_v[i]] = not_gift_rec_v[(i+1)%sz];
            }
        }
                
        int cnt = 0;
        for(int i = 0; i < n; i++) cnt += (org[i] == vec[i]);
        
        cout << cnt << endl;
        for(auto i : vec) cout << i+1 << ' ';
        cout << endl;
    }	
}
