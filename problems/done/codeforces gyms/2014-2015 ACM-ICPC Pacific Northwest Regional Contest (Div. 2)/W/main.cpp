#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct point{
    ll x,y,z;
};

long double dis[150][150];

long double cal_dis(point a,point b){
    long double res=(a.x-b.x)*(a.x-b.x);
    res+=(a.y-b.y)*(a.y-b.y);
    res+=(a.z-b.z)*(a.z-b.z);
    return sqrtl(res);
}

int solve(){

    int n;cin>>n;
    map<string,int>mp;
    vector<point>v;

    for(int i=0;i<n;i++){
        string name;ll x,y,z;cin>>name>>x>>y>>z;
        point p;
        p.x=x;
        p.y=y;
        p.z=z;
        mp[name]=i;
        v.emplace_back(p);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dis[i][j]=cal_dis(v[i],v[j]);
        }
    }

    int w;cin>>w;
    for(int i=0;i<w;i++){
        string a,b;cin>>a>>b;
        dis[mp[a]][mp[b]]=0;
    }

    for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }

    int q;cin>>q;
    while(q--){
        string a,b;cin>>a>>b;
        long double res=dis[mp[a]][mp[b]];
        cout<<"The distance from "<<a<<" to "<<b<<" is "<<llround(res)<<" parsecs.\n";
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;cin>>t;
    int i=1;
    while(t--){
        cout<<"Case "<<i++<<":\n";
        solve();
    }
    return 0;
}
