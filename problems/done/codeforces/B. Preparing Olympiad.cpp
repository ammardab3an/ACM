#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, l, r, x;
    cin >> n >> l >> r >> x;

    int arr[20];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 0;

    for(int bitMsk = 0; bitMsk < (1 << n); bitMsk++)
    {
        int mn = INT_MAX;
        int mx = INT_MIN;
        long long sm = 0;

        for(int i = 0; i < n; i++)
            if(bitMsk & (1 << i))
        {
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
            sm += arr[i];
        }

        cnt += ((l <= sm) && (sm <= r) && (abs(mx - mn) >= x));
    }

    cout << cnt << endl;
}
