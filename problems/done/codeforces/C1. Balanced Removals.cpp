// Problem: C1. Balanced Removals (Easier)
// Contest: Codeforces - Codeforces Global Round 5
// URL: https://codeforces.com/problemset/problem/1237/C1
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

struct point{
	int x, y, z;
	int dist2(point p){
		return pow(x-p.x, 2) + pow(y-p.y, 2) + pow(z-p.z, 2);
	}
};

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	int n;
	cin >> n;
	
	vector<point> points(n);
	for(auto &p: points) cin >> p.x >> p.y >> p.z;
	
	vector<bool> vist(n, 0);

	for(int i = 0; i < n; i++) if(!vist[i]){
		
		int mnPos = -1;
		int mnDist = INFLL;
		
		vist[i] = true;
		for(int j = 0; j < n; j++) if(!vist[j]){
			
			int ndist = points[i].dist2(points[j]);
			
			if(ndist < mnDist){
				mnPos = j;
				mnDist = ndist;
			}
		}
		
		vist[mnPos] = true;
		cout << i+1 << ' ' << mnPos+1 << endl;
	}
}
