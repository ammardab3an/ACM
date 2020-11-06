// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
array<double, 3> arr[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    double ans = 0;
    for(int i =  0 ; i < n; i++)
    for(int j = i+1; j < n; j++)
    {
        double t = (arr[j][0] - arr[i][0]) / (arr[j][1] + arr[i][1]);
        ans += arr[i][2] * (100 - arr[j][2]) * t;
    }

    cout << ans;
}
