
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

const int MAX = 3e4 + 10;

vi coins = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
int coinsSz = 11;
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
    	
    	if(i == 0) break;
    	
    	int n = i*1000;
    	
    	if(n%10 >= 5) n += 10;
    	
    	n /= 10;
    	
    	cout << right << setw(6) << fixed << setprecision(2) << i;
		cout << right << setw(17) << go(0, n) << endl;
    }
		
}
