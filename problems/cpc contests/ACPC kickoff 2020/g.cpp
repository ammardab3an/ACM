
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

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

//#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int MAX = 2e5 + 10;

int n, m;
int grid_a[111][111];
int grid_b[111][111];
bool vis[111];

int mem[111][111];
bool comp(int i, int j){
	
	int & ret = mem[i][j];
}

bool go(int pos){
	
	if(pos == n) return true;

	for(int i = 0; i < n; i++) if(!vis[i]){
		
		bool b = true;
		for(int j = 0; j < m; j++){
			if(grid_a[pos][j] % grid_b[i][j]){
				b = false;
				break;
			}		
		}
		
		if(b){
			vis[i] = true;
			if(go(pos+1)) return true;
			vis[i] = false;	
		}
	}
	
	return false;
}
int main(){
    
    fastIO;
    //freopen("grids.in", "r", stdin);
	
	int t; cin >> t; while(t--){

		memset(vis, 0, sizeof vis);
		    	
    	cin >> n >> m;
    	for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++) cin >> grid_a[i][j];	
    	for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++) cin >> grid_b[i][j];
    	
    	cout << (go(0) ? "YES" : "NO") << endl;
    }

	
	
}
