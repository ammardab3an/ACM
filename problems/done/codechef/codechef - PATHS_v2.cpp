// Problem: Number of Paths in a Grid
// Contest: CodeChef - Practice(Extcontest)
// URL: https://www.codechef.com/problems/PATHS
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

// #define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7, MOD2 = 999999937;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int mem[2][1010][1010];

void dp(){
    
    for(int i = 1; i <= 1000; i++)
        mem[0][i][1] = mem[0][1][i] = mem[1][i][1] = mem[1][1][i] = 1;
    
    for(int i = 2; i <= 1000; i++)
    for(int j = 2; j <= 1000; j++){
        mem[0][i][j] = (mem[0][i-1][j] + mem[0][i][j-1]) % MOD;
        mem[1][i][j] = (mem[1][i-1][j] + mem[1][i][j-1]) % MOD2;
    }
}

int conv(string num, int mod){
    int ret = 0;
    for(int i = 0; i < num.size(); i++){
        (ret *= 10LL) %= mod;
        (ret += num[i] - '0') %= mod;
    }
    return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    dp();
    
    int t; cin >> t; while(t--){
        
        string num_s;
        cin >> num_s;
        
        int num_i = conv(num_s, MOD);
        int num_i2 = conv(num_s, MOD2);
        
        vpii ans;
        for(int i = 1; i <= 1000; i++)
        for(int j = 1; j <= 1000; j++){
            if(mem[0][i][j] == num_i && mem[1][i][j] == num_i2)
                ans.emplace_back(i, j);
        }
        
        if(ans.empty()){
            cout << "The Grid is Too Big!" << endl;
        }
        else{
            cout << ans.size() << endl;
            for(auto p : ans)
                cout << p.first << ' ' << p.second << endl;
        }
    }
}
