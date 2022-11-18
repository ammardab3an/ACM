#include <bits/stdc++.h>
using namespace std;

#define double long double
const double PI = acos(-1);
const double eps = 1e-7;
const double inf = 1e9;

typedef complex<double> point;
#define vec(a,b) ((b) - (a))
#define X real()
#define Y imag()
#define length(v) ((double)hypot((v).Y, (v).X))
#define lengthSqr(v) (dot(v,v))
#define ang(v) (atan2((v).Y, (v).X))
#define dot(a, b) ((conj(a)*(b)).real())
#define cross(a, b) ((conj(a)*(b)).imag())
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b)) < eps)
#define perp(a) (point(-(a).Y, (a).X))


double angle(point v, point w){
    double a = fmod(ang(v) + 4*PI, 2*PI);
    double b = fmod(ang(w) + 4*PI, 2*PI);
    double res = fabs(a-b);
    if(res >= PI) res = 2*PI - res;
    return res;
}

bool pointOnLine(point a, point b, point p)
{
    return fabs(cross(b-a, p-a))<eps;
}

bool pointOnRay(point a, point b, point p)
{
    return dot( vec(a,p), vec(a,b) ) > -eps;
}

bool pointOnSeg(point a, point b, point p)
{
    if(!pointOnLine(a,b,p)) return 0;
    return pointOnRay(a,b,p) && pointOnRay(b,a,p);
}

double area(point a, point b, point c)
{
    return fabs(cross(a,b) + cross(b,c) + cross(c,a))/2;
}

double get(double a, double t, double s)
{
    return fabs(s/(a*sin(t)));
}

point solve(point a, point b, point p, point c, double s)
{
    if(!same(a,p))
    {
        double d = get(length(p-a), angle(b-a,c-a), s);
        point ad = normalize(vec(a,c))*d + a;
        if(pointOnSeg(a,c,ad)) return ad;

    }
    if(!same(b,p))
    {
        double d = get(length(p-b), angle(a-b,c-b), s);
        point bd = normalize(vec(b,c))*d + b;
        if(pointOnSeg(b,c,bd)) return bd;
    }
    return {inf , inf};
}

void out(point a)
{
    cout<<fixed<<setprecision(10)<<a.X<<" "<<a.Y<<endl;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        vector<point> p;
        for(int i=0; i<4; i++)
        {
            int x,y;
            cin>>x>>y;
            p.push_back({x,y});
        }

        double s = area(p[0], p[1], p[2]);

        if(pointOnSeg(p[0],p[1],p[3]))
        {
            point ans = solve(p[0],p[1],p[3],p[2],s);
            if(ans.X <inf)
            {
                out(ans);
                continue;
            }
        }
        if(pointOnSeg(p[0],p[2],p[3]))
        {
            point ans = solve(p[0],p[2],p[3],p[1],s);
            if(ans.X <inf)
            {
                out(ans);
                continue;
            }

        }
        if(pointOnSeg(p[2],p[1],p[3]))
        {
            point ans = solve(p[2],p[1],p[3],p[0],s);
            if(ans.X <inf)
            {
                out(ans);
                continue;
            }
        }
        cout<<-1<<endl;
    }
    return 0;
}
