
// Problem : G - Easy Longest Increasing Subsequence
// Contest : Virtual Judge - Week #4.2 [DP #1] Easy
// URL : https://vjudge.net/contest/399816#problem/G
// Memory Limit : 1572 MB
// Time Limit : 1948 ms
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

const int MAX = 10 + 10;

int n;
int arr[MAX];
int mem[MAX][MAX];

int go(int pos, int lst){
	
	if(pos == n) return 0;
	
	int & ret = mem[pos][lst];
	if(ret != -1) return ret;
	
	int stPath = go(pos+1, lst);
	
	int ndPath = 0;
	if(arr[lst] < arr[pos])
		ndPath = go(pos+1, pos) + 1;
		
	return ret = max(stPath, ndPath);
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	
	while(cin >> n){
		for(int i = 1; i <= n; i++) cin >> arr[i]; n++; arr[0] = -1;
		memset(mem, -1, sizeof mem);
		cout << go(1, 0) << endl;
	}	
	
}
