#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main(){


    int a, b;
    cin >> a >> b;

    int st_path = 0;
    st_path += ((a+b-1)/b) * (a-b);
    st_path += a-b;

    int nd_path = 0;
    int l = a, r = a;

    while(l>0 && r>0){

        nd_path += l;
        r -= b;

        swap(l, r);
    }

    nd_path -= b;

    int ans = min(st_path, nd_path);


    cout << ans << endl;
}
