
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

int n, m, mxCnt, k, arr[77][77];
lli mem[77][77][40][77];

lli go(int i, int j, int cnt, int rem){
	
	if(i >= n || j > m || cnt > mxCnt) return -INF;
	
	if(i == n-1 && j == m) return bool(rem) * -INF;
	
	lli & ret = mem[i][j][cnt][rem];
	if(~ret) return ret;
	
	lli stPath = go(i, j+1, cnt, rem);
	lli ndPath = go(i, j+1, cnt+1, (rem + arr[i][j]) % k) + arr[i][j];
	lli rdPath = go(i+1, 0, 0, rem);
	
	return ret = max({stPath, ndPath, rdPath});
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	cin >> n >> m >> k; mxCnt = m/2;
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++) cin >> arr[i][j];
	
	memset(mem, -1, sizeof mem);

	cout << go(0, 0, 0, 0);
	
}
