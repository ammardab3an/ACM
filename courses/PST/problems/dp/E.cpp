
// Problem : E - Edit distance
// Contest : Virtual Judge - Week #4.2 [DP #1] Easy
// URL : https://vjudge.net/contest/399816#problem/E
// Memory Limit : 1572 MB
// Time Limit : 15000 ms
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

const int MAX = 2e3 + 10;

string str_0, str_1;
int sz_0, sz_1;
int mem[MAX][MAX];

int go(int pos_0, int pos_1){
	
	if(pos_0 == sz_0 || pos_1 == sz_1)
		return max(sz_0 - pos_0, sz_1 - pos_1);
	
	int & ret = mem[pos_0][pos_1];
	if(ret != -1) return ret;
	
	int mn = INT_MAX;
	
	if(str_0[pos_0] == str_1[pos_1])
		mn = go(pos_0 + 1, pos_1 + 1);
		
	int stPath = go(pos_0 + 1, pos_1) + 1;
	int ndPath = go(pos_0, pos_1 + 1) + 1;
	int rdPath = go(pos_0 + 1, pos_1 + 1) + 1;
	
	mn = min({mn, stPath, ndPath, rdPath});
	
	return ret = mn;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	
	int t; cin >> t; while(t--){
		cin >> str_0 >> str_1;
		sz_0 = str_0.size();
		sz_1 = str_1.size();
		memset(mem, -1, sizeof mem);
		cout << go(0, 0) << endl;
	}
	
}
