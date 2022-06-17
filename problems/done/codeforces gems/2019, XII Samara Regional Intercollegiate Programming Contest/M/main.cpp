#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

pair<ll,ll> a[1009];
bool ans[1009];

bool larger(ll a, ll b, ll c, ll d )
{
    return a*d<c*b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        ll n, x, y , sum = 0, q =0;

        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>x>>y;
            a[i] = {x,i};
            q += (x*y);
            sum += y;
        }

        sort(a, a+n);
        reverse(a, a+n);

        ll sz= 0 ;
        for(int i=0; i<n; i++)
        {
            ll x = q+a[i].first, y = sum+1;

            if(larger(q, sum , x, y))
            {
                q = x;
                sum = y;
                ans[ a[i].second ] = 1;
                sz++;
            }
        }

            ll g = __gcd(q,sum);
            q /= g;
            sum /= g;

            cout<<q<<"/"<<sum<<"\n";
            cout<<sz<<"\n";

            for(int i=0; i<n; i++)
                if(ans[i])
                    cout<<i+1<<" ";
            cout<<"\n";

            for(int i=0; i<n; i++)
                ans[i] = 0;

    }

    return 0;
}
