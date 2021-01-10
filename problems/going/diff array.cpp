
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

    int n, q;
    cin >> n >> q;
	
	vi vec(n);
	for(int &i : vec) cin >> i;
	
	vi diff(n);
	diff[0] = vec[0];
	for(int i = 1; i < n; i++) diff[i] = vec[i] - vec[i-1];
	
	while(q--){
		int l, r, x;
		cin >> l >> r >> x;
		diff[l] += x;
		diff[r+1] -= x;
	}
	
	for(int cur = 0, i = 0; i < n; i++) {
		cur += diff[i];
		cout << cur << ' ';
	} cout << endl;
	
}
