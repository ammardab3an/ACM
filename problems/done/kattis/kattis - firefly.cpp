// Problem: A - Firefly
// Contest: Virtual Judge - Session 3 Sheet - [BS, TS, Prime, Fibonacci, binomial coefficients, GCD and lCM]
// URL: https://vjudge.net/contest/422448#problem/A
// Memory Limit: 1048 MB
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

const int NMAX = 2e5 + 10;
const int HMAX = 5e5 + 10;

int n, h;
int cum[2][HMAX];
int ans[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> h;
    
    for(int i = 0; i < n; i++){
    	
    	int x;
    	cin >> x;
    	
    	cum[i&1][x]++;	
    }
    
    for(int i = h-1; i >= 0; i--){
    	cum[0][i] += cum[0][i+1];
    	cum[1][i] += cum[1][i+1];
    }
    
    memset(ans, -1, (n+1) * sizeof(ans[0]));
    
    for(int lvl = 1; lvl <= h; lvl++){
		int val = cum[0][lvl] + cum[1][h-lvl+1];
		ans[val] += 1 + bool(ans[val] == -1);
    }
    
	for(int i = 0; i <= n; i++) if(ans[i] != -1){
		cout << i << ' ' << ans[i] << endl;
		break;
	}
}
