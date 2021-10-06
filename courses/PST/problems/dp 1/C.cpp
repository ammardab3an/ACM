
// Problem : C - Tetrahedron
// Contest : Virtual Judge - Week #5.0 DP [Medium]
// URL : https://vjudge.net/contest/401749#problem/C
// Memory Limit : 262 MB
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

const int MAX = 1e7 + 10;
const int MOD = 1e9 + 7;

int mem[4][MAX];

int go(int pos, int k){
	
	if(!k) return !pos;
	
	int & ret = mem[pos][k];
	if(~ret) return ret;
	
	int sm = 0;
	for(int i = 0; i < 4; i++) if(i != pos){
		sm = (sm + go(i, k-1)) % MOD;
	}
	
	return ret = sm;
}
int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	int n; cin >> n;
	memset(mem, -1, sizeof mem);
	cout << go(0, n);
	
	
}
