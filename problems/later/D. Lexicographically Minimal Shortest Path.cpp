// Problem: D. Lexicographically Minimal Shortest Path
// Contest: Codeforces - 2020, XIII Samara Regional Intercollegiate Programming Contest
// URL: https://codeforces.com/gym/102569/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
vector< pair<int, char> > adj[NMAX];
pair<int, char> par[NMAX];
int dist[NMAX];

void dij(){

	for(int i = 0; i < n; i++) dist[i] = INF;
	dist[n-1] = 0;

	auto cmp = [](int idx0, int idx1){

		if(dist[idx0] != dist[idx1])
			return dist[idx0] > dist[idx1];
		
		while((idx0 != n-1) && (idx1 != n-1)){
			
			char c0 = par[idx0].second;
			char c1 = par[idx1].second;
			
			if(c0 != c1) 
				return c0 > c1;
			
			idx0 = par[idx0].first;
			idx1 = par[idx1].first;
		}

		return false;
	};
	
	auto cmp0 = [](int idx0, int idx1, char add){

		if(dist[idx0] != (dist[idx1] + (bool)add))
			return dist[idx0] > (dist[idx1] + (bool)add);
			
		if(par[idx0].second != add) 
			return par[idx0].second > add;
		
		idx1 = par[idx1].first;
		
		while((idx0 != n-1) && (idx1 != n-1)){
			
			char c0 = par[idx0].second;
			char c1 = par[idx1].second;
			
			if(c0 != c1) 
				return c0 > c1;
			
			idx0 = par[idx0].first;
			idx1 = par[idx1].first;
		}

		return false;
	};

	priority_queue< int, vector<int>, decltype(cmp) > que(cmp);

	que.push(n-1);

	while(!que.empty()){

		auto tp = que.top(); que.pop();

		int cnd = tp;
		
		for(auto nxt : adj[cnd]){

			int nxtNd = nxt.first;
			char nxtCh = nxt.second;

			if(cmp0(nxtNd, cnd, nxtCh)){

				par[nxtNd] = {cnd, nxtCh};
				dist[nxtNd] = dist[cnd]+1;

				que.push(nxtNd);
			}
		}
	}

}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v; char c;
		cin >> u >> v >> c; u--, v--;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}

	dij();

	string ans_str;
	vector<int> ans_nds;

	int cur = 0;
	while(cur != n-1){
		ans_nds.push_back(cur+1);
		ans_str.push_back(par[cur].second);
		cur = par[cur].first;
		assert(cur != par[cur].first);
	}

	ans_nds.push_back(n);

	cout << ans_str.size() << endl;
	for(auto nd : ans_nds) cout << nd << ' '; cout << endl;
	cout << ans_str << endl;
}
