#include <bits/stdc++.h>

#define int int64_t
#define endl '\n'

using namespace std;

const int NMAX = 1e3 + 10;


int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    pre[0] = arr[0];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + arr[i];
    }

    tmp[sz++] = 0;
    for(int i = 0; i < n; i++){
        tmp[sz++] = pre[i];
        tmp[sz++] = pre[i]-x;
    }


    sort(tmp, tmp+sz);
    sz = unique(tmp, tmp+sz) - tmp;

    for(int i = 0; i < n; i++){

        SegTree tree(sz);

        if(i){
            tree.insert(1, 0, sz-1, lower_bound(tmp, tmp+sz, pre[i-1])-tmp, +1);
        }
        else{
            tree.insert(1, 0, sz-1, 0, +1);
        }

        for(int j = i; j < n; j++){

            int r = pre[j];
            int l = tree.query(1, 0, sz-1, )
        }
    }

}
