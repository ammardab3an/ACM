
// Problem : C. Producing Snow
// Contest : Codeforces - Codeforces Round #470 (rated, Div. 2, based on VK Cup 2018 Round 1)
// URL : https://codeforces.com/contest/948/problem/C
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

#define int int64_t

//#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 10;

int n;
int piles[MAX];
multiset<int> st;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
    
	cin >> n;
	for(int i = 0; i < n; i++) cin >> piles[i];
	
	int t = 0;
	int k = 0;
	
	for(int i = 0; i < n; i++){
		
		int rst = 0;
		
		int ct; cin >> ct;
		
		st.insert(piles[i] + t);
		
		while(st.size() && *st.begin() - (t + ct) <= 0){
			rst += *st.begin() - t;
			st.erase(st.begin());
			k++;
		}
		
		t += ct;
		
		cout << (i+1-k) * ct + rst << ' ';
	}	
	
}
