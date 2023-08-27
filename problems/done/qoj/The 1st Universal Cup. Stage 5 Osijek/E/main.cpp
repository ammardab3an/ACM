#include <bits/stdc++.h>

#define int int64_t
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> iii;

int32_t main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<pii> vec(n);
    for(auto &[x, y] : vec){
        cin >> x >> y;
    }

    int q;
    cin >> q;

    vector<iii> queries(q);
    for(auto &[k, xy] : queries){
        auto &[x, y] = xy;
        cin >> x >> y >> k;
    }

    vector<double> ans(q, -1);

    queue<pair<pair<double, double>, vi>> que;
    que.push({{0, 1e18}, vi(q)});
    iota(que.front().second.begin(), que.front().second.end(), 0);

    int cur = 1e9;
    int iter_cnt = 100;
    while(iter_cnt--){

        auto fr = que.front();
        que.pop();

        auto [l, r] = fr.first;
        auto &v = fr.second;


    }
}
