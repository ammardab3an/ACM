// Problem: Wandering Robot
// Contest: Google Coding Competitions - Round B 2020 - Kick Start 2020
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d8565
// Memory Limit: 1024 MB
// Time Limit: 15000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define lli int64_t

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

const int NMAX = 2e5 + 10;

double lg[NMAX];

void init(){
    for(int i = 1; i < NMAX; i++){
        lg[i] = lg[i-1] + log2(i);
    }    
}

double choose(int n, int c){
    return pow(2.0, lg[n] - lg[c] - lg[n-c] - n);
}

double calc(int n, int m){
    // double p = pow(0.5, n+m-2);
    double c = choose(n+m-2, n-1);
    return c;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    init();
    
    int tt = 1;
    int t; cin >> t; while(t--){
        
        int n, m;
        cin >> n >> m;
        
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        
        double ans = 0;
        
        if(y1+1 <= m){
            double pst = 0;
            for(int cx = 1; cx <= x0-1; cx++){
                ans -= pst * 0.5;
                pst = calc(cx, y1+1);
                ans += pst;
            }
        }
        
        if(x1+1 <= n){
            double pst = 0;
            for(int cy = 1; cy <= y0-1; cy++){
                ans -= pst * 0.5;
                pst = calc(x1+1, cy);
                ans += pst;
            }
        }
        
        cout << "Case #" << tt++ << ": ";
        cout << fixed << setprecision(7) << ans << endl;
    }	
}
