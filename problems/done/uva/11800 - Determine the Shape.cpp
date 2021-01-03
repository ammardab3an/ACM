// Problem: E - Determine the Shape
// Contest: Virtual Judge - Basic Geometry
// URL: https://vjudge.net/contest/405410#problem/E
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
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
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

struct point{
	int x, y;
};

typedef point gvector;

gvector gvec(point p0, point p1){
	return {p1.x - p0.x, p1.y - p0.y};
}

double cross(gvector v0, gvector v1){
	return v0.x*v1.y - v1.x*v0.y;
}

double dot(gvector v0, gvector v1){
	return v0.x*v1.x + v0.y*v1.y;
}

double dist2(point p0, point p1){
	return pow(p0.x-p1.x, 2) + pow(p0.y-p1.y, 2);	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; for(int tt = 1; tt <= t; tt++){

		point pnt[4];
		for(int i = 0; i < 4; i++) cin >> pnt[i].x >> pnt[i].y;
		
		auto cmpAng = [pnt](const point & p0, const point & p1){
			gvector n = gvec(pnt[0], p0);
			gvector m = gvec(pnt[0], p1);
			return atan2(n.y, n.x) < atan2(m.y, m.x);	
		};
		
		sort(pnt+1, pnt+4, cmpAng);
		
		double len[4];
		for(int i = 0; i < 4; i++) len[i] = dist2(pnt[i], pnt[(i+1)%4]);
		
		bool right = dot(gvec(pnt[0], pnt[1]), gvec(pnt[0], pnt[3])) == 0;
		
		string ans = "Ordinary Quadrilateral";
		
		if(len[0] == len[1] && len[1] == len[2] && len[2] == len[3]){
			ans = right ? "Square" : "Rhombus";
		}
		else if(len[0] == len[2] && len[1] == len[3]){
			ans = right ? "Rectangle" : "Parallelogram";
		}
		else if(cross(gvec(pnt[0], pnt[1]), gvec(pnt[2], pnt[3])) == 0 || 
				cross(gvec(pnt[0], pnt[3]), gvec(pnt[1], pnt[2])) == 0){
			ans = "Trapezium";
		}
				
		cout << "Case " << tt << ": ";
		cout << ans << endl;
    }	
}
