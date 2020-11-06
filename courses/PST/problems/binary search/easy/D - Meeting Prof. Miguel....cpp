
// Problem : D - Meeting Prof. Miguel...
// Contest : Virtual Judge - Week #3.0 [Binary-search]  - Easy
// URL : https://vjudge.net/contest/397639#problem/D
// Memory Limit : 1024 MB
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

bool vis[2][30];
vpii adj[2][30];

int ansEng;
set<int> ans, ans_t;

void go(int c0, int c1, int eng){
	
	if(c0 == c1) ans_t.insert(c0);
	
	for(pii to : adj[1][c0]) if(eng >= to.second) if(!vis[1][to.first]){
		vis[1][to.first] = true;
		go(to.first, c1, eng - to.second);
		vis[1][to.first] = false;
	}
		
	for(pii to : adj[0][c1]) if(eng >= to.second) if(!vis[0][to.first]){
		vis[0][to.first] = true;
		go(c0, to.first, eng - to.second);
		vis[0][to.first] = false;
	}
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	int n;
	while(cin >> n, n){
		
		ansEng = -1;
		for(int i = 0; i < 2; i++)
		for(int j = 0; j < 30; j++) adj[i][j].clear();
		
		int sm = 0;
		
		for(int i = 0; i < n; i++){
			char type, dir, frm, to; int len;
			cin >> type >> dir >> frm >> to >> len;	
			adj[type == 'Y'][frm - 'A'].push_back({to - 'A', len});
			if(dir == 'B')
			adj[type == 'Y'][to - 'A'].push_back({frm - 'A', len});
			sm += len;	
		}
		
		char c0, c1;
		cin >> c0 >> c1;
		
		int l = 0;
		int r = sm;
		
		while(l <= r){
			int mid = (l+r)/2;
			ans_t.clear();
			go(c0 - 'A', c1 - 'A', mid);
			if(ans_t.size()){
				ans = ans_t;
				ansEng = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		
		if(ansEng != -1){
			cout << ansEng;
			for(int i : ans) cout << ' ' << char('A' + i);
			cout << endl;
		}
		else{
			cout << "You will never meet." << endl;
		}
	}
	
	
}
