// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long int  lli;

// Global Variables
const int MAX = 3e5 + 10;
pii arr[MAX];


int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].second, &arr[i].first);

    sort(arr, arr+n, greater<pii>());

    multiset < int, greater<int> > mst;

    lli ans = 0;
    int pos = 0;

    while(pos < n){

        int mn = arr[pos].first;
        while(pos < n && (mn <= arr[pos].first))
            mst.insert(arr[pos++].second);

        lli sm = 0;

        auto it = mst.begin();
        for(int i = 0; i < k && i < mst.size(); i++)
            sm += *(it++);

        ans = max(ans, sm * (lli)mn);
    }

    printf("%I64d", ans);
}
