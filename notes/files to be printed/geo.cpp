
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

typedef double T;
struct point{

	T x, y;
	
	point(){}
	point(const point& pnt): x(pnt.x), y(pnt.y) {}
	point(T i, T j): x(i), y(j) {}
	
	point operator*(T d) { return point(x*d, y*d); }
	point operator/(T d) { return point(x/d, y/d); }
	
	point operator+(point p) { return point(x+p.x, y+p.y); }
	point operator-(point p) { return point(x-p.x, y-p.y); }
	
	T operator*(point p) { return x*p.x + y*p.y; }
	T operator^(point p) { return x*p.y - y*p.x; }
	
	bool operator==(point p) { return x==p.x && y==p.y; }
	bool operator!=(point p) { return x!=p.x || y!=p.y; }
	bool operator <(point p) { return pii(x, y) < pii(p.x, p.y); }

//	bool operator==(pt a, pt b)	{ return abs(a.x-b.x) < EPS && abs(a.y-b.y) < EPS; }
//	bool operator!=(pt a, pt b) { return abs(a.x-b.x) > EPS || abs(a.y-b.y) > EPS; }
		
	T len2() { return x*x + y*y; }
	double len()  { return sqrt(x*x + y*y); }
	
	void scan()  { cin >> x >> y; }
	void print() { cout << x << ' ' << y << endl; }
};

double clamp(double th) {return max(-1.0, min(1.0, th));}

point tran(point p, point v) { return p + v; }
point rot(point p, double th) { return {p.x*cos(th)-p.y*sin(th), p.x*sin(th)+p.y*cos(th)}; }
point rot90(point p) { return point(-p.y, p.x); }
point scale(point p, point c, double f) { return c + (c-p)*f; }

bool isPerp(point v, point w) { return abs(v*w) < EPS; }

double angle(point v, point w){
	double cosTheta = (v*w)/v.len()/w.len();
		return acos(clamp(cosTheta));
}

T orient(point a, point b, point c) { return (b-a)^(c-a); }

bool inAngle(point a, point b, point c, point p){
	assert( abs(orient(a, b, c)) > EPS );
	if( (orient(a, b, c)) < -EPS ) swap(b, c);
	return orient(a, b, p) >= EPS && orient(a, c, p) <= -EPS;
}

double orientedAngle(point a, point b, point c){
	if(abs(orient(a, b, c)) >= EPS)
		return angle(b-a, c-a);
	return 2*PI - angle(b-a, c-a);
}

bool isConvex(vector<point> vp){
	bool hasPos = false, hasNeg = false;
	for(int i = 0, n = vp.size(); i < n; i++){
		int o = orient(vp[i], vp[(i+1)%n], vp[(i+2)%n]);
		if(o > EPS) hasPos = true;
		if(o < -EPS) hasPos = true;
	}
	return !(hasPos && hasNeg);
}

int sgn(T x){
	return (T(0) < x) - (T(0) > x);
}

vector<point> calc_chull(vector<point> points){
	
	int n = points.size();
	
	int idx = 0;
	for(int i = 1; i < n; i++){
		if(points[i] < points[idx])
			idx = i;	
	}
	
	swap(points[0], points[idx]);
	
	auto cmp = [&](point &p0, point &p1){
		point v1 = p0-points[0];
		point v2 = p1-points[0];
		int crs = v1^v2;
		if(!crs) return p0.len2() < p1.len2();
		return crs < 0;
	}; 
	
	sort(points.begin()+1, points.end(), cmp);
	
	vector<point> chull;
	chull.push_back(points[0]);
	chull.push_back(points[1]);
		
	for(int i = 2; i < n; i++) {
		while(chull.size() > 1){	
			int m = chull.size();
			point v1 = chull[m-1] - chull[m-2];
			point v2 = points[ i] - chull[m-2];
			if((v1^v2) < 0) break;
			chull.pop_back();
		}
		chull.push_back(points[i]);
	}
	
	return chull;	
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	point u(0, 0), v(0, 1);
	
	int n;
	cin >> n;
	
	vector<point> points(n);
	
	for(int i = 0; i < n; i++) points[i].scan();

	vector<point> chull = calc_chull(points);
	
	cout << chull.size() << endl;
	for(auto p : chull) p.print();
	
	cin >> n;
	points.resize(n);
	for(int i = 0; i < n; i++) points[i].scan();
	cout << (isConvex(points) ? "YES" : "NO") << endl;
}
