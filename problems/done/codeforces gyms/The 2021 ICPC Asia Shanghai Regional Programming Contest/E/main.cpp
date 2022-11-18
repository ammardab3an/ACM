#include<bits/stdc++.h>

using namespace std;

const int NMAX = 1e5 + 10;

signed main(){

    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for(auto &i : vec) cin >> i;


    sort(vec.begin(), vec.end());

    int ans = 1;
    int lst = vec[0];
    for(int i = 1; i < n; i++){
        if(vec[i]-lst >= k){
            ans++;
            lst = vec[i];
        }
    }

    cout << ans << endl;
}
