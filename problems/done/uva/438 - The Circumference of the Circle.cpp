// Problem: A - The Circumference of the Circle
// Contest: Virtual Judge - Basic Geometry
// URL: https://vjudge.net/contest/405410#problem/A
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
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

bool debug = false;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    double x[3] ,y[3];
    while(cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2]){
    	
    	if(debug) for(int i = 0; i < 3; i++) cout << x[i] << ' ' << y[i] << endl;
    	
    	/*
		x0(-2a+2c) + y0(-2b+2d) = -a2-b2+c2+d2
		x0(-2e+2c) + y0(-2f+2d) = -e2-f2+c2+d2
		
		x0(A0) + y0(B0) = C0
		x0(A1) + y0(B1) = C1
		
		x0 = (C0 - y0(B0))/A0
		A1(C0 - y0(B0))/A0 + y0(B1) = C1
		
		C0A1/A0 + y0(B1-B0A1/A0) = C1
		y0 = (C1 - C0A1/A0)/(B1-B0A1/A0)
		=> x0 = (C0 - y0(B0))/A0
		*/
		
		double a[2], b[2], c[2];
		
		a[0] = -2.0*(x[0]-x[1]);
		a[1] = -2.0*(x[2]-x[1]);
		b[0] = -2.0*(y[0]-y[1]);
		b[1] = -2.0*(y[2]-y[1]);
		c[0] = -x[0]*x[0] -y[0]*y[0] +x[1]*x[1] +y[1]*y[1];
		c[1] = -x[2]*x[2] -y[2]*y[2] +x[1]*x[1] +y[1]*y[1];
		
		if(debug) for(int i = 0; i < 2; i++) cout << a[i] << ' ' << b[i] << ' ' << c[i] << endl;
		
		double x0, y0;
		
		// incase a[0] == 0 (x[0] == x[1])
		
		a[0] += EPS;
		
		y0 = (c[1] - c[0]*a[1]/a[0])/(b[1]-b[0]*a[1]/a[0]);
		x0 = (c[0] - y0*b[0])/a[0];
		
		if(debug) cout << x0 << ' ' << y0 << endl;
		
		double r2 = (x[0] - x0)*(x[0] - x0) + (y[0] - y0)*(y[0] - y0);
		
		cout << fixed << setprecision(2) << 2.0*PI*sqrt(r2) << endl;
		
		if(debug) cout << endl;
    }
}
