// Problem: K. The Robot
// Contest: Codeforces - 2020-2021 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules)
// URL: https://codeforces.com/problemset/problem/1468/K
// Memory Limit: 512 MB
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
    
    map<char, pii> mv;
    mv['R'] = {+1, 0};
    mv['L'] = {-1, 0};
    mv['U'] = {0, +1};
    mv['D'] = {0, -1};
    
    int t; cin >> t; while(t--){
        
        string str;
        cin >> str;
        
        int n = str.size();
        
        pii pans;
        
        int ax = 0, ay = 0;
        
        for(int i = 0; i < n; i++){
            
            pii p = mv[str[i]];
            ax += p.first;
            ay += p.second;
            
            int x = 0, y = 0;
                
            for(int j = 0; j < n; j++){
                
                auto p = mv[str[j]];
                int nx = x + p.first;
                int ny = y + p.second;
                
                if(nx == ax && ny == ay) continue;
                
                x = nx;
                y = ny;
            }
            
            if(x == 0 && y == 0){
                pans = {ax, ay};        
            }
        }
        
        if(ax == 0 && ay == 0) pans = {1e9, 1e9};
        
        cout << pans.first << ' ' << pans.second << endl;
    }	    
}