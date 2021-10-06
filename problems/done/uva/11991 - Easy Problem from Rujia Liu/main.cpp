#include <bits/stdc++.h>

using namespace std;

array< vector<int>, 1000001 > vec;

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        vec.fill({});

        for(int num, i = 1; i <= n; i++){
            cin >> num; vec[num].push_back(i);
        }

        while(m--)
        {
            int k, v;
            cin >> k >> v;
            cout << ((k <= vec[v].size()) ? vec[v][k-1] : 0)<< endl;
        }
    }
}
