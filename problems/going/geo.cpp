
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

typedef double T;
typedef complex<T> cpt;

struct pt{
	T x, y;
	pt operator+(pt p) {return {x+p.x, y+p.y};}
	pt operator-(pt p) {return {x-p.x, y-p.y};}
	pt operator*(T d) {return {x*d, y*d};}
	pt operator/(T d) {return {x/d, y/d};}
};

bool operator==(pt a, pt b)	{return abs(a.x-b.x) < EPS && abs(a.y-b.y) < EPS;}
bool operator!=(pt a, pt b) {return abs(a.x-b.x) > EPS || abs(a.y-b.y) > EPS;}

T sq(pt p) {return p.x*p.x + p.y*p.y;}
T sq(cpt p) {return p.real()*p.real() + p.imag()*p.imag();};
double ptabs(pt p) {return sqrt(sq(p));}
double ptabs(cpt p) {return sqrt(sq(p));}

pt translate(pt v, pt p) {return p+v;}
cpt translate(cpt v, cpt p){return p+v;};
pt scale(pt c, double factor, pt p){ return c + (p-c)*factor;}
cpt scale(cpt c, double factor, cpt p) {return c + (p-c)*factor;}
pt rot(pt p, double th) {return {p.x*cos(th)-p.y*sin(th), p.x*sin(th)+p.y*cos(th)};}
cpt rot(cpt p, double th) {return p*polar(1.0, th);}
pt rot90(pt p) {return {-p.y, p.x};}
cpt rot90(cpt p){return {-p.imag(), p.real()};}

T dot(pt v, pt w) {return v.x*w.x + v.y*w.y;};
T dot(cpt v, cpt w) {return (conj(v)*w).real();}
T cross(pt v, pt w) {return v.real()*w.imag() - v.imag()*w.real();}
T cross(cpt v, cpt w) {return (conj(v)*w).imag();}

bool isPerp(pt v, pt w) {return abs(dot(v, w)) < EPS; }
bool isPerp(cpt v, cpt w) {return abs(dot(v, w)) < EPS; }

double clamp(double th) {return max(-1.0, min(1.0, th));}

double angle(pt v, pt w){
	double cosTheta = dot(v, w)/ptabs(v)/ptabs(w);
		return acos(clamp(cosTheta));
}

T orient(pt a, pt b, pt c) {return cross(b-a, c-a);}

bool inAngle(pt a, pt b, pt c, pt p){
	assert( abs(orient(a, b, c)) > EPS );
	if( (orient(a, b, c)) < -EPS ) swap(b, c);
	return orient(a, b, p) >= EPS && orient(a, c, p) <= -EPS;
}

double orientedAngle(pt a, pt b, pt c){
	if(abs(orient(a, b, c)) >= EPS)
		return angle(b-a, c-a);
	return 2*PI - angle(b-a, c-a);
}

bool isConvex(vector<pt> vp){
	bool hasPos = false, hasNeg = false;
	for(int i = 0, n = vp.size(); i < n; i++){
		int o = orient(vp[i], p[(i+1)%n], p[(i+2)%n]);
		if(o > EPS) hasPos = true;
		if(o < -EPS) hasPos = true;
	}
	return !(hasPos && hasNeg);
}

ostream& operator<<(ostream& os, pt p){
	return os << "(" << p.x << ", " << p.y << ")";
}

istream& operator>>(istream& is, pt p){
	return is >> p.x >> p.y;
}

int sgn(T x){
	return (T(0) < x) - (T(0) > x);
}



int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){


    }	
}
