
// Problem : F. Print Mix Strings
// Contest : Codeforces - 2015 Damascus Collegiate Programming Contest (DCPC 2015)
// URL : https://codeforces.com/gym/100883/problem/F
// Memory Limit : 64 MB
// Time Limit : 2000 ms
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

const int INF = 0x3f3f3f3f;
const int MAX = 1e4 + 10;
const int MOD = 1e9 + 7;

int szi, szj;
int mem[MAX][MAX];

int go(int i, int j){
	
	if(!i && !j)
		return 1;
		
	int & ret = mem[i][j];
	if(~ret) return ret;
	
	int ans = 0;
	if(i > 0) ans += go(i-1, j);
	if(j > 0) ans += go(i, j-1);
	ans %= MOD;
	
	return ret = ans;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
	    
	memset(mem, -1, sizeof mem);
	
	int t; cin >> t; while(t--){
		cin >> szi >> szj;
		cout << go(szi, szj) << endl;
	}
	
	
}
