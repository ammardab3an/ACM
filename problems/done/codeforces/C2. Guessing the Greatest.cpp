// Problem: C2. Guessing the Greatest (hard version)
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/C2
// Memory Limit: 256 MB
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

// #define endl '\n'
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

map<pii, int> mem;
int ask(int l, int r){
    if(mem.find({l, r}) != mem.end()) return mem[{l, r}];
    cout << "? " << l << ' ' << r << endl;
    int pos;
    cin >> pos;
    return mem[{l, r}] = pos;
}

int32_t main(){

    fastIO;

    int n;
    cin >> n;

    int l = 1;
    int r = n;
    int sgn = 1;
    int pos = ask(l, r);

    if(pos != l)
    {
        int tl = l;
        int tr = pos;
        int rpos = ask(tl, tr);
        if(rpos == pos){
            r = pos;
            sgn = -1;
        }
        else{
            l = pos;
            sgn = +1;
        }
    }
    else{
        int tl = pos;
        int tr = r;
        int rpos = ask(tl, tr);
        if(rpos == pos){
            l = pos;
            sgn = +1;
        }
        else{
            r = pos;
            sgn = -1;
        }
    }

    int ans;
    int dl = 1;
    int dr = r-l;
    while(dl <= dr){
        int m = (dl+dr)/2;
        int rpos = ask(min(pos, pos+sgn*m), max(pos, pos+sgn*m));
        if(pos == rpos){
            ans = m;
            dr = m-1;
        }
        else{
            dl = m+1;
        }
    }

    cout << "! " << pos+sgn*ans << endl;
}
