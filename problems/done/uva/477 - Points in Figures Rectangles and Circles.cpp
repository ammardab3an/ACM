// Problem: C - Points in Figures: Rectangles and Circles
// Contest: Virtual Judge - Basic Geometry
// URL: https://vjudge.net/contest/405410#problem/C
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

	int n(0), m(0), k(0);
    vector<array<double, 5>> rec;
    vector<array<double, 4>> cir;
    vector<pair<double, double>> points;
    
    char c; int idx = 1;
    while(cin >> c, c != '*'){
    	if(c == 'r'){
	    	rec.resize(++n);
	    	auto &a = rec.back();
	    	cin >> a[0] >> a[1] >> a[2] >> a[3]; a[4] = idx++;
    	} 
    	else{
    		cir.resize(++m);
    		auto &a = cir.back();
    		cin >> a[0] >> a[1] >> a[2]; a[3] = idx++;
    	}
    }	
    
    
    double x, y;
    while(cin >> x >> y){
    	points.push_back({x, y}); k++;
    }
	
	k--;
	
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
	    
    	if(!found){
			cout << "Point " << i+1 << " is not contained in any figure" << endl;
	    }
    }
    
}
