
// Problem : D - Candy
// Contest : Virtual Judge - Week #4.2 [DP #1] Easy
// URL : https://vjudge.net/contest/399816#problem/D
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

const int MAX = 1e5 + 10;

int n, m;
lli tmp[MAX];
lli mem[MAX];
lli mxRow[MAX];

lli go(int i, int sz, lli * arr){
	
	if(i >= sz) return 0;
	
	lli & ret = mem[i];
	if(ret != -1LL) return ret;
	
	lli stPath = go(i+2, sz, arr) + arr[i];
	lli ndPath = go(i+1, sz, arr);
	
	return ret = max(stPath, ndPath);
}

int main(){
    
    fastIO;
    
	while(cin >> n >> m){
		
		if(!n && !m) break;
		
		for(int i = 0; i < n; i++){
		
			for(int j = 0; j < m; j++) cin >> tmp[j];
			
			memset(mem, -1LL, sizeof mem);
			mxRow[i] = go(0, m, tmp);
		}
		
		memset(mem, -1LL, sizeof mem);
		cout << go(0, n, mxRow) << endl;
	}
		
}
