// Problem: D. Dogeforces
// Contest: Codeforces - Educational Codeforces Round 105 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1494/problem/D
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

int n;
int arr[555][555];
int ans[1010];
vpii out;

int go(vector<int> leaves){

    if(leaves.size() == 1)
        return leaves[0];

    int mx = -1;
    for(auto i : leaves) mx = max(mx, arr[leaves[0]][i]);

    vector<vector<int> > ch;
    ch.push_back({leaves[0]});

    for(int i = 1; i < leaves.size(); i++){
        
        int nd = leaves[i];
        int id = -1;

        for(int j = 0; j < ch.size(); j++){
            if(arr[nd][ch[j][0]] != mx){
                id = j;
                break;
            }
        }

        if(id == -1){
            id = ch.size();
            ch.push_back({});
        }

        ch[id].push_back(nd);
    }

    int v = n++;
    ans[v] = mx;

    for(int i = 0; i < ch.size(); i++){
        int u = go(ch[i]);
        out.emplace_back(u, v);
    }

    return v;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) cin >> arr[i][j];

    for(int i = 0; i < n; i++) ans[i] = arr[i][i];

    vector<int> leaves(n);
    iota(leaves.begin(), leaves.end(), 0);

    int root = go(leaves);

    cout << n << endl;

    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl << root+1 << endl;

    for(auto p : out)
        cout << p.first+1 << ' ' << p.second+1 << endl;

}