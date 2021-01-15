
#include <bits/stdc++.h>

#define int int64_t
#define ll int64_t

using namespace std;

const int OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int pi = acos(-1);
const double EPS = 1e-9;

const int MAX = 2e5 + 10;

int32_t main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("gift.in", "r", stdin);
  //  freopen("input.txt", "r", stdin);


    int t; cin >> t; while(t--){

        int n;
        cin >> n;

        vector<string> vec(n);
        for(auto &s:vec) cin >> s;

        map<string, int> mp;

        for(int i= 0; i < n; i++){

            string frm;
            cin >> frm;
            int p, k;
            cin >> p >> k;

            vector<string> to(k);

            for(auto &s : to) {
                    cin >> s;
                    mp[s] += p/k;
            }

            mp[frm] -= p;

            if(k) mp[frm] += (p%k);
        }

        for(auto s : vec) cout << s << ' ' << mp[s] << endl;
    }

}
