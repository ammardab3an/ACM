// Problem: B. Planet Lapituletti
// Contest: Codeforces - Codeforces Round #705 (Div. 2)
// URL: https://codeforces.com/contest/1493/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

        int h, m;
        cin >> h >> m;

        string ln;
        cin >> ln;

        int ch = (ln[1] -'0') + (ln[0]-'0') * 10;
        int cm = (ln[4]-'0') + (ln[3]-'0') * 10;

        auto good = [](int num){

            bool tmp[10] = {0};

            tmp[0] = tmp[1] = tmp[2] = tmp[5] = tmp[8] = 1;

            return tmp[num/10] && tmp[num%10];
        };
        
        int tmp[10] = {0};

        tmp[2] = 5;
        tmp[5] = 2;
        tmp[1] = 1;
        tmp[0] = 0;
        tmp[8] = 8;
            
        bool found = false;

        int nh = ch;
        int nm = cm;
        
        for(int i = 0; i <= h && !found; i++, nh = (nh+1)%h){
            
            for(; nm < m && !found; nm++){
                
                int cur_h = nh;
                int cur_m = nm;
                
                // cout << cur_h << ' ' << cur_m << endl;
                
                if(good(cur_h) && good(cur_m)){

                    int mir_h = (tmp[cur_m%10])*10 + (tmp[cur_m/10]);
                    int mir_m = (tmp[cur_h%10])*10 + (tmp[cur_h/10]);

                    // cout << endl ;
                    // cout << cur_h << ' ' << mir_m << endl;;
                    // cout << cur_m << ' ' << mir_h << endl;;
                    
                    if(mir_h < h && mir_m < m){

                        string out;
                        out.push_back('0' + cur_h/10);
                        out.push_back('0' + cur_h%10);
                        out.push_back(':');
                        out.push_back('0' + cur_m/10);
                        out.push_back('0' + cur_m%10);

                        cout << out << endl;

                        found = true;
                    }
                }
            }
            
            nm = 0;
        }

    }	
}