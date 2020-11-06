
// Problem : A - Princess Farida
// Contest : Virtual Judge - Week #4.2 [DP #1] Easy
// URL : https://vjudge.net/contest/399816#problem/A
// Memory Limit : 1572 MB
// Time Limit : 1237 ms
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

int n;
int arr[MAX];
lli mem[MAX];

lli go(int pos){
	
	if(pos >= n) return 0;
	
	lli & ret = mem[pos];
	if(ret != -1) return ret;
	
	lli stPath = go(pos+1);
	lli ndPath = go(pos+2) + arr[pos];
	
	return ret = max(stPath, ndPath);
}
int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	int t; cin >> t; for(int tt = 0; tt < t; tt++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> arr[i];
		memset(mem, -1, sizeof mem);
		cout << "Case " << tt+1 << ": " << go(0) << endl;
	}
	
	
}
