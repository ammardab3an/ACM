#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int N = 100100;

int n;
int arr[N];
pii seg[N << 2];

void build(int nd, int L, int R)
{
	if(L == R)
	{
		seg[nd] = {arr[L], INT_MIN};
		return;
	}

	int mid = (L + R) >> 1;

	build(nd << 1  ,   L  , mid);
	build(nd << 1|1, mid+1,  R );

    vector<int> vec = {seg[ nd << 1 ].first, seg[ nd << 1 ].second,
                       seg[nd << 1|1].first, seg[nd << 1|1].second};
    sort(vec.begin(), vec.end());
	seg[nd] = {vec[2], vec[3]};
}

void update(int nd, int L, int R, int idx, int val)
{
	if(L == R)
	{
		seg[nd] = {val, INT_MIN};
		return;
	}

	int mid = (L + R) >> 1;

	if(idx <= mid)
		update(nd << 1  ,   L  , mid, idx, val);
	else
		update(nd << 1|1, mid+1,  R , idx, val);


	vector<int> vec = {seg[ nd << 1 ].first, seg[ nd << 1 ].second,
	                   seg[nd << 1|1].first, seg[nd << 1|1].second};
    sort(vec.begin(), vec.end());
	seg[nd] = {vec[2], vec[3]};
}

pii query(int nd, int L, int R, int from, int to)
{
	if(L >= from && to >= R)
		return seg[nd];

	if(to < L || R < from)
		return {INT_MIN, INT_MIN};

	int mid = (L + R) >> 1;

	pii leftAns  = query(nd << 1  ,   L  , mid, from, to);
	pii rightAns = query(nd << 1|1, mid+1,  R , from, to);

	vector<int> vec = {leftAns.first , leftAns.second,
	                   rightAns.first, rightAns.second};
    sort(vec.begin(), vec.end());
	return {vec[2], vec[3]};
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];

	build(1, 1, n);

    int k; cin >> k;
    while(k--)
    {
    	char fn; int aa, bb;
    	cin >> fn >> aa >> bb;

    	if(fn == 'Q')
    	{
    		pii que = query(1, 1, n, aa, bb);
    		cout << que.first + que.second << endl;
    	}
    	else
    		update(1, 1, n, aa, bb);
    }
}
