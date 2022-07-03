#include<bits/stdc++.h>

#define int int64_t

using namespace std;

const int NMAX = 1e7 + 1;

bitset<NMAX> vis;

int32_t main(){


    int p, n;
    cin >> p >> n;

    int cur = 0;
    int ans = 1;
    vis.set(0, true);

    n = min(n, 2*p+10);

    int inc = 1;
    while(ans < p && n > 0){

        cur = (cur+inc)%p;
        if(vis.test(cur)==false){
            ans++;
            vis.set(cur, true);
        }

        n--;
        inc++;
    }

    cout << ans << endl;
}
