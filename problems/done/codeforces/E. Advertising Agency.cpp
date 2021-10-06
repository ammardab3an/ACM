// Problem: E. Advertising Agency
// Contest: Codeforces - Codeforces Round #697 (Div. 3)
// URL: https://codeforces.com/contest/1475/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int k, n;
int arr[1010];
int fact[1010];

int fast_pow(int n, int p){
	if(!p) return 1;
	if(p&1) return (n * fast_pow(n, p-1)) % MOD;
	int tmp = fast_pow(n, p/2);	
	return (tmp * tmp) % MOD;
}

int get_fact(int n){
	if(n < 1) return 1;
	if(fact[n]) return fact[n];
	return fact[n] = (n * get_fact(n-1)) % MOD;
}

int choose(int n, int r){

	return (
				(
					(get_fact(n) * fast_pow(get_fact(r), MOD-2)) % MOD
				) 	
					* fast_pow(get_fact(n-r), MOD-2)
			) % MOD;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		sort(arr, arr+n, greater<int>());
		
		int mx = 0;
		for(int i = 0; i < k; i++) mx += arr[i];
		
		int tot = 0;
		int cnt = 0;
		
		int ai = arr[k-1];
		
		for(int i = k; i < n && arr[i] == ai; i++) tot++;
		for(int i = k-1; i >= 0 && arr[i] == ai; i--) tot++, cnt++;
		
		if(2 * cnt > tot) cnt = tot-cnt;
		
		cout << choose(tot, cnt) << endl;
    }	
}
