#include<bits/stdc++.h>

using namespace std;

int arr[100010];
int sum[100010];

int main()
{
    int n, t;
    cin >> n >> t;

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    int mx = 0;

    for(int i = 1; i <= n; i++)
    {
        int ans = 0;

        int low = 0;
        int hi  = n-i+1;

        while(hi >= low)
        {
            int mid = (hi+low)/2;

            int sm = sum[i+mid-1] - sum[i-1];

            if(sm <= t)
            {
                low = mid+1;
                ans = mid;
            }
            else
                hi = mid-1;
        }
        mx = max(mx, ans);
    }

    cout << mx << endl;
}
