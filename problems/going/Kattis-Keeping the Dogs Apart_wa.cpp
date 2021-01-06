// Problem: Kattis-Keeping the Dogs Apart
// Contest: Kattis
// URL: https://open.kattis.com/problems/dogs
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
pii a[NMAX], b[NMAX];

double dist(pii p0, pii p1){
	return sqrt( (double)pow(p0.first - p1.first, 2) + (double)pow(p0.second - p1.second, 2) );
}

struct pt{
	double x, y;
	pt(double _x, double _y) : x(_x), y(_y){};
};

pair<double, double> ptp(pt p){
	return (pair<double, double>){p.x, p.y};
}

double minDist(pt pa, pt pb, pt pe) 
{ 
  
  	pair<double, double> A = ptp(pa), B = ptp(pb), E = ptp(pe);
  	
    // vector AB 
    pair<double, double> AB; 
    AB.F = B.F - A.F; 
    AB.S = B.S - A.S; 
  
    // vector BP 
    pair<double, double> BE; 
    BE.F = E.F - B.F; 
    BE.S = E.S - B.S; 
  
    // vector AP 
    pair<double, double> AE; 
    AE.F = E.F - A.F, 
    AE.S = E.S - A.S; 
  
    // Variables to store dot product 
    double AB_BE, AB_AE; 
  
    // Calculating the dot product 
    AB_BE = (AB.F * BE.F + AB.S * BE.S); 
    AB_AE = (AB.F * AE.F + AB.S * AE.S); 
  
    // Minimum distance from 
    // pt E to the line segment 
    double reqAns = 0; 
  
    // Case 1 
    if (AB_BE > EPS) { 
  
        // Finding the magnitude 
        double y = E.S - B.S; 
        double x = E.F - B.F; 
        reqAns = sqrt(x * x + y * y); 
    } 
  
    // Case 2 
    else if (AB_AE < EPS) { 
        double y = E.S - A.S; 
        double x = E.F - A.F; 
        reqAns = sqrt(x * x + y * y); 
    } 
  
    // Case 3 
    else { 
  
        // Finding the perpendicular distance 
        double x1 = AB.F; 
        double y1 = AB.S; 
        double x2 = AE.F; 
        double y2 = AE.S; 
        double mod = sqrt(x1 * x1 + y1 * y1); 
        reqAns = abs(x1 * y2 - y1 * x2) / mod; 
    } 
    return reqAns; 
} 

pt moveBy(pii p0, pii p1, double d){
	
	double dst = dist(p0, p1);
	
	double dx = p1.first - p0.first;
	double dy = p1.second - p0.second;
	
	double nx = p0.first + dx*(d/dst);
	double ny = p0.second + dy*(d/dst);	
	
	return pt(nx, ny);
}

double minDist(pt p, pt q, pt r, pt s){	

	double ans0 = min(minDist(p, q, r), minDist(p, q, s));
	double ans1 = min(minDist(r, s, p), minDist(r, s, q));
	return min(ans0, ans1);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	pt c = moveBy({0, 0}, {0, 1}, 1);
	cout << c.x << ' ' << c.y << endl;
	
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
    
    
    int i = 0, j = 0;
    
    double ans = dist(a[0], b[0]);
    double sumA = 0;
    double sumB = 0;
    
    while(i+1 < n && j+1 < m){
    	
    	double start = max(sumA, sumB);
    	double dA = dist(a[i], a[i+1]);
    	double dB = dist(b[j], b[j+1]);
    	double endA = sumA + dA;
    	double endB = sumB + dB;
    	double end = min(endA, endB);
    	
    	pt p = moveBy(a[i], a[i+1], start-sumA);
    	pt q = moveBy(a[i], a[i+1], end-sumA);
    	pt r = moveBy(b[j], b[j+1], start-sumB);
    	pt s = moveBy(b[j], b[j+1], end-sumB);
    	
    	ans = min(ans, minDist(p, q, r, s));
    	
    	if(endA < endB){
    		i++;
    		sumA += dA;	
    	}
    	else{
    		j++;
    		sumB += dB;
    	}
    	
    	double minSum = min(sumA, sumB);
    	sumA -= minSum;
    	sumB -= minSum;	
    }
    
    cout << fixed << setprecision(12) << ans << endl;
}
