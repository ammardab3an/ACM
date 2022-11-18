#include<bits/stdc++.h>

using namespace std;

int ans = 0;
//const double eps = 1e-9;
#define pt complex<long long>
#define cross(a,b) ((conj(a)*(b)).imag())

bool colinear(pt a, pt b, pt c)
{
    return abs(cross(b-a, c-a))==0;
}

bool quad(pt a , pt b, pt c, pt d)
{
    if(colinear(a,b,c)) return 0;
    if(colinear(a,b,d)) return 0;
    if(colinear(a,c,d)) return 0;
    if(colinear(d,b,c)) return 0;
    return 1;
}
int main(){

    int n;
    cin >> n;

    vector<pt> pts;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        pts.push_back({x,y});
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                for(int w=k+1; w<n; w++)
                {
                    if(quad(pts[i],pts[j],pts[k],pts[w]) ) ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
