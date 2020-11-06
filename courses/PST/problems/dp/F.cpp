
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

const int MAX = 6100 + 10;

string str;
int mem[MAX][MAX];

int go(int i, int j){
	
	if(i > j) return 0;
	
	int &ret = mem[i][j];
	if(ret != -1) return ret;
	
	if(str[i] == str[j]) 
		return go(i+1, j-1);
	
	int stPath = go(i+1, j) + 1;
	int ndPath = go(i, j-1) + 1;
	
	return ret = min(stPath, ndPath);
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	
	int t; cin >> t; while(t--){
		cin >> str;
		memset(mem, -1, sizeof mem);
		cout << go(0, str.size()-1) << endl;
	}
	
}
