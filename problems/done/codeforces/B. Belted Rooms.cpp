
// Problem : B. Belted Rooms
// Contest : Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1428/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

string str;

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	int t; cin >> t; while(t--){
		
		int n;
		cin >> n >> str;
		
		bool b0, b1;
		b0 = b1 = true;
		
		int cnt = 0;	
		
		for(int i = 0; i < n; i++){
			
			b0 &= (str[i] == '>') || (str[i] == '-');
			b1 &= (str[i] == '<') || (str[i] == '-');			
			cnt += (str[i] == '-') || (str[(i-1+n) % n] == '-');
		}
		
		if(b0 || b1)
			cout << n << endl;
		else
			cout << cnt << endl;
	}	
	
	
}
