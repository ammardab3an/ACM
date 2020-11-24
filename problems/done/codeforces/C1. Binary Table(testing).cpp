
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
int grid[1010][1010];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        for(int j = 0; j < m; j++) grid[i][j] = str[j] - '0';
    }
    
    int q; cin >> q; while(q--){
		for(int i = 0; i < 3; i++){
			int x, y; cin >> x >> y;
			grid[x-1][y-1] = !grid[x-1][y-1];
		}
    }
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++) cout << grid[i][j];
    	cout << endl;
    }
}
