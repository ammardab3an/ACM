// Problem: Robot Path Decoding
// Contest: Google Coding Competitions - Round B 2020 - Kick Start 2020
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int add(int a, int b){
    const int mod = 1e9;
    return ((lli) a + b + mod + mod) % mod;
}
int mul(int a, int b){
    const int mod = 1e9;
    return ((lli) a * b) % mod;
}

pii go(string &str, int l, int r){
    
    pii ret = {0, 0};
    
    for(int i = l; i < r; i++){
        
        if(isdigit(str[i])){
            
            int nl = i+2;
            int nr = i+3;
            
            int cnt = 1;

            while(true) {
                if(str[nr] == '(') cnt++;
                if(str[nr] == ')') cnt--;
                if(!cnt) break;
                nr++;
            }
            
            pii tmp = go(str, nl, nr);
            
            ret.first = add(ret.first, mul(tmp.first, str[i]-'0'));
            ret.second = add(ret.second, mul(tmp.second, str[i]-'0'));
            
            i = nr;
        }
        else{
            
            char cc = str[i];
            
            if(cc == 'S') ret.first = add(ret.first, +1);
            if(cc == 'N') ret.first = add(ret.first, -1);
            if(cc == 'E') ret.second = add(ret.second, +1);
            if(cc == 'W') ret.second = add(ret.second, -1);
        }
    }    
    
    return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int tt = 1;
    int t; cin >> t; while(t--){
        
        string str;
        cin >> str;
        
        pii ans = go(str, 0, str.size());
        
        cout << "Case #" << tt++ << ": ";
        cout << ans.second+1 << ' ' << ans.first+1 << endl;
    }	
}
