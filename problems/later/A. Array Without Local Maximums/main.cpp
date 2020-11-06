#include <bits/stdc++.h>

using namespace std;

const int N 1e5;
const int MOD 998244353;

//declarations
int n;
int arr[N];

int go(int pos)
{
    int ans = 0;

    if(pos == n)
        return ans;

    if(arr[pos] != -1)
        return go(pos +1);

    if(pos > 0 && pos < n-1)
        for(int i = 1; i <= 200; i++)
        {
            if(i <= max(arr[pos-1], arr[pos+1])
               ans++;
        }

    return ans % MOD;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << go(0);
}
