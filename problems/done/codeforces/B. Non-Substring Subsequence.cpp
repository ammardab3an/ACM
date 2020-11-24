// Problem: B. Non-Substring Subsequence
// Contest: Codeforces - Codeforces Round #685 (Div. 2)
// URL: https://codeforces.com/contest/1451/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int l, r;
char str[110];
int mem[110][110][2];

int go(int i, int j, bool b){
	
	if(j == r+1) return b;
	if(i == n) return 0;
	
	int & ret = mem[i][j][b]; 
	if(ret + 1) return ret;
	
	int ans = 0;
	
	if(go(i+1, j, (j!=l) || b)) 
		ans = 1;

	if(str[i] == str[j]){	
		if(go(i+1, j+1, b))
			ans = 1;
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		int q;
		cin >> n >> q;
		
		cin >> str;
		
		while(q--){
			cin >> l >> r; l--; r--;
			memset(mem, -1, sizeof mem);
			cout << ((r-l+1 >= 2) && go(0, l, 0) ? "YES" : "NO") << endl;
		}
		
//		cout << endl;
    }	
}
