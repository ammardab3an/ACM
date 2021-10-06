// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 100010;

int  n;
pii  arr[N];
int  mxArr[N];
int  mnArr[N];

int main()
{
    cin >> n;

    for(int l, i = 0; i < n; i++)
    {
        cin >> l;
        int mx = INT_MIN;
        int mn = INT_MAX;

        bool bo = false;
        for(int num, j = 0; j < l; j++)
        {
            cin >> num;
            bo += mn < num;
            mx = max(mx, num);
            mn = min(mn, num);
        }
        if(bo)
            mx = INT_MAX, mn = INT_MIN;
        arr[i] = {mx, mn};
    }


    sort(arr, arr+n);

    for(int i = 0; i < n; i++)
        mxArr[i] = arr[i].first,
        mnArr[i] = arr[i].second;


    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        int upBoIdx = upper_bound(mxArr, mxArr + n, mnArr[i]) - mxArr;
        ans += n - upBoIdx;
    }
    cout << ans;
}

