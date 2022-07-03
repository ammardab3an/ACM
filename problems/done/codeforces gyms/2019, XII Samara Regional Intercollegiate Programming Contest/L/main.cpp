#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
    double res = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    res = pow(res, 0.5);
    return res;
}

double rat(double a1, double a2 , double d1, double d2)
{
    double res;
    if(a1 > a2)
        res = a2 + (a1-a2)*(d2/(d1+d2));
    else
        res = a1 + (a2-a1)*(d1/(d1+d2));

    return res;
}

int main()
{
    double x1, x2, y1, y2, r1, r2 , x, y, r, l;

    cin>>x1>>y1>>r1;
    cin>>x2>>y2>>r2;

    double d = dist(x1, y1, x2, y2);

    l = r1 + r2 - d;

    r = l/2;
    double d1 = r1 - l/2;
    double d2 = r2 - l/2;

    x = rat(x1, x2, d1, d2);
    y = rat(y1, y2, d1, d2);

    printf("%.14f %.14f %.14f", x, y, r );

    return 0;
}
