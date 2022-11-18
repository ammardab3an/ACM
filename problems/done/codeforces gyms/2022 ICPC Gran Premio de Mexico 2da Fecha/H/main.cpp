#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll n, x, ans;
set<int> s;
ll a[22];

void get()
{
    for(int i=1; i<(1<<n); i++)
    {
        ll prod = 1, sz= 0;
        for(int j=0; j<n; j++)
        {
            if(i & (1<<j))
            {
                prod = prod*a[j]/__gcd(a[j], prod);
                sz++;
            }
            if(prod > x) break;
        }
        ll res = x/prod;
        if(sz & 1) ans += res;
        else ans -= res;
    }
}
int main()
{
    cin>>n>>x;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    n = s.size();
    int i = 0;
    for(int x : s){
        a[i++] = x;
    }
    get();
    cout<<ans;
    return 0;
}
