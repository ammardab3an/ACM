#include<bits/stdc++.h>

using namespace std;
const int mx = 1e5 +1;
const int oo = 1e9;
int n;
vector<int> a[mx];
int mem[mx][2];
int par[mx];

int dfs(int pos, int f)
{
    if (mem[pos][f] != -1)
        return mem[pos][f];

    int sum = f;
    for (auto to : a[pos])
    {
        if (to != par[pos])
        {
            par[to] = pos;
            int path_1 = dfs(to, 1);
            int path_2 = oo;
            if (f)
                path_2 = dfs(to, 0);
            sum += min(path_1, path_2);
        }
    }
    return mem[pos][f] = sum;
}

int main()
{
    memset(mem, -1, sizeof mem);
    memset(par, -1, sizeof par);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    cout << min(dfs(1,0), dfs(1,1));
    return 0;
}
