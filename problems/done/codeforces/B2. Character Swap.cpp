// Problem: B2. Character Swap (Hard Version)
// Contest: Codeforces - Codeforces Round #599 (Div. 2)
// URL: https://codeforces.com/contest/1243/problem/B2
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

// #define endl '\n'
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
        
        string str[2];
        cin >> str[0] >> str[1];
        
        vi cnt(26);
        
        vector<vector<set<int>>> v_st(2, vector<set<int>>(26));
        
        for(int s : {0, 1})
        for(int i = 0; i < n; i++){
            v_st[s][str[s][i]-'a'].insert(i);
            cnt[str[s][i]-'a']++;
        }
        
        bool good = true;
        for(int i = 0; i < 26; i++) if(cnt[i]%2==1){
            good = false;
            break;
        }
        
        if(!good){
            cout << "No" << endl;
            continue;
        }
        
        vpii ans;
        
        for(int i = 0; i < n; i++){
            
            int c = str[0][i]-'a';
            v_st[0][c].erase(v_st[0][c].begin());
            
            if(v_st[1][c].size() && ((*v_st[1][c].begin())==i)){
                v_st[1][c].erase(v_st[1][c].begin());      
                continue;  
            }
            
            if(v_st[0][c].empty()){
                
                int j = *v_st[1][c].begin();
                v_st[1][c].erase(v_st[1][c].begin());
                
                int cc = str[0][j]-'a';
                v_st[0][cc].erase(v_st[0][cc].find(j));
                
                v_st[0][c].insert(j);
                v_st[1][cc].insert(j);
                
                str[0][j] = 'a'+c;
                str[1][j] = 'a'+cc;
                
                ans.push_back({j, j});
            }
            
            int cc = str[1][i]-'a';
            v_st[1][cc].erase(v_st[1][cc].begin());
            int j = *v_st[0][c].begin();
            v_st[0][c].erase(v_st[0][c].begin());
            v_st[0][cc].insert(j);
            str[0][j] = 'a'+cc;
            ans.push_back({j, i});
        }
        
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for(auto p : ans){
            cout << p.first+1 << ' ' << p.second+1 << endl;
        }
    }	
}
