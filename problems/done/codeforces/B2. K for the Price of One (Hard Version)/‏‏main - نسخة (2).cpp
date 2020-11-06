#include<bits/stdc++.h>

using namespace std;

#define iii pair< int, pair<int, int> >
#define cnt frp.first
#define pos frp.second.first
#define mon frp.second.second

const int N = 2e5;
const int K = 2e9;

int n, p, k;
int arr[N];

int dij()
{
    int ans = 0;

    priority_queue< iii, vector<iii>, greater<iii> > que;

    for(int i = 0; i < n; i++)
        que.push({0, {i, p}});

    iii frp, last = {-1, {-1, -1}};

    while(!que.empty())
    {
        frp = que.top(); que.pop();

        if(frp == last)
            continue;
        else
            last = frp;

        if(pos == n)
        {
            ans = max(ans, cnt);
            continue;
        }

        que.push({cnt, {pos +1, mon}});

        if(arr[pos] > mon)
            continue;

        que.push({cnt +1, {pos +1, mon - arr[pos]}});

        if(pos +k <= n)
            que.push({cnt +k, {pos +k, mon - arr[pos]}});
    }

    return ans;
}
int main()
{
    int t;
    for(scanf("%d", &t); t--;)
    {
        scanf("%d%d%d", &n, &p, &k);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        sort(arr, arr+n, greater<int>());

        printf("%d\n", dij());
    }
}
