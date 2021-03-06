
// Problem : G - Add All
// Contest : Virtual Judge - Week #1[STLs - Hard]
// URL : https://vjudge.net/contest/394529#problem/G
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
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
		
		vi vec(n);
		for(int &i : vec) cin >> i;
			
		priority_queue<int, vi, greater<int>> que;
		
		for(int i : vec) que.push(i);
		
		lli cost = 0;
		while(que.size() > 1){
			int st = que.top(); que.pop();
			int nd = que.top(); que.pop();
			que.push(st + nd);
			cost += st+nd;
		}
		
		cout << cost << endl;
	}
	
}
