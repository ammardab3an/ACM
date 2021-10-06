// Problem: M. ACPC Headquarters : AASTMT (Stairway to Heaven)
// Contest: Codeforces - 2015 ACM Syrian Collegiate Programming Contest
// URL: https://codeforces.com/gym/101086/problem/M
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
        
        map<string, vector<pair<string, pii> > > mp;
        
        for(int i = 0; i < n; i++){
            
            int s, e, v;
            string contest_name;
            cin >> contest_name >> s >> e >> v;
            
            for(int j = 0; j < v; j++){
                
                string volunteer_name;
                cin >> volunteer_name;
                
                mp[volunteer_name].push_back((pair<string, pii>){contest_name, {s, e}});
            }
        }
        
        vector<string> ans;
        
        for(auto p : mp){
            
            bool found = false;
            
            int sz = p.second.size();
            for(int i = 0; i < sz; i++){
                
                int s, e;
                s = p.second[i].second.first;
                e = p.second[i].second.second;
                
                for(int j = i+1; j < sz; j++){
                    
                    int ns, ne;
                    ns = p.second[j].second.first;
                    ne = p.second[j].second.second;
                    
                    bool b0 = s <= ns && ns <= e;
                    bool b1 = s <= ne && ne <= e;
                    bool b2 = ns <= s && s <= ne;
                    bool b3 = ns <= e && e <= ne;
                    
                    if(b0 || b1 || b2 || b3){
                        ans.emplace_back(p.first);
                        found = true;
                        break;
                    }
                }
                
                if(found) break;
            }
        }
        
        // just in case
        sort(ans.begin(), ans.end());
        
        cout << ans.size() << endl;
        for(auto s : ans) cout << s << endl;
    }	
}
