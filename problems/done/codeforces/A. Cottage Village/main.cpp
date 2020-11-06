#include<bits/stdc++.h>

using namespace std;

//declarations
#define pii pair<int,int>
#define x first
#define a second
int main()
{
    int n, t;
    cin >> n >> t; t *= 2;

    vector<pii> vec; pii ip;
    vec.push_back({5000, 0});
    vec.push_back({-5000,0});

    while(n--)
    {
        cin >> ip.x >> ip.a;
        ip.x *= 2; ip.a *= 2;
        vec.push_back(ip);
    }
    sort(vec.begin(), vec.end());

    set<int> st;
    pii _p, p, p_; int n_x;
    for(int i = 1; i < vec.size()-1; i++)
    {
        _p  = vec[i-1];
         p  = vec[i];
         p_ = vec[i+1];

        n_x = p.x + p.a/2 + t/2;
        if (p_.x - n_x >= p_.a/2 + t/2)
            st.insert(n_x);

        n_x = p.x - p.a/2 - t/2;
        if (n_x - _p.x >= _p.a/2 + t/2)
            st.insert(n_x);
    }
    cout << st.size();
    return 0;
}
