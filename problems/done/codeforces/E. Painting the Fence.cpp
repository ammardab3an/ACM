// Problem: E. Painting the Fence
// Contest: Codeforces - Training Contest 5
// URL: https://codeforces.com/group/FqtJd4zMPb/contest/310836/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const int NMAX = 3e5 + 10;

int n;
int arr[NMAX];
bool vis[NMAX];
set<int> st[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		st[arr[i]].insert(i);
	}
	
	int q; cin >> q; while(q--){

		int c; cin >> c;
		
		if(vis[c] || st[c].size() < 2) continue;
		
		int l = *st[c].begin();
		int r = *st[c].rbegin();
		
		for(int i = l+1; i < r; i++){
			st[arr[i]].erase(i);
			if(vis[arr[i]] && !st[arr[i]].empty()){
				i = *st[arr[i]].begin() -1;
			}
		}
		
		vis[c] = true;
	}

	for(int i = 1; i < NMAX; i++){
		
		if(vis[i] && st[i].size() > 1){
		
			int l = *st[i].begin();
			int r = *st[i].rbegin();
			
			for(int j = l+1; j < r; j++) arr[j] = i;
		}
	}
	
	for(int i = 0; i < n; i++) cout << arr[i] << ' '; cout << endl;
}
