// Problem: C. Longest Simple Cycle
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1476/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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
int arr[NMAX];
pii adj[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> n;
		for(int i = 0; i < n; i++) cin >> arr[i];	
		for(int i = 0; i < n; i++) cin >> adj[i].first;
		for(int i = 0; i < n; i++) cin >> adj[i].second;
		for(int i = 0; i < n; i++) if(adj[i].first > adj[i].second) swap(adj[i].first, adj[i].second);
		
		int ans = arr[n-1]-1 + 2;
		
		int h = adj[n-1].first;
		int l = adj[n-1].second;
		int cur = arr[n-1]-1 + 2;
		
		int i = n-2;
		
		while(i >= 0){
			
			ans = max(ans, cur + l-h); 
			
			if(l == h){
				cur = 0;
			}
			
			cur += h-1;
			cur += arr[i]-l;
			
			h = 1;
			l = arr[i];
			
			cur += 1;
			cur += 1;
			
			h = adj[i].first;
			l = adj[i].second;
			
			cur = max(cur, arr[i]-1+2);
			
			i--;
		}
		
		cout << ans << endl;
    }	
}
