
// Problem : B - Team Queue
// Contest : Virtual Judge - Week #1[STLs - Hard]
// URL : https://vjudge.net/contest/394529#problem/B
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int MAX = 2e5 + 10;

array<vi, 1010> teams;
int wteam[1010101];

int main(){

    fastIO;
	
	int t, cnt = 1;
	while(cin >> t){
		
		if(!t) break;
		
		cout << "Scenario #" << cnt++ << endl;
		
		teams.fill({});
		memset(wteam, -1, sizeof wteam);
				
		for(int i = 0; i < t; i++){
			int n; cin >> n; teams[i].resize(n);
			for(int j = 0; j < n; j++) {
				cin >> teams[i][j];
				wteam[teams[i][j]] = i;
			}
		}
		
		deque<queue<int>> que;
		
		string com;
		while(cin >> com){
			if(com == "ENQUEUE"){
				int el; cin >> el;
				
				bool b = true;
				for(auto & q : que){
					if(wteam[q.front()] == wteam[el]){
						q.push(el);
						b = false;
						break;
					}
				}
				if(b){
					que.push_back(queue<int>());
					que.back().push(el);	
				}
				 
			}
			else if(com == "DEQUEUE"){
				cout << que.front().front() << endl;
				que.front().pop();
				if(que.front().empty()) que.pop_front();
			}
			else break;
		}
		
		cout << endl;
	}
}
