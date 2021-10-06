#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
const ll inf = 1LL<<30;

ii slope(point a,point b){

    int dx = a.x - b.x;
    int dy = a.y - b.y;
	
    bool f=0;
    if(dx < 0) f=!f;
    if(dy < 0) f=!f;

    dx=fabs(dx);
    dy=fabs(dy);

	if( !dx && !dy )return {0,0};
	if( !dx )return {1,0};
	if( !dy )return {0,1};

    int gcd = __gcd(dx,dy);
	dx /= gcd;
	dy /= gcd;
	if(f)dy=-dy;
    return {dy,dx};
}
