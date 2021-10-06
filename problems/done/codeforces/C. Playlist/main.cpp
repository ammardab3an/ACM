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
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> arr[i].second >> arr[i].first;

    sort(arr, arr+n, greater<pii>());

    multiset<int> mst;

    lli ans = 0;
    lli sum = 0;

    for(int i = 0; i < n; i++){

        mst.insert(arr[i].second);
        sum += arr[i].second;

        while(mst.size() > k){
            auto it = mst.begin();
            sum -= *it;
            mst.erase(it);
        }

        ans = max(ans, sum * arr[i].first);
    }

    cout << ans;
}
