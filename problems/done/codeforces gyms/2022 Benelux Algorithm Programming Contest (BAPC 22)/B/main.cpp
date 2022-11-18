#include <bits/stdc++.h>

using namespace std;
#define double long double
#define ll long long
typedef complex<ll> point;
const double PI = acos(-1);

#define eps 1e-9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define ang(v) (atan2((v).Y,(v).X))
#define cross(a,b) ((conj(a)*(b)).imag())
#define dot(a,b) ((conj(a)*(b)).real())
#define lengthsqr(v) (dot(v,v))
#define same(a,b) (lengthsqr(vec(a,b))==0)

double angle(point p, point q)
{
    double res;
    if(p.Y == q.Y){
        return 0;
    }
    if(p.Y < q.Y)
    {
        point a = vec(q,p);
        double ta = fmod(ang(a) + 2*PI, 2*PI);
        res = ta -  PI;
    }
    else
    {
        point a = vec(p,q);
        double ta = fmod(ang(a) + 2*PI, 2*PI);
        res = 2*PI - ta;

    }
    res *= 180/PI;
    return res;
}

void convexHull(vector<point> pnts , vector<point> &convex)
{
    convex.push_back(pnts[0]);
    if(pnts.size() == 1) return;
    convex.push_back(pnts[1]);
    if(pnts.size() == 2) return;

    for(int i=2; i<= pnts.size(); i++)
    {
        point c = pnts[i%pnts.size()];
        while(convex.size() > 1)
        {
            point b = convex.back();
            point a = convex[convex.size() - 2];

            if(cross(vec(b,a), vec(b,c)) < 0) break;

            convex.pop_back();
        }
        if(i< pnts.size()) convex.push_back(pnts[i]);
    }
}

int main()
{
    int n;
    vector<point> pnts, convex;

    cin>>n;
    for(int i=0; i<n; i++)
    {
        ll x,y;
        cin>>x>>y;
        pnts.push_back({x,y});
    }
    reverse(pnts.begin(), pnts.end());

    convexHull(pnts, convex);

    reverse(convex.begin(), convex.end());

//    for(auto i : convex) cout << i << ' '; cout << endl;
    double ans = 0;
    for(int i=0; i<convex.size()-1; i++)
    {
        double t = angle(convex[i], convex[i+1]);
        ans = max( ans, t);

    }
    cout<<fixed << setprecision(12) << ans;

    return 0;
}
