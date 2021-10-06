
// Problem : B - Copying Books
// Contest : Virtual Judge - Week #3.0 [Binary-search]  - Easy
// URL : https://vjudge.net/contest/397639#problem/B
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

const int MAX = 500 + 10;

int m, k;
int p[MAX];

lli mx;
bool ans[MAX];

bool can(int pos, lli sm, int cnt){
	
	if(pos == m) 
		return cnt == k-1;
	
	bool t = ans[pos];
	
	if(sm + p[pos] <= mx){
		ans[pos] = false;
		if(can(pos+1, sm + p[pos], cnt)) return true;
	}
	
	if(sm + p[pos] > mx || (cnt + (m-pos) == k-1)){
		ans[pos] = true;
		if(can(pos+1, p[pos], cnt+1)) return true;
	}	
	
	ans[pos] = t;

	return false;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	int t; cin >> t; while(t--){
		
		memset(ans, 0, sizeof ans);
		
		cin >> m >> k;
		for(int i = 0; i < m; i++) cin >> p[i];
		reverse(p, p+m);
		
		lli l = 0;
		lli r = 0;
	
		for(int i = 0; i < m; i++) 
			l = max(l, (lli)p[i]), r += p[i];
		
		while(l <= r){
			mx = (l+r)/2;	
			if(can(0, 0, 0))
				r = mx-1;
			else
				l = mx+1;
		}
		

		for(int i = m-1; i >= 0; i--){
			cout << p[i]; 
			if(ans[i]) cout << " /";
			if(i) cout << ' ';
		}
		
		cout << endl;
	}
	
}
