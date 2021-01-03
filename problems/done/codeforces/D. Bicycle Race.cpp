// Problem: D. Bicycle Race
// Contest: Codeforces - Codeforces Round #346 (Div. 2)
// URL: https://codeforces.com/problemset/problem/659/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

typedef complex<int> pt;

int n;
pt arr[NMAX];

pt inputPt(){
	int x, y;
	cin >> x >> y;
	return {x, y};
}

double cross(pt v, pt w) {return (conj(v)*w).imag();}
double orient(pt a, pt b, pt c) {return cross(b-a, c-a);}

int isConvexCnt(pt * vp){
	int hasPos = 0, hasNeg = 0;
	for(int i = 0; i < n; i++){
		int o = orient(vp[i], vp[(i+1)%n], vp[(i+2)%n]);
		if(o > EPS) hasNeg++;
		if(o < -EPS) hasPos++;
	}
	return min(hasPos, hasNeg);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	
	cin >> n;
	for(int i = 0; i < n; i++) arr[i] = inputPt();
	cout << isConvexCnt(arr) << endl;
}
