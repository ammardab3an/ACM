
// Problem : E - Conformity
// Contest : Virtual Judge - Week #1[STLs - Hard]
// URL : https://vjudge.net/contest/394529#problem/E
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef long long int       lli;
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
	
	int n; while(cin >> n){
		if(!n) break;
	
		vi vec(5);
		map<vi, int> mp;
		
		for(int i = 0; i < n; i++){
			for(int &i : vec) cin >> i;
			sort(vec.begin(), vec.end());
			mp[vec];
			mp[vec]++;	
		}
		
		
		int mx = 0;
		for(auto p : mp)
			mx = max(mx, p.second);
		
		int cnt = 0;
		for(auto p : mp) if(p.second == mx) cnt += p.second;
			
		cout << cnt << endl;		
	}	
	
}
