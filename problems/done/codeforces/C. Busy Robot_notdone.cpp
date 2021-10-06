// Problem: C. Busy Robot
// Contest: Codeforces - Educational Codeforces Round 100 (Rated for Div. 2)
// URL: http://codeforces.com/contest/1463/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
pii arr[NMAX];
int tmp[NMAX];

vector<pair<pii, pii> > poss;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> n;
		
		for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
		
		//arr[n] = {INF, arr[n-1].second}; n++;
		
		for(int i = 0; i < n; i++) tmp[i] = arr[i].first;
		
		int ans = 0;
		
		int ct = 0;
		int cp = 0;
			
		poss.clear();
		
		while(true){
			
			
			//cout << cp << ' ' << ct << endl;
			
			int nxt = lower_bound(tmp, tmp+n, ct) - tmp;
			
			if(nxt == n) break;
			
			int nct = arr[nxt].first + abs(cp - arr[nxt].second);
			
			int ncp = arr[nxt].second;
			
			poss.push_back({{ct, nct}, {cp, ncp}});
			
			ct = nct;
			cp = ncp;
		}
		
		arr[n] = {INF, arr[n-1].second}; n++;
		tmp[n] = INF;
		poss.push_back({{ct, INF}, {cp, cp}});
		
		if(false) 
		for(auto p : poss){
			cout << p.first.first << ' ' << p.first.second << ' ' << p.second.first << ' ' << p.second.second << endl;
		}
		
		int j = 0;
		
		for(int i = 0; i < n; i++){
						
			int pos = arr[i].second;
			
			int tm = arr[i].first;
			int tp = arr[i+1].first;
			
			
			vector< pair<pii, pii> > bp, ap;
			
			
		}
		
		
		cout << ans << endl;
    }	
}
