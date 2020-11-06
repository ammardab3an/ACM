
// Problem : F - Hoax or what
// Contest : Virtual Judge - Week #1[STLs - Hard]
// URL : https://vjudge.net/contest/394529#problem/F
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
    	
    	lli sm = 0;
		multiset<int> st;
    	
		while(n--){
			
			int k; cin >> k; while(k--){
				int i; cin >> i; st.insert(i);
			}
			
			sm += *st.rbegin() - *st.begin();
			
			st.erase(st.begin());
			st.erase(prev(st.end()));
		}
		
		cout << sm << endl; 
    }	
	
}
