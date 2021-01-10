// Problem: E. Distinctive Roots in a Tree
// Contest: Codeforces - Codeforces Round #695 (Div. 2)
// URL: https://codeforces.com/contest/1467/problem/E
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
vi adj[NMAX];
map<int, set<int> > mp;
int vist[NMAX];
bool ans[NMAX];

int visfoo = 0;
bool sp = 0;
int beg;

bool dfs(int nd, int col, bool b, bool bb){
	
	if(sp) return 1;
	
	if(b) ans[nd] = 1;
	
	vist[nd] = visfoo;
	
	bool ret = b;
	bool pst = 0;
	
	for(int nxt : adj[nd]) if(vist[nxt] != visfoo){
		
		bool nbb = mp[col].count(nxt);
		
		if(nd != beg && b && nbb) return sp = 1;
		
		bool tmp = dfs(nxt, col, b || nbb, nbb);

		if(tmp && nd == beg) vist[nxt] = visfoo+1;

		if((bb && pst && tmp) || (bb && nbb)) return sp = 1;
		
		pst |= tmp, ret += tmp;
	}
	
	if(ret && nd == beg && !b){
		visfoo++;
		dfs(nd, col, 1, 1);
	}
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n; i++){
    	int col; 
    	cin >> col;
    	mp[col].insert(i);
    }
    
    for(int i = 0; i < n-1; i++){
    	int u, v; 
    	cin >> u >> v; u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }    

    for(auto p : mp){
    	
    	if(sp) break;
    	if(p.second.size() < 2) continue;
    	
    	int stNd = *p.second.begin();
    	int ndNd = *p.second.rbegin();
    	
    	visfoo += 2;
    	dfs(beg = stNd, p.first, 0, 1);
    }
    
    int cnt = n * (!sp);
    if(!sp) for(int i = 0; i < n; i++) cnt -= ans[i];
    cout << cnt << endl;
}
