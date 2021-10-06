
// Problem : 11003 - Boxes
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1944
// Memory Limit : 32 MB
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

const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;

int n;
int weight[1010], mxLoad[1010];
int mem[1010][6060];

int go(int pos, int w){
	
	if(pos == n) return 0;
	
	int & ret = mem[pos][w];
	if(~ret) return ret;
	
	ret = go(pos+1, w);
	
	if(w - weight[pos] >= 0)
		ret = max(ret, go(pos+1, min(w-weight[pos], mxLoad[pos])) + 1);
	
	return ret;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	while(cin >> n){
		if(!n) break;
		for(int i = 0; i < n; i++) cin >> weight[i] >> mxLoad[i];
		memset(mem, -1, sizeof mem);
		cout << go(0, 6050) << endl;
	}
	
}
