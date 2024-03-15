
// Problem : B - Matchmaker
// Contest : Virtual Judge - Week #2.1 [Greedy] easy ~ medium
// URL : https://vjudge.net/contest/396749#problem/B
// Memory Limit : 262 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


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
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int MAX = 2e5 + 10;

int main(){

    fastIO;

	int n, m; 
	cin >> n >> m;
	
	map<int, vi> markers;
	map<int, vi> caps;
	
	for(int i = 0; i < n; i++){
		int col, wid;
		cin >> col >> wid;
		markers[wid];
		markers[wid].push_back(col);
	}
	
	for(int i = 0; i < m; i++){
		int col, wid;
		cin >> col >> wid;
		caps[wid];
		caps[wid].push_back(col);
	}
	
	int cnt = 0;
	int bea = 0;
	
	for(auto p : markers){
		
		int wid = p.first;
		vi cols_m = p.second;
		
		if(caps.find(wid) != caps.end()){
			
			vi cols_c = caps[wid];
			
			sort(cols_m.begin(), cols_m.end());
			sort(cols_c.begin(), cols_c.end());
			
			cnt += min(cols_m.size(), cols_c.size());
			
			int i0 = 0;
			int i1 = 0;
			
			while(i0 < cols_m.size() && i1 < cols_c.size()){
	
				if(cols_m[i0] == cols_c[i1]){
					bea++; i0++; i1++;
				}	
				
				else if(cols_m[i0] < cols_c[i1]) i0++;
				else if(cols_m[i0] > cols_c[i1]) i1++;
			}
		}
		
		
	}
	
	cout << cnt << ' ' << bea << endl;
}
