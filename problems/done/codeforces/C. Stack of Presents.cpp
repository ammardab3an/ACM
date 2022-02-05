#include<bits/stdc++.h>

using namespace std;

int n, m;
int stk[100010];
int arr[100010];
int idx[100010];

int main()
{
    int t;
    for(cin >> t; t--;)
    {
        cin >> n >> m;

        for(int i = 1; i <= n; i++)
        {
            cin >> stk[i];
            idx[stk[i]] = i;
        }

        long long ans = 0;
        int lstIdx = 0;

        for(int i = 1; i <= m; i++)
        {
            cin >> arr[i];

            if(idx[arr[i]] < lstIdx)
                ans += 1;
            else
            {
                ans += (idx[arr[i]]-1 -(i-1))*2LL +1LL;
                lstIdx = idx[arr[i]];
            }
        }
        cout << ans << endl;
    }
}
