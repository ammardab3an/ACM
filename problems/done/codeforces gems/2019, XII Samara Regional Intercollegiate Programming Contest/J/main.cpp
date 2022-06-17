#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll ans[500009];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n , v[3];
    vector < pair<ll, ll> > a;
    vector <ll> b;

    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j = 0; j<3; j++)
            cin>>v[j];

        sort(v, v+3);

        a.push_back({v[0]+v[1] , v[0]+v[1]+v[2]});
        b.push_back(v[0]+v[1]);
    }

    sort(b.begin(), b.end());

    for(int i=0; i<n; i++)
    {
        ans[i] = upper_bound(b.begin(), b.end(), a[i].second-2) - b.begin();
        if(a[i].first <= (a[i].second - 2) )
            ans[i]--;
    }

    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";



    return 0;
}
