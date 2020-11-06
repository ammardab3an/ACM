#include<bits/stdc++.h>

using namespace std;

const int N = 200020;

#define pii pair<int, int>

int n;
int arr[N];
int seg[2][N << 2];
bool go(int low, int hi);

void build(int nd, int L, int R)
{
	if(L == R)
	{
		seg[0][nd] = seg[1][nd] = arr[L];
		return;
	}

	int mid = (L + R) >> 1;

	build(nd << 1  ,   L  , mid);
	build(nd << 1|1, mid+1,  R );

    seg[1][nd] = max(seg[1][nd << 1], seg[1][nd << 1|1]);
    seg[0][nd] = min(seg[0][nd << 1], seg[0][nd << 1|1]);
}

pii query(int nd, int L, int R, int from, int to)
{
	if(L >= from && to >= R)
		return {seg[1][nd], seg[0][nd]};

	if(to < L || R < from)
		return {INT_MIN, INT_MAX};

	int mid = (L + R) >> 1;

	pii leftAns  = query(nd << 1  ,   L  , mid, from, to);
	pii rightAns = query(nd << 1|1, mid+1,  R , from, to);

    return {max(leftAns.first, rightAns.first), min(leftAns.second, rightAns.second)};
}

int main()
{
    int t;
    for(scanf("%d", &t); t--;)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);

        build(1, 1, n);

        if(!go(1, n))
            printf("NO\n");
    }
}
bool go(int low, int hi)
{
    if(low < 1 || hi > n || low > hi)
        return false;

    pii que = query(1, 1, n, low, hi);
    int mx = que.first;
    int mn = que.second;

    if((mx-mn) >= (hi-low+1))
    {
        printf("YES\n");
        printf("%d %d\n", low, hi);
        return true;
    }

    for(int mid = (low+hi)/2; mid; mid/=2)
    {
        if(go(low + mid, hi)) return true;
        if(go(low, hi - mid)) return true;
    }
    return false;
}
