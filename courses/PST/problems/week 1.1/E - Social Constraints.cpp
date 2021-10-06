
// Problem : E - Social Constraints
// Contest : Virtual Judge - Week # 1.1 [Complete search - Iterative&Recursive]- Easy~Medium
// URL : https://vjudge.net/contest/395176#problem/E
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
	
	int n, m;
	while(cin >> n >> m){
		
		if(!n && !m) break;
		
		vector<array<int, 3>> vec(m);
		for(int i = 0; i < m; i++) 
			cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
			
		int cnt = 0;
		vector<int> vec_n(n);
		for(int i = 0; i < n; i++) vec_n[i] = i;
		
		do{
			
			for(int i : vec_n) cout << i << ' '; cout << endl;
			
		}while(next_permutation(vec_n.begin(), vec_n.end()));
		
	}	
	
}
