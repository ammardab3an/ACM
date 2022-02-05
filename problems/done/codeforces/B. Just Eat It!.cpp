// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

long long arr[100010];
long long sum[100010];

int main()
{
    int t;
    for(cin >> t; t--;)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }

        if(!sum[n])
        {
            cout << "NO" << endl;
            goto next;
        }

        for(int i = 1; i <= n; i++) if(arr[i] < 0)
        {
            if((-arr[i] >= sum[i-1]) || (-arr[i] >= (sum[n] - sum[i])))
            {
                cout << "NO" << endl;
                goto next;
            }
        }

        cout << "YES" << endl;
        next:;
    }
}
