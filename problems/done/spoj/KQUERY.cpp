#include<bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int N = 200020;

int n;
int arr[N];
int seg[N << 2];

int ans[N];
vector<pii> vec;
vector< pair<pii, pii> > querys;

void update(int nd, int L, int R, int idx, int val)
{
	if(L == R)
	{
		seg[nd] = val;
		return;
	}

	int mid = (L + R) >> 1;

	if(idx <= mid)
		update(nd << 1  ,   L  , mid, idx, val);
	else
		update(nd << 1|1, mid+1,  R , idx, val);

	seg[nd] = seg[nd << 1] + seg[nd << 1|1];
}

int query(int nd, int L, int R, int from, int to)
{
	if(L >= from && to >= R)
		return seg[nd];

	if(to < L || R < from)
		return 0;

	int mid = (L + R) >> 1;

	int leftAns  = query(nd << 1  ,   L  , mid, from, to);
	int rightAns = query(nd << 1|1, mid+1,  R , from, to);

	return leftAns + rightAns;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        vec.push_back({arr[i], i});
    }

    sort(vec.begin(), vec.end());

    int k; scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        int l, r, v;
        scanf("%d%d%d", &l, &r, &v);
        querys.push_back({{v, i}, {l, r}});
    }

    sort(querys.begin(), querys.end(), greater< pair<pii, pii> >());

    for(auto p : querys)
    {
        int v = p.first.first;
        int i = p.first.second;
        int l = p.second.first;
        int r = p.second.second;

        while(vec.size() &&(vec.back().first > v))
        {
            int _i = vec.back().second;
            vec.pop_back();

            update(1, 1, n, _i, 1);
        }
        ans[i] = query(1, 1, n, l, r);
    }

    for(int i = 0; i < k; i++)
        printf("%d\n", ans[i]);
}
