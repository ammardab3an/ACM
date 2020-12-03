// Problem: 532 - Dungeon Master
// Contest: Virtual Judge - Week #8.1 [Dijkstra- BFS] Harder
// URL: https://vjudge.net/contest/406926#problem/B
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int l, r, c;
int si, sj, sk;
char dung[50][50][50];
int mvArr[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

bool can(int i, int j, int k){
	
	return 0 <= i && i < l &&
		   0 <= j && j < r &&
		   0 <= k && k < c;
}

int go(){
	
	bool vist[50][50][50];
	memset(vist, 0, sizeof vist);
	vist[si][sj][sk] = 1;
	
	queue< array<int, 4> > que;
	que.push({0, si, sj, sk});
	
	while(!que.empty()){
		
		auto fr = que.front(); que.pop();

		int cc = fr[0];
		int ci = fr[1];
		int cj = fr[2];
		int ck = fr[3];
		
		if(dung[ci][cj][ck] == 'E') return cc;
		
		for(auto a : mvArr){
			
			int ni = ci + a[0];
			int nj = cj + a[1];
			int nk = ck + a[2];
			
			if(can(ni, nj, nk) && dung[ni][nj][nk] != '#' && !vist[ni][nj][nk]){
				vist[ni][nj][nk] = 1;
				que.push({cc+1, ni, nj, nk});
			}
		}
	}
	
	return -1;
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif

	while(true){
		
		cin >> l >> r >> c;
		
		if(!l && !r && !c) break;
		
		for(int i = 0; i < l; i++)
		for(int j = 0; j < r; j++)
		for(int k = 0; k < c; k++){
			cin >> dung[i][j][k];
			if(dung[i][j][k] == 'S') si = i, sj = j, sk = k;
		}
		
		int dist = go();
		
		if(dist != -1)
			cout << "Escaped in " << dist << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
	}
}
