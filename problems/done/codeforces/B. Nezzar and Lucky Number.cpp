// Problem: B. Nezzar and Lucky Number
// Contest: Codeforces - Codeforces Round #698 (Div. 2)
// URL: http://codeforces.com/contest/1478/problem/B
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        int n, d;
        cin >> n >> d;
        
        vi vec(n);
        for(auto &i : vec) cin >> i;
        
        for(auto ai : vec){
            
            if(d == 1){
                cout << "YES" << endl;
                continue;
            }
            
            bool b = false;
            
            for(int i = 0; i < 10; i++){
                
                int tmp = ai - i * d;
                
                if(tmp < 0) break;
                
                while(tmp){
                    int cd = tmp % 10;
                    if(cd == d){
                        b = true;
                        break;
                    }
                    tmp /= 10;
                }
            }
            
            cout << (b||ai >= 10*d ? "YES" : "NO") << endl;
        }

    }	
}
