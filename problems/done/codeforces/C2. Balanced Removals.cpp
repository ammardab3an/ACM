// Problem: C1. Balanced Removals (Easier)
// Contest: Codeforces - Codeforces Global Round 5
// URL: https://codeforces.com/problemset/problem/1237/C1
// Memory Limit: 512 MB
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

vector< array<int, 3> > points;

int solve(vi ids, int d){
	
	if(!d) return ids[0];
	
	map<int, vi> mp;
	for(int i : ids){
		mp[points[i][d-1]].push_back(i);
	}
	
	vi ans;
	for(auto p : mp){
		int cur = solve(p.second, d-1);
		if(cur != -1) ans.push_back(cur);
	}
	
	for(int i = 0; i+1 < ans.size(); i+=2){
		cout << ans[i]+1 << ' ' << ans[i+1]+1 << endl;
	}
	
	return ans.size()%2 ? ans.back() : -1;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	int n;
	cin >> n;
	
	points.resize(n);
	for(auto &p: points) for(auto &i: p) cin >> i;
	
	vi ids(n);
	iota(ids.begin(), ids.end(), 0);
	solve(ids, 3);
}
