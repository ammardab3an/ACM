#include<bits/stdc++.h>

using namespace std;

//declarations
#define pii pair<int, int>
#define P first
#define K second
int arr[11][101][3];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    memset (arr, 0, sizeof arr);
    for(int p = 0; p < n; p++)
    {
        string str; cin >> str;
        for(int i = 0; i < m; i++)
            cin >> arr[p][i][0] >> arr[p][i][1] >> arr[p][i][2];
    }

    int mx = 0;
    for(int p1 = 0; p1 < n; p1++)
    for(int p2 = 0; p2 < n; p2++) if (p1 != p2)
    {
        vector<pii> pro;
        for(int i = 0; i < m; i++)
        {
            pii p = {-(arr[p2][i][1]-arr[p1][i][0]), arr[p1][i][2]};
            if (-p.P > 0 && p.K > 0)
                pro.push_back(p);
        }
        sort(pro.begin(), pro.end());

        int _k = k, cnt = 0;
        for(auto item : pro)
        {
            if(_k > item.K)
            {
                cnt += item.K * -item.P;
                _k -= item.K;
            }
            else
            {
                cnt += _k * -item.P;
                break;
            }
        }
        mx = max(mx, cnt);
    }

    cout << mx << endl;
    return 0;
}
