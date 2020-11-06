
// Problem : B - Dollars
// Contest : Virtual Judge - Week #4.2 [DP #1] Easy
// URL : https://vjudge.net/contest/399816#problem/B
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

const int MAX = 8e3 + 10;

vi coins = {1, 5, 10, 25, 50};
int coinsSz = 5;
lli mem[15][MAX];

lli go(int pos, int n){
	
	if(!n) return 1;
	if(pos == coinsSz) return 0;
	
	lli & ret = mem[pos][n];
	if(ret != -1) return ret;
	
	lli ans = 0;
	if(pos < coinsSz)
		ans += go(pos+1, n);
	if(coins[pos] <= n)
		ans += go(pos, n-coins[pos]);
	
	return ret = ans;
}
int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL

    memset(mem, -1, sizeof mem);
    
    double i;
    while(cin >> i){
    	
		cout << go(0, i) << endl;
    }
		
}
