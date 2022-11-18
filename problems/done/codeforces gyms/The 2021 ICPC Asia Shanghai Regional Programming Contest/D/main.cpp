#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 4e7+ 100;
int lp[N];

void sieve()
{
    lp[1] = 1;

    for(int i = 2; i < N; i += 2) lp[i] = 2;

    for(int i=3; i<N/i; i += 2)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            for(int j=i*i; j<N; j+=2*i)
            {
                if(!lp[j]) lp[j] = i;
            }

        }
    }
    for(int i=0; i<N; i++)
        if(!lp[i]) lp[i] = i;
}

ll fac(int x)
{
    vector<int> f;
    for(int i = x; i>1; i /= lp[x])
    {
        f.push_back(lp[i]);
    }

    sort(f.begin(), f.end());

    ll res=1;
    int cnt = 1;
    for(int i=1; i<f.size(); i++)
    {
        if(f[i] == f[i-1]) cnt++;
        else
        {
            if(cnt&1) res *= f[i-1];
            cnt = 1;
        }
    }
    if((cnt&1) && !f.empty()) res *= f.back();
    return res;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sieve();

    int t;
    cin>>t;
    while(t--)
    {
        ll p, q;
        cin>>p>>q;
        int g = __gcd(p,q);
        p/=g; q/=g;


        ll delta = p*p - 4*q*q;

        if(delta<0)
        {
            cout<<"0 0\n";
            continue;
        }


        ll sq = sqrt(delta);
        if(sq*sq != delta)
        {
            cout<<"0 0\n";
            continue;
        }

        ll yd1 = p + sq;
        ll yd2 = p - sq;

        ll y1 = 2*yd1;
        ll y2 = 2*yd2;

        ll z1 = 4*p - 2*yd1;
        ll z2 = 4*p - 2*yd2;

        ll k1 = fac(y1), k2 = fac(z1);
        if(y1>0 && z1>0 && (k1 == k2))
        {
            ll a = sqrt(k1*y1), b = sqrt(k2*z1);
            cout<<a<< " " <<b <<"\n";
            continue;
        }

        k1 = fac(y2), k2 = fac(z2);
        if(y2>0 && z2>0 && (k1 == k2))
        {
            ll a = sqrt(k1*y2), b = sqrt(k2*z2);
            cout<<a<< " " <<b <<"\n";
        }
        else
        {
            cout<<"0 0\n";
        }


    }

    return 0;
}
