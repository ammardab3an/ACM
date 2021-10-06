// Problem: E. Cheap Dinner
// Contest: Codeforces - Educational Codeforces Round 104 (Rated for Div. 2)
// URL: http://codeforces.com/contest/1487/problem/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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

int n[4];
int val[4][NMAX];
vi adj[4][NMAX];
multiset<int> st;

void add(int v){
	st.insert(v);	
}

void rem(int v){
	st.erase(st.find(v));	
}

int get(){
    if(st.empty()) return INF;
	return *st.begin();
}

void clear(){
	st.clear();	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    for(int i = 0; i < 4; i++)
		cin >> n[i];

    for(int i = 0; i < 4; i++)
	for(int j = 0; j < n[i]; j++)
		cin >> val[i][j];

	for(int i = 0; i < 3; i++){
		int m; cin >> m; while(m--){
			int u, v;
			cin >> u >> v; u--, v--;
			adj[i+1][v].push_back(u);
		}
	}


	for(int i = 1; i < 4; i++){

		clear();
		for(int j = 0; j < n[i-1]; j++) add(val[i-1][j]);

		for(int j = 0; j < n[i]; j++){
			for(int k : adj[i][j]) rem(val[i-1][k]);
			val[i][j] += get();
			for(int k : adj[i][j]) add(val[i-1][k]);
		}
		
	}
	
	int ans = *min_element(val[3], val[3] + n[3]);
	cout << (ans >= INF ? -1 : ans) << endl;	
}
