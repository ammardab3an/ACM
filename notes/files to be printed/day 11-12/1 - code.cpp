#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-9;
const double pi = acos(-1);

struct point{
    double x,y;
    point(){}
    point(double a,double b){ x=a;y=b; }
    void in(){ scanf("%lf %lf",&x,&y); }
    void out(){ printf("{%.9f,%.9f}\n",x,y); }
    double len(){ return hypot(x,y); }
    double len2(){ return x*x+y*y; }
    double angle(){ return atan2(y,x); }
    point operator+(point s){ return point(s.x+x,s.y+y); }
    point operator-(point s){ return point(-s.x+x,-s.y+y); }
    point operator*(double k){ return point(x*k,y*k); }
    point operator/(double k){ return point(x/k,y/k); }
    point  norm(){ return point(x/len(),y/len()); }

};

point vec(point a,point b){ return b-a; }
double dot(point a,point b){ return a.x*b.x + a.y*b.y; }
double crs(point a,point b){ return a.x*b.y - a.y*b.x; }

// compare 2 real numbers a , b
// return +1 if a > b
// return  0 if a = b
// return -1 if a < b
int cmp(double a,double b){
if( fabs(a-b) < eps )return 0;
if( a-b > eps )return 1;
return -1;
}


bool same(point a,point b){
    return  cmp( vec(a,b).len2() , 0) == 0;
}


// compute the distance between c & line defined by (a,b)
double linePointDist(point a,point b,point c){
    return fabs( crs( vec(a,b) , vec(a,c) )/ vec(a,b).len() );
}

double segmentPointDist(point a,point b,point c){
    if( dot(vec(a,b),vec(b,c)) >= 0 )
        return vec(b,c).len();

    if( dot(vec(b,a),vec(a,c)) >= 0 )
        return vec(a,c).len();

    return linePointDist(a,b,c);
}

double polygonArea(vector<point>pol){
double area =0.0;
int N = pol.size();
for(int i=0;i<N;i++)
    area += crs( pol[i] , pol[(i+1)%N] );
return fabs( area / 2.0 );
}

struct Line{
    point p,q;
    double A,B,C;
    Line(){}
    Line(point aa,point bb){
        p=aa; q=bb;
        A = q.y - p.y;
        B = p.x - q.x;
        C = A * p.x + B * p.y;
    }

    Line(double a,double b,double c){
        A=a;
        B=b;
        C=c;
        p=point(1.0,(c-a)/b);
        q=point((c-b)/a,1.0);
        if( same(p,q) )q=point((c-10.0*b)/a,1.0);
    }
// latice points on segment [p,q]
    ll get(){ return 1 
				+ __gcd( (ll)abs( p.x-q.x ) , (ll)abs( p.y-q.y) ); 
			}

// is x in range [l , r]
    bool between(double l,double r,double x){
        if( cmp(l,r)==1 )swap(l,r);
        return cmp(l,x)<=0&&cmp(x,r)<=0;
        }
// is point o on line [p,q]
	bool between(point& o){
	return between(p.x,q.x,o.x)&&between(p.y,q.y,o.y);
	}

    bool intersect(Line &o,point &ret){
        double det = A*o.B - o.A*B;
        if( cmp(det,0)==0 )return 0;// parallel or same 2 lines
        double dx = o.B*C - B*o.C;
        double dy = A*o.C - o.A*C;
//        if( dx%det !=0 || dy%det !=0 )return 0;
// not integer coordinates (should be used with int variables det,dx and dy)
        dx /= det;
        dy /= det;
        ret = point(dx,dy);
        return between(ret)&&o.between(ret);
    }
};

void circleFrom3Points(point a,point b,point c,point &cen,double &rad){
    Line AB = Line(a,b);
    double d1 = - AB.B * ((a.x+b.x)/2.0) + AB.A * ((a.y+b.y)/2.0);
    Line t1 = Line(-AB.B,AB.A,d1);

    Line BC = Line(b,c);
    double d2 = - BC.B * ((b.x+c.x)/2.0) + BC.A * ((b.y+c.y)/2.0);
    Line t2 = Line(-BC.B,BC.A,d2);

    t1.intersect(t2,cen);
    rad = vec(cen,a).len();
}

point rot(point p,double t){
    return point( p.x*cos(t) - p.y*sin(t) , p.x*sin(t) + p.y*cos(t) );
}
// rotate p with ang=t about q
point rotAboutPoint(point p,double t,point q){
    return q+rot(p-q,t);
}

bool pointOnSegment(point a,point b,point p){
    return cmp( vec(a,b).len() , vec(p,a).len() + vec(p,b).len() )==0;
}

// angle(abc) : between line(b,a) and line(b,c)
double angle(point a,point b,point c){
point ba = vec(b,a);
point bc = vec(b,c);
return acos( dot(ba,bc) / sqrt( ba.len2() * bc.len2() ) );
}


