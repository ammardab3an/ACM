// Problem: Friends with Problems
// Contest: CodeChef - Code Fest
// URL: https://www.codechef.com/CFST2021/problems/CFEST001
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

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

	int n;
	cin >> n;
	
	vector<string> vec(n);
	
	for(auto &s:vec) cin >> s;
	
	int ans = 1;
	
	int m = vec[0].size();
	for(int i = 0; i < m; i++){
		
		int cnt[3] = {0, 0, 0};
		
		for(int j = 0; j < n; j++){
			cnt[ vec[j][i] - '0' ]++;
		}
		
		if((cnt[0] && cnt[1]) || cnt[2]){
			ans *= 2;
			ans %= MOD;
		}
	}
	
	cout << ans << endl;
}
