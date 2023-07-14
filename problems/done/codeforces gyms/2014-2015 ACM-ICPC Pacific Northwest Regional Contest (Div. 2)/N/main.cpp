#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t; while(t--){

        int n;
        cin >> n;

        vector<int> vec(n);
        for(auto &i : vec) cin >> i;

        map<int, int> mp;
        for(auto i : vec) mp[i]++;

        int mx_val = -1;
        int mx_frq = -1;

        for(auto [v, f] : mp){
            if(f > mx_frq){
                mx_val = v;
                mx_frq = f;
            }
        }

        cout << mx_val << endl;
    }
}
