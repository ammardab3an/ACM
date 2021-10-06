#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int lazy[N << 2];
array<int, 3>  seg[N << 2];

void build(int nd, int L, int R)
{
    if(L == R)
    {
        seg[nd][0] = 1;
        return;
    }

    int mid = (L + R)/2;
    build(nd << 1  ,  L   , mid);
    build(nd << 1|1, mid+1,  R );

    for(int i = 0; i < 3; i++)
        seg[nd][i] = seg[nd << 1][i] + seg[nd << 1|1][i];
}
void push(int nd, int L, int R)
{
    lazy[nd] %= 3;

    if(!lazy[nd])
        return;

    array<int, 3> tmp;

    for(int i = 0; i < 3; i++)
        tmp[i] = seg[nd][((lazy[nd])%2 + i + 1) %3];

    seg[nd] = tmp;

    if(L != R)
    {
        lazy[nd << 1  ] += lazy[nd];
        lazy[nd << 1|1] += lazy[nd];
    }

    lazy[nd] = 0;
}
int query(int nd, int L, int R, int from, int to)
{
    push(nd, L, R);

    if(L >= from && to >= R)
        return seg[nd][0];

    if(from > R || L > to)
        return 0;

    int mid = (L + R) /2;

    int leftAns  = query(nd << 1  ,  L   , mid, from, to);
    int rightAns = query(nd << 1|1, mid+1,  R , from, to);

    return leftAns + rightAns;
}
void updateRange(int nd, int L, int R, int from, int to, int val)
{
    push(nd, L, R);

    if(from > R || L > to)
        return;

    if(L >= from && to >= R)
    {
        lazy[nd] += val;
        push(nd, L, R);
        return;
    }

    int mid = (L + R)/2;
    updateRange(nd << 1  ,   L  , mid, from, to, val);
    updateRange(nd << 1|1, mid+1,  R , from, to, val);

    for(int i = 0; i < 3; i++)
        seg[nd][i] = seg[nd << 1][i] + seg[nd << 1|1][i];
}
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);

    build(1, 0, n-1);

    while(q--)
    {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if(t)
            printf("%d\n", query(1, 0, n-1, l, r));
        else
            updateRange(1, 0, n-1, l, r, 1);
    }
}
