// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef pair<lli, int> Pair;
const lli INF = 1e18;

vector<Pair> factors(lli num)
{
    vector<Pair> pri;
    for(lli i = 2; i*i <= num; i++) if(num % i == 0)
    {
        int t = 0;
        while(num % i == 0) num /= i, t++;
        pri.push_back({i, t});
    }
    if(num > 1) pri.push_back({num, 1});
    return pri;
}
int main()
{
    lli n;
    cin >> n;

    vector<Pair> vec = factors(n);
    for(Pair &p : vec) p.first = pow((long double)p.first, p.second);

    pair<lli, lli> ans = {INF, INF};

    for(int i = 0; i < 1 << vec.size(); i++)
    {
        lli a = 1, b = 1;
        for(int j = 0; j < vec.size(); j++)
        {
            if(i & (1 << j))
                a *= vec[j].first;
            else
                b *= vec[j].first;
        }
        if(a < b) swap(a, b);
        ans = min(ans, {a, b});
    }
    cout << ans.first << ' ' << ans.second;
}