// inside or on some side
bool pointInPolygon(vector<point>&pol,point &a){
int N = pol.size();

for(int i=0;i<N;i++)
    if( pointOnSegment(pol[i],pol[(i+1)%N],a) )
        return 1;


double tot =0.0;
for(int i=0;i<N;i++)
    if( crs( vec(a,pol[i]),vec(a,pol[(i+1)%N]) )>0 )// CCW
        tot +=angle( pol[i],a,pol[(i+1)%N] );
    else // CW
        tot -=angle( pol[i],a,pol[(i+1)%N] );

tot=fabs(tot);
return cmp(tot,2.0*pi)==0;
}



bool cmp1(point a,point b){
    return cmp(a.x,b.x)==-1 ||( cmp(a.x,b.x)==0 && cmp(a.y,b.y)==-1 );
}

vector<point> convexHull(vector<point>pol){
sort(pol.begin(),pol.end(),cmp1);

// remove duplicate points
vector<point>tmp;
tmp.push_back(pol[0]);
int N = pol.size();
for(int i=1;i<N;i++)
    if( !same(pol[i-1],pol[i]) )
        tmp.push_back(pol[i]);
pol=tmp;

N=pol.size();// new size
vector<point>up,dn;
for(int i=0;i<N;i++){
        while( dn.size() >=2 
		&& crs(
			vec(dn[dn.size()-2],dn[dn.size()-1]),
			vec(dn[dn.size()-1],pol[i])) <0 )
            dn.pop_back();
    dn.push_back(pol[i]);
    }


for(int i=N-1;i>=0;i--){
        while( up.size() >=2 && crs(vec(up[up.size()-2],up[up.size()-1]),vec(up[up.size()-1],pol[i])) <0 )
            up.pop_back();
    up.push_back(pol[i]);
    }

dn.pop_back();
up.pop_back();

vector<point>cvx;
for(auto p:dn)cvx.push_back(p);
for(auto p:up)cvx.push_back(p);
return cvx;
}

// inside triangle or on one of it's sides
bool pointInTriangle(point a,point b,point c,point p){
    return crs( vec(a,b) , vec(a,p) ) >=0
        && crs( vec(b,c) , vec(b,p) ) >=0
        && crs( vec(c,a) , vec(c,p) ) >=0 ;
}

bool pointInConvex(vector<point>&pol,point &a){
int N = pol.size();
if( cmp( crs( vec(pol[0],pol[ 1 ]) , vec(pol[0],a) ) ) < 0 )return 0;
if( cmp( crs( vec(pol[0],pol[N-1]) , vec(pol[0],a) ) ) > 0 )return 0;

int low =1,high = N-2;
while(low < high){
    int mid = low+high+1>>1;
    if( cmp( crs(vec(pol[0],pol[mid]),vec(pol[0],a)) ) >0 )low=mid;
    else high=mid-1;
}
return pointInTriangle(pol[0],pol[low],pol[low+1],a);
}


bool pointInCircle(point p,point c,double r){
	return cmp(r*r,vec(p,c).len2()) >=0;
}



// need to check ??
vector<point> circleLineIntersection(point c,double r,point p,point q){

vector<point> ret;
if( cmp( linePointDistance(p,q,c) , r ) == 1 )return ret;//  no intersection

Line L = Line(p-c,q-c);
double a = L.A , b = L.B , c = L.C;

double x0 = - a*c / ( a*a + b*b );
double y0 = - b*c / ( a*a + b*b ); 

double d  = sqrt( r*r - (  (c*c) / ( a*a + b*b ) ) )
double m  = sqrt( d*d / (  a*a + b*b ) );

if( cmp( linePointDistance(p,q,c) , r ) == 0 ){
	ret.push_back( point(x0,y0) );
	return ret;
}

ret.push_back( point( x0 + b*m , y0 - a*m ) );
ret.push_back( point( x0 - b*m , y0 + a*m ) );
return ret;
}


// need to check ???
vector<point> circleCircleIntersection(point c1,double r1,point c2,double r2){

vector<point> ret;
double d = vec(c1,c2).len();
if( cmp( d , r1+r2 ) == 1 )return ret;// no intersection
if( cmp( d , r1+r2 ) == 0 ){ // 1 point
		ret.push_back( c1 + vec(c1,c2).norm()*r1 );
		return ret;	
}
if( cmp(d,eps) == 0 )return ret;// same circle or same center (can be handled differently)

double a = ( r1*r1 - r2*r2  + d*d ) / ( d + d );
double h = sqrt( r1*r1 - a*a );

point t  = c1 + vec(c1,c2)*a/d;
ret.push_back( point( p2.x + h*(c2.y-c1.y)/d, p2.y - h*( c2.x - c1.x )/d ) );
ret.push_back( point( p2.x - h*(c2.y-c1.y)/d, p2.y + h*( c2.x - c1.x )/d ) );

return ret;
}



int main(){
		

    vector<point>pol;
    pol.push_back( point(0,0) );
    pol.push_back( point(10,0) );
    pol.push_back( point(10,10) );
    pol.push_back( point(0,10) );
    point p[5] = {
                    point(10,10),
                    point(0,10),
                    point(1,10),
                    point(2,15),
                    point(5,5)
                    };

    for(int i=0;i<5;i++)
    cout<< pointInPolygon(pol,p[i]) <<endl;

}
