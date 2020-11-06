
// Problem : I - Lotto
// Contest : Virtual Judge - Week # 1.1 [Complete search - Iterative&Recursive]- Easy~Medium
// URL : https://vjudge.net/contest/395176#problem/I
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

int n;
int arr[20];

int ans[6];
void go(int pos, int cnt){
	
	if(cnt == 6){
		for(int i = 0; i < 6; i++) cout << ans[i] << (i < 5 ? " " : "");
		cout << endl;
		return;
	}
	
	if(pos == n) return;
	
	ans[cnt] = arr[pos];
	go(pos+1, cnt+1);
	
	go(pos+1, cnt);
}

int main(){

    fastIO;
	
	bool b = false;
	while(cin >> n){
			
		if(!n) break;
		if(b++) cout << endl;
		
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		go(0, 0);
	}	
	
}
