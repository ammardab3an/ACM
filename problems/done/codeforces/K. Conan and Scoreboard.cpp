// Problem: K. Conan and Scoreboard
// Contest: Codeforces - 2018 JUST Programming Contest 1.0
// URL: https://codeforces.com/gym/101778/problem/K
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
    
    int t; cin >> t; while(t--){

        int n, m, k;
        cin >> n >> m >> k;
        
        vi ans(n+1, -1), rfoo(m+1);
        vector<vi> rvis(m+1, vi(n+1)), rcnt(m+1, vi(n+1));
        
        int fst = -1;
        int lst = -1;
        int steady = 1;
        int steady_cnt = 0;
        int relent = 1;
        int relent_cnt = 0;
        
        vector<pair<int, array<int, 3>>> vec;
        
        for(int i = 0; i < k; i++){
            
            int p, id, res;
            cin >> p >> id >> res;
            
            string time_str;
            cin >> time_str;
            
            int time;
            
            {
                int time_min = 0;
                int time_sec = 0;
                
                int i = 0;
                while(time_str[i] != ':'){
                    time_min *= 10;
                    time_min += time_str[i++] - '0';
                }
                
                i++;
                while(i < 6){    
                    time_sec *= 10;
                    time_sec += time_str[i++] - '0';
                }
                
                time = time_min * 60 + time_sec;
            }
            
            vec.push_back({time, {p, id, res}});
        }
        
        sort(vec.begin(), vec.end());
        
        for(int i = 0; i < k; i++){
            
            int p = vec[i].second[0];
            int id = vec[i].second[1];
            int res = vec[i].second[2];
            
            if(res){
                
                if(fst == -1) fst = id;
                lst = id;
                
                if(ans[p] == -1){
                    ans[p] = id;
                }
                
                if(rcnt[id][p] == 0){
                    rfoo[id]++;    
                    if(rfoo[id] > steady_cnt){
                        steady = id;
                        steady_cnt = rfoo[id];
                    }
                    else if(rfoo[id] == steady_cnt){
                        steady = min(steady, id);
                    }
                }
                else{   
                    if(rcnt[id][p] > relent_cnt){
                        relent = id;
                        relent_cnt = rcnt[id][p];
                    }
                    else if(rcnt[id][p] == relent_cnt){
                        relent = min(relent, id);
                    }
                }
                
            }
            else{
                rcnt[id][p]++;
            }
            
        }
        
        for(int i = 1; i <= n; i++) cout << ans[i] << ' ' ; cout << endl;
        cout << fst << ' ' << lst << ' ' << steady << ' ' << relent << endl;
    }	
}
