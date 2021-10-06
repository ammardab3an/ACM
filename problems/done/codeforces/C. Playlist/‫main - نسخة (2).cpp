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

    set<pii> st;

    lli ans = 0;
    lli sum = 0;

    for(int i = 0; i < n; i++){

        st.insert({arr[i].second, i});
        sum += arr[i].second;

        while(st.size() > k){
            auto it = st.begin();
            sum -= it -> first;
            st.erase(it);
        }

        ans = max(ans, sum * arr[i].first);
    }

    cout << ans;
}
