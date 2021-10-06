#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

long long  seg[N << 2];
long long lazy[N << 2];

void push(int nd, int L, int R)
{
    if(lazy[nd])
    {
        if(L != R)
        {
            lazy[nd << 1  ] += lazy[nd];
            lazy[nd << 1|1] += lazy[nd];
        }
        seg[nd] += lazy[nd]*(R - L +1);
        lazy[nd] = 0;
    }
}
long long query(int nd, int L, int R, int from, int to)
{
    if(from > R || L > to)
        return 0;

    push(nd, L, R);

    if(L >= from && to >= R)
        return seg[nd];

    int mid = (L + R)/2;

    long long leftAns  = query(nd << 1  ,   L  , mid, from, to);
    long long rightAns = query(nd << 1|1, mid+1,  R , from, to);

    return leftAns + rightAns;
}

void updateRange(int nd, int L, int R, int from, int to, int val)
{
    push(nd, L, R);

    if(from > R || L > to)
        return;

    if(L >= from && to >= R)
    {
        lazy[nd] = val;
        push(nd, L, R);
        return;
    }

    int mid = (L + R)/2;
    updateRange(nd << 1  ,   L  , mid, from, to, val);
    updateRange(nd << 1|1, mid+1,  R , from, to, val);

    seg[nd] = seg[nd << 1] + seg[nd << 1|1];
}
int main()
{
    int T, n, c, com, frm, to ,val;
    for(cin >> T; T--;)
    {
        cin >> n >> c;

        memset(seg,  0, sizeof seg);
        memset(lazy, 0, sizeof lazy);

        while(c--)
        {
            cin >> com >> frm >> to;

            if(com)
                cout << query(1, 1, n, frm, to) << endl;
            else
            {
                cin >> val;
                updateRange(1, 1, n, frm, to, val);
            }
        }
    }
}
