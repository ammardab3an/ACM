// Problem: D - Points in Figures: Rectangles, Circles, Triangles
// Contest: Virtual Judge - Basic Geometry
// URL: https://vjudge.net/contest/405410#problem/D
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	int n(0), m(0), ts(0), k(0);
    vector<array<double, 5>> rec;
    vector<array<double, 4>> cir;
    vector<array<double, 7>> tri;    
    vector<pair<double, double>> points;
    
    char c; int idx = 1;
    while(cin >> c, c != '*'){
    	if(c == 'r'){
	    	rec.resize(++n);
	    	auto &a = rec.back();
	    	cin >> a[0] >> a[1] >> a[2] >> a[3]; a[4] = idx++;
    	} 
    	else if(c == 'c'){
    		cir.resize(++m);
    		auto &a = cir.back();
    		cin >> a[0] >> a[1] >> a[2]; a[3] = idx++;
    	}
    	else{
    		tri.resize(++ts);
    		auto &a = tri.back();
    		cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5]; a[6] = idx++;
    	}
    }	
    
    
    double x, y;
    while(cin >> x >> y){
    	points.push_back({x, y}); k++;
    }
	
	k--;
	
	auto calc_area = [](array<double, 3> x, array<double, 3> y){
		return abs(x[0]*(y[1]-y[2]) + x[1]*(y[2]-y[0]) + x[2]*(y[0]-y[1]))/2.0;
	};
	
    for(int i = 0; i < k; i++){
    	
    	bool found = false;
	    for(int j = 0; j < n; j++){
	    	
	    	double x = points[i].first;
	    	double y = points[i].second;
	    	
	    	bool b0 = rec[j][0] < x && x < rec[j][2];
	    	bool b1 = rec[j][3] < y && y < rec[j][1];
	    	
	    	if(b0 && b1){
	    		cout << "Point " << i+1 << " is contained in figure " << rec[j][4] << endl;
	    		found = true;
	    	} 
	    }
	    for(int j = 0; j < m; j++){

	    	double x = points[i].first;
	    	double y = points[i].second;

	    	bool b0 = (pow(cir[j][0] - x, 2) + pow(cir[j][1] - y, 2)) < pow(cir[j][2], 2);

	    	if(b0){
	    		cout << "Point " << i+1 << " is contained in figure " << cir[j][3] << endl;
	    		found = true;
			}	    	
	    }
		for(int j = 0; j < ts; j++){
			
			array<double, 4> x, y;
			x = {tri[j][0], tri[j][2], tri[j][4], points[i].first};
			y = {tri[j][1], tri[j][3], tri[j][5], points[i].second};
		

			double area[4];
			area[0] = calc_area({x[0], x[1], x[2]}, {y[0], y[1], y[2]});
			area[1] = calc_area({x[0], x[1], x[3]}, {y[0], y[1], y[3]});
			area[2] = calc_area({x[0], x[3], x[2]}, {y[0], y[3], y[2]});
			area[3] = calc_area({x[3], x[1], x[2]}, {y[3], y[1], y[2]});
			
	    	bool b0 = abs(area[1] + area[2] + area[3] - area[0]) < EPS;

	    	if(b0){
	    		cout << "Point " << i+1 << " is contained in figure " << tri[j][6] << endl;
	    		found = true;
			}
			
		}    
    	if(!found){
			cout << "Point " << i+1 << " is not contained in any figure" << endl;
	    }
    }
    
}
