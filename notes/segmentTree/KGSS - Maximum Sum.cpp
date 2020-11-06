#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int N = 100100;

int arr[N];
pii seg[N << 2];

void build(int nd, int L, int R){

    if(L == R){
        seg[nd] = {arr[L], INT_MIN};
        return;
    }

    int mid = (L + R) >> 1;

    build(nd << 1, L, mid);
    build(nd << 1 | 1, mid+1, R);

    int tmp[4] = {seg[nd << 1].first    , seg[nd << 1].second,
                  seg[nd << 1 | 1].first, seg[nd << 1 | 1].second};
    sort(tmp, tmp+4);
    seg[nd] = {tmp[2], tmp[3]};
}

void update(int nd, int L, int R, int idx, int val){

    if(L == R){
        seg[nd] = {val, INT_MIN};
        return;
    }

    int mid = (L + R) >> 1;

    if(idx <= mid)
        update(nd << 1, L, mid, idx, val);
    else
        update(nd << 1 | 1, mid+1, R, idx, val);

    int tmp[4] = {seg[nd << 1].first    , seg[nd << 1].second,
                  seg[nd << 1 | 1].first, seg[nd << 1 | 1].second};
    sort(tmp, tmp+4);
    seg[nd] = {tmp[2], tmp[3]};
}

pii query(int nd, int L, int R, int from, int to){

    if(to < L || R < from)
        return {INT_MIN, INT_MIN};
    
    if(from <= L && R <= to)
        return seg[nd];
    
    int mid = (L + R) >> 1;

    pii leftAns  = query(nd << 1    ,   L  , mid, from, to);
    pii rightAns = query(nd << 1 | 1, mid+1, R  , from, to);

    int tmp[4] = {leftAns.first , leftAns.second,
                  rightAns.first, rightAns.second};
    sort(tmp, tmp+4);
    return {tmp[2], tmp[3]};
}

int main(){

#ifdef DEBUG
    cout << "debug time" << endl;
    freopen("input.txt", "r", stdin);
#endif


    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    int m;
    for(cin >> m; m--;){

        char fn; int a, b;
        cin >> fn >> a >> b;

        if(fn == 'Q'){
            pii ans = query(1, 1, n, a, b);
            cout << ans.first + ans.second << endl;
        }  

        else
            update(1, 1, n, a, b);
    }
}