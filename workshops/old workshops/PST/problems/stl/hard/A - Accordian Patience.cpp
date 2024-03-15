
// Problem : A - "Accordian" Patience
// Contest : Virtual Judge - Week #1[STLs - Hard]
// URL : https://vjudge.net/contest/394529#problem/A
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

int main(){

    fastIO;
	
	stack<string> st[52];
	
	while(true){
		
		for(int i = 0; i < 52; i++) while(!st[i].empty()) st[i].pop();
		
		string str;
		cin >> str;
		if(str == "#") break;
		
		st[0].push(str);
		for(int i = 1; i < 52; i++){
			cin >> str;
			st[i].push(str);
		}
		
		while(true){

			bool b = true;
			
			for(int i = 1; i < 52; i++) if(!st[i].empty()){
				
				string tp = st[i].top();
				
				int nxt = i-1;
				while(nxt >= 0 && st[nxt].empty()) nxt--;
				
				int nxt_1 = nxt;
				
				nxt--; while(nxt >= 0 && st[nxt].empty()) nxt--;
				nxt--; while(nxt >= 0 && st[nxt].empty()) nxt--;
				
				if(nxt >= 0) {
					string nxt_3 = st[nxt].top();
					if(tp[0] == nxt_3[0] || tp[1] == nxt_3[1]){
						st[nxt].push(tp);
						st[i].pop();
						b = false;
						break;
					}
				}
				
				nxt = nxt_1;
				
				if(nxt >= 0){
					string nxt_1 = st[nxt].top();
					if(tp[0] == nxt_1[0] || tp[1] == nxt_1[1]){
						st[nxt].push(tp);
						st[i].pop();
						b = false;
						break;
					}	
				}
				
			}
			
			if(b) break;
		}
		
		vi cnt;
		for(int i = 0; i < 52; i++)
			if(!st[i].empty()) cnt.push_back(st[i].size());
		
		int sz = cnt.size();
		
		if(sz == 1)
			cout << sz << " pile remaining: ";
		else
			cout << sz << " piles remaining: ";
			
		for(int i = 0; i < sz; i++)
			cout << cnt[i] << (i+1 < sz ? " " : "");
		
		cout << endl;
	}
}
