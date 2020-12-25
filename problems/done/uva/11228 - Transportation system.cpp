// Problem: 11228 - Transportation system.
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2169
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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

int n, r;
pii arr[NMAX];

int par[NMAX];

int get_par(int u){
	return par[u] == u ? u : par[u] = get_par(par[u]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	int tt = 1;
    int t; cin >> t; while(t--){
    	
		cin >> n >> r;
		for(int i = 0; i < n; i++) 
			cin >> arr[i].first >> arr[i].second;
			
		
		vector< pair< double, pair<int, int> > > edges;
		
		for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++){
			double dist = sqrt( pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2));
			edges.push_back({dist, {i, j}});
		}
		
		
		sort(edges.begin(), edges.end());
		
		int cntc = 1;
		double totr = 0;
		double totb = 0;
		
		for(int i = 0; i < n; i++) par[i] = i;
		
		for(int i = 0; i < edges.size(); i++){
			
			double d = edges[i].first;
			int u = edges[i].second.first;
			int v = edges[i].second.second;
			
			int paru = get_par(u);
			int parv = get_par(v);
			
			if(paru != parv){
				
				if(d > double(r)){
					cntc++;
					totb += d;
				}
				else{
					totr += d;
				}
				
				if(rand() & 1){
					par[paru] = parv;
				}
				else{
					par[parv] = paru;
				}
			}
		}
		
		
		cout << "Case #" << tt++ << ": " << cntc << ' ' << round(totr) << ' ' << round(totb) << endl;
    }	
}
