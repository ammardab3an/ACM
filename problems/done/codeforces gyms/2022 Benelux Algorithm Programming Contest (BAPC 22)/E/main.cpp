#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

typedef long double dt;

signed main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> vec(n);
    for(auto &i : vec) cin >> i;

    int sm = 0, sm2 = 0;
    for(auto i : vec){
        sm += i;
        sm2 += i*i;
    }

    dt k = sm2==0 ? 0 : dt(x*n)/dt(sm2);
    k = sqrtl(k);

    cout << fixed << setprecision(10);

    for(int i = 0; i < n; i++){
        if(i) cout << ' ';
        cout << k*dt(vec[i]);
    }
}
