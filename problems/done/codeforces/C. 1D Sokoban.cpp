// Problem: C. 1D Sokoban
// Contest: Codeforces - Educational Codeforces Round 105 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1494/problem/C
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

int calc(vi &a, vi &b){

    int n = a.size();
    int m = b.size();

    vector<int> suf(n+1);

    for(int i = n-1, j = m-1; i >= 0; i--){
        suf[i] = suf[i+1];
        while(j >= 0 && b[j] > a[i]) j--;
        if(j >= 0 && b[j] == a[i]) suf[i]++;
    }

    int ans = 0;

    int j = 0;
    for(int r = 0, l = 0; l < m; l++){

        while(j < n && a[j] <= b[l] + j) j++;
        while(r < m && b[r] - b[l] < j) r++;

        ans = max(ans, r - l + suf[j]);
    }

    return ans; 
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;
        
        vector<int> al, ar, bl, br;

        for(auto i : a){
            if(i > 0) ar.push_back(i);
            else al.push_back(-i);
        }

        for(auto i : b){
            if(i > 0) br.push_back(i);
            else bl.push_back(-i);
        }

        reverse(al.begin(), al.end());
        reverse(bl.begin(), bl.end());

        cout << calc(al, bl) + calc(ar, br) << endl;
    }	
}
