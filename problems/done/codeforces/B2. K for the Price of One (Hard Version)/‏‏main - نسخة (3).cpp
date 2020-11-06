#include<bits/stdc++.h>

using namespace std;

const int N = 2e5;
const int K = 2e9;

int arr[N];
int n, p, k;

int Cnt(int np, int shift)
{
    int i, j, cnt = 0;
    for(i = k -1 +shift; i < n; i += k)
    {
        if(arr[i] > np)
            break;
        np -= arr[i];
        cnt += k;
    }
    for(j = i -k +1; j < n; j++)
    {
        if(arr[j] > np)
            break;
        np -= arr[j];
        cnt += 1;
    }
    return cnt;
}

bool can(int cnt)
{
    int ans = 0;

    for(int shift = 0; shift < k; shift++)
    {
        if(shift)
        {
            if(arr[shift-1] > p)
                break;
            for(int i = 1; i <= shift; i++)
                ans = max(ans, 1 +Cnt(p - arr[shift -i], shift));
        }
        ans = max(ans, Cnt(p, shift));
    }

    return ans >= cnt;
}
int bs()
{
    int  hi = n;
    int low = 0;
    int ans = 0;

    while(low <= hi)
    {
        int mid = (hi + low)/2;
        if(can(mid))
        {
            ans = mid;
            low = mid +1;
        }
        else
            hi = mid-1;
    }
    return ans;
}
int main()
{
    int t;
    for(cin >> t; t--;)
    {
        cin >> n >> p >> k;
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr+n);

        cout << bs() << endl;
    }
}
