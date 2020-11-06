#include <bits/stdc++.h>

using namespace std;

vector<int> vec;

pair<int, int> go(int pos, int d)
{
    pos *= 2;

    if(d == 1)
    {
        int sum = vec[pos] + vec[pos+1];
        return {sum % 10, ((sum >= 10) ?  1 : 0)};
    }

    pair<int, int> path_1, path_2;
    path_1 = go(pos, d-1);
    path_2 = go(pos+1, d-1);

    int sum = path_1.first + path_2.first;

    return {sum % 10, path_1.second + path_2.second + ((sum >= 10) ?  1 : 0)};

}
int main()
{
    int n, k, l, r;

    cin >> n;
    for(int e, i = 0; i < n; i++)
        cin >> e, vec.push_back(e);

    for(cin >> k; k; k--)
    {
        cin >> l >> r;
        if(!(l%2))
            cout << go((l-1)/(r-l+1), log2(r-l+1)).second << endl;
    }
}
