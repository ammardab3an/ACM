#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int ask(int i, int b){

    cout << "? " << i+1 << ' ' << b << endl << flush;
    int ret;
    cin >> ret;
    return ret;
}

int32_t main()
{

    int n;
    cin >> n;

    vector<int> v(n);
    iota(v.begin(), v.end(), 0);

    int ans = 0;

    int b = 0;
    while(!v.empty()){

        int cnt[2] = {0};
        for(int i = 0; i <= n; i++){
            int j = (i << b) | ans;
            if(j <= n){
                cnt[(j>>b)&1]++;
            }
            else{
                break;
            }
        }

        vector<int> newIdc[2];

        for(auto idx : v){
            int cur = ask(idx, b);
            newIdc[cur].push_back(idx);
        }

        if(newIdc[0].size() == cnt[0]){
            v = newIdc[1];
            ans |= 1 << b;
        } else {
            v = newIdc[0];
        }

        b++;
    }

    cout << "! " << ans << endl;
    return 0;
}
