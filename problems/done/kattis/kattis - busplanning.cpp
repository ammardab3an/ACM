// Problem: Bus Planning
// Contest: Kattis
// URL: https://open.kattis.com/problems/busplanning
// Memory Limit: 1024 MB
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

int n, m, k, sz;
bool cant[22][22];
int mem[1001000];
int vis[1001000];
vi sol;

void calc(int msk){
	if(mem[msk] == 1){
		sol.push_back(msk);
	}
	else{
		calc(msk ^ vis[msk]);
		calc(vis[msk]);
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	cin >> n >> m >> k;
	
	map<string, int> tran0;
	map<int, string> tran1;
	
	for(int i = 0; i < n; i++){
		string name;
		cin >> name;
		tran0[name] = i;
		tran1[i] = name;
	}
	
	for(int i = 0; i < m; i++){
		string u, v;
		cin >> u >> v;
		cant[tran0[u]][tran0[v]] = 1;
		cant[tran0[v]][tran0[u]] = 1;
	}
	
	memset(mem, INF, (1 << n) * sizeof(mem[0]));
	
	for(int i = 0; i < (1 << n); i++) if(__builtin_popcount(i) <= k){
		
		bool b = true;
		
		for(int j = 0; j < n && b; j++) if(i & (1 << j)){
			for(int k = j+1; k < n && b; k++) if(i & (1 << k)){
				if(cant[j][k]){
					b = false;
				}
			}
		}
		
		if(b){
			mem[i] = 1;
		}
	}
		
	for(int i = 0; i < (1 << n); i++){
		
		for(int j = i; j; j = (j-1) & i){
			
			if(mem[i] > mem[i^j] + mem[j]){
				mem[i] = mem[i^j] + mem[j];
				vis[i] = j;
			}
		}
	}
	
	calc((1 << n) -1);
	
	cout << sol.size() << endl;
	
	for(auto msk : sol){
		for(int i = 0; i < n; i++) if(msk & (1 << i)) 
			cout << tran1[i] << ' '; 
		cout << endl;
	}
}
