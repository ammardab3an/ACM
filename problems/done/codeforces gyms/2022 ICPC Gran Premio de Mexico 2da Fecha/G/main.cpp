#include <bits/stdc++.h>

#define int int64_t
#define endl '\n'

using namespace std;

using ll = long long;

signed main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n-1), x(n);
    for(auto &i : a) cin >> i;
    for(auto &i : x) cin >> i;

    vector<pair<ll, ll>> f(n+1, {-1, -1}), s(n+1, {-1, -1});

    for(ll i = 0, l = 0, r = 0; i < n; i++){
        r = l + x[i];
        f[i] = {l, r};
        if(i != n-1) l = r + a[i];
    }

    for(ll i = n-1, l = 0, r = 0; i >= 0; i--){
        r = l + x[i];
        s[i] = {l, r};
        if(i != 0) l = r + a[i-1];
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll r = min(f[i].second, s[i].second);
        ll l = max(f[i].first, s[i].first);
        ans += max(0LL, r - l);
    }

    cout << ans << endl;
    return 0;
}
