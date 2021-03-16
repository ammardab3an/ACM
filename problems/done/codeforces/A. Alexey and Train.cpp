// Problem: A. Alexey and Train
// Contest: Codeforces - Codeforces Round #707 (Div. 2, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1501/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

//typedef unsigned int        uint;
//typedef long long int       lli;
//typedef unsigned long long  ull;
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

        int n;
        cin >> n;

        vpii vec(n+1);
        for(int i = 1; i < n+1; i++) cin >> vec[i].first >> vec[i].second;

        vi tm(n+1);
        for(int i = 1; i < n+1; i++) cin >> tm[i];



        int ct = vec[1].first + tm[1];

        for(int i = 1; i < n; i++){

            int nt = max(ct + (vec[i].second - vec[i].first + 1)/2, vec[i].second);

            ct = nt + vec[i+1].first - vec[i].second + tm[i+1];

        }


        cout << ct << endl;

    }	
}
