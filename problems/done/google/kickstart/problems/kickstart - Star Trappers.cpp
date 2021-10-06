// Problem: Star Trappers
// Contest: Google Coding Competitions - Round F 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000888d45
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ld long double

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef complex<ld> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-6
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((ld)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine

enum STATE {
	IN, OUT, BOUNDRY
};

bool pointOnLine(const point& a, const point& b, const point& p) {
    // degenerate case: line is a point
    return fabs(cross(vec(a,b),vec(a,p))) < EPS;
}

bool pointOnRay(const point& a, const point& b, const point& p) {
    //IMP NOTE: a,b,p must be collinear
    return dot(vec(a,p), vec(a,b)) > -EPS;
}

bool pointOnSegment(const point& a, const point& b, const point& p) {
    if(!colliner(a,b,p)) return 0;
    return pointOnRay(a, b, p) && pointOnRay(b, a, p);
}

bool intersect(const point &a, const point &b, const point &p, const point &q,
                 point &ret) {
    //handle degenerate cases (2 parallel lines, 2 identical lines,   line is 1 point)
    ld d1 = cross(p - a, b - a);
    ld d2 = cross(q - a, b - a);
    ret = (d1 * q - d2 * p) / (d1 - d2);
    if(fabs(d1 - d2) > EPS) return 1;
    return 0;
}

STATE pointInPolygon(const vector<point>& p, const point &pnt) { 
 point p2 = pnt + point(1, 0); 
 int cnt = 0; 
 for (int i = 0; i < sz(p); i++) { 
  int j = (i + 1) % sz(p); 
  if (pointOnSegment(p[i], p[j], pnt)) 
   return BOUNDRY; 
  point r; 
  if(!intersect(pnt, p2, p[i], p[j], r)) 
          continue; 
  if (!pointOnRay(pnt, p2, r)) 
   continue; 
  if (same(r,p[i]) || same(r,p[j])) 
   if (fabs(r.Y - min(p[i].Y, p[j].Y)) < EPS) 
    continue; 
  if (!pointOnSegment(p[i], p[j], r)) 
   continue; 
  cnt++; 
 } 
 return cnt & 1 ? IN : OUT; 
}

bool half(point p) { // true if in blue half
    return p.Y > 0 || (p.Y == 0 && p.X < 0);
}

int32_t main(){
    
    fastIO;
    
    int tt = 0;
    int t; cin >> t; while(t--){
        
        int n;
        cin >> n;
        
        vector<point> pnts(n);
        for(auto &p : pnts){
            int x, y;
            cin >> x >> y;
            p = point(x, y);
        }
        
        point npnt;
        {
            int x, y;
            cin >> x >> y;
            npnt = point(x, y);
        }
        
        for(auto &p : pnts){
            p = point(p.X-npnt.X, p.Y-npnt.Y);
        }
        
        npnt = point(0, 0);
        
        sort(pnts.begin(), pnts.end(), [&](point v, point w) {
            return make_tuple(half(v), 0) < make_tuple(half(w), cross(v,w));
        });
        
        ld ans = 1.0 / 0.0;
        bool found = false;
        
        auto test = [&](vector<point> &cpnts){
            
            STATE st = pointInPolygon(cpnts, npnt);
            
            if(st == (STATE)(IN)){
                
                ld cans = 0;
                for(int i = 0; i < cpnts.size(); i++){
                    cans += length(vec(cpnts[i], cpnts[(i+1)%(cpnts.size())]));
                } 
                
                found = true;
                ans = min(ans, cans);
            }
            
            return st;
        };
       
        vector<point> cpnts;
        
        for(int i = 0; i < n-2; i++){
            cpnts.push_back(pnts[i]);   
            
        for(int j = i+1; j < n-1; j++){
            cpnts.push_back(pnts[j]);   
            
        for(int k = j+1; k < n; k++){
            cpnts.push_back(pnts[k]);   
            STATE st = test(cpnts);
        
        if(st == BOUNDRY)
        for(int l = k+1; l < n; l++){
            cpnts.push_back(pnts[l]);   
            test(cpnts);
            
            cpnts.pop_back();
        }
            cpnts.pop_back();
        }
            cpnts.pop_back();
        }
            cpnts.pop_back();
        }
        
        cout << "Case #" << ++tt << ": ";
        if(found){
            cout << fixed << setprecision(9) << ans << endl;
        }
        else{
            cout << "IMPOSSIBLE" << endl;
        }
    }	
}
