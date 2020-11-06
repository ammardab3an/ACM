#include<bits/stdc++.h>

using namespace std;

const int N = 2e5;
const int K = 2e9;

int arr[N];
int n, p, k;

int main()
{
    int t;
    for(cin >> t; t--;)
    {
        cin >> n >> p >> k;
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr+n);

        int ans = 0;
        int pre = 0;

        for(int i = 0; i < k; i++)
        {
            if(pre > p) break;

            int cnt = i;
            int sum = pre;

            for(int j = (i +k -1); j < n; j += k)
            {
                if(sum + arr[j] > p) break;

                cnt += k;
                sum += arr[j];
            }

            pre += arr[i];
            ans  = max(ans, cnt);
        }
        cout << ans << endl;
    }
}
