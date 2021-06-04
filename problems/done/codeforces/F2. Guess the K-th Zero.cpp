// Problem: F2. Guess the K-th Zero (Hard version)
// Contest: Codeforces - Codeforces Round #719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/F2
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)



// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

typedef unsigned int		uint;
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

//#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int NMAX = 2e5 + 10;

int n, t;
int tree[NMAX << 2];

int que(int nd, int l, int r){

    if(tree[nd] != -1) return tree[nd];

    cout << "? " << l << ' ' << r << endl;
    int res;
    cin >> res;
    assert(res != -1);
    return tree[nd] = res;
}

int print(int res){
    cout << "! " << res << endl;
}

void query(int nd, int l, int r, int k, int &ans){

    if(l == r){
        ans = l;
        tree[nd] = 1;
        return;
    }

    int mid = (l+r)/2;

    if(((mid-l+1) - que(nd*2, l, mid)) >= k){
        query(nd*2, l, mid, k, ans);
    }
    else{
        query(nd*2+1, mid+1, r, k - ((mid-l+1) - que(nd*2, l, mid)), ans);
    }

    tree[nd]++;
}

int32_t main(){

    cin >> n >> t;

    memset(tree, -1, sizeof tree);

    while(t--){

        int k;
        cin >> k;

        int cans = -1;
        query(1, 1, n, k, cans);

        print(cans);
    }
}
