#include <bits/stdc++.h>

using namespace std;

long long n[3], p[3], BSC[3], r;

bool can(long long cnt)
{
    long long _r = 0;
    for(int i = 0; (i < 3) && (r >= _r); i++)
        if(cnt * BSC[i] > n[i])
            _r += (cnt * BSC[i] - n[i]) * p[i];
    return r >= _r;
}
int main()
{
    string rec;
    cin >> rec;

    cin >> n[0] >> n[1] >> n[2]
        >> p[0] >> p[1] >> p[2]
        >> r;

    BSC[0] = count(rec.begin(), rec.end(), 'B');
    BSC[1] = count(rec.begin(), rec.end(), 'S');
    BSC[2] = count(rec.begin(), rec.end(), 'C');

    long long low = 0, hi = 1e13 , mid, ans;
    while(hi >= low)
    {
        mid = (low + hi)/2;
        if(can(mid))
        {
            low = mid +1;
            ans = mid;
        }
        else
            hi = mid -1;
    }

    cout << ans;
    return 0;
}
