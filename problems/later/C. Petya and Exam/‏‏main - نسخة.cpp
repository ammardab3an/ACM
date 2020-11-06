// By AmmarDab3an - Aleppo University
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 200020;

int n, T, a, b;
pii arr[MAX];
int tst[MAX];
int dif[MAX];

bool _can(int time)
{
    int sum = 0;
    int upBo = upper_bound(tst, tst+n, time) - tst;
    for(int i = 0; i < upBo; i++)
        sum += dif[i] ? b : a;
    return sum <= time;
}
bool can(int num)
{
    int sum = 0;
    for(int i = 0; i < num; i++)
        sum += dif[i] ? b : a;
    return _can(sum) && sum <= T;
}
int main()
{
    int t;
    for(cin >> t; t--;)
    {
        cin >> n >> T >> a >> b;
        for(int i = 0; i < n; i++)
            cin >> arr[i].second;
        for(int i = 0; i < n; i++)
            cin >> arr[i].first;

        auto comp = [](const pii &p1, const pii &p2)
        {
            if(p1.first != p2.first)
                return p1.first < p2.first;
            return p1.second < p2.second;
        };

        sort(arr, arr+n, comp);

        for(int i = 0; i < n; i++)
            tst[i] = arr[i].first,
            dif[i] = arr[i].second;

        for(int i = 0; i < n; i++)
            cout << tst[i] << ' ' << dif[i] << endl;

        int ans = 0;
        int low = 0;
        int hi  = n;

        while(low <= hi)
        {
            int mid = (low + hi)/2;
            if(can(mid))
            {
                ans = mid;
                low = mid +1;
            }
            else
                hi = mid -1;
        }

        cout << '-' << ans << endl;
    }
}
