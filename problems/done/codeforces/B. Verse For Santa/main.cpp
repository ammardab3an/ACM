#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int n, s;
int arr[100010];
lli sum[100010];

bool can(int cnt, int ski)
{
    lli Sum = sum[cnt-1];

    if(ski != -1 && ski < cnt)
    {
                Sum -= sum[ski];
        if(ski) Sum += sum[ski-1];
    }

    return Sum <= s;
}

int Max(int ski)
{
    int ans = 0;

    int hi  = n;
    int low = 1;

    while(low <= hi)
    {
        int mid = (low + hi)/2;
        if(can(mid, ski))
        {
            ans = mid;
            low = mid+1;
        }
        else
            hi = mid-1;
    }

    return ans;
}
int go()
{
    int idx = -1;
    int mx  = Max(-1);

    for(int i = 0; i < n; i++)
    {
        int nMx = Max(i);

        if(nMx > mx)
        {
            idx = i;
            mx  = nMx;
        }
    }
    return idx +1;
}
int main()
{
    int t;
    for(cin >> t; t--;)
    {
        cin >> n >> s;
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        sum[0] = arr[0];
        for(int i = 1; i < n; i++)
            sum[i] = sum[i-1] + arr[i];

        cout << go() << endl;
    }
}
