// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vii;

const int N = 2020;

int root;
vii chil[N];

int n;
int Ci[N];
int ans[N];

vii dfs(int node)
{
    vii ret;
    for(int ch : chil[node])
    {
        vii chVec = dfs(ch);
        ret.insert(ret.end(), chVec.begin(), chVec.end());
    }

    if(Ci[node] > ret.size())
    {
        cout << "NO";
        exit(0);
    }

    ret.insert(ret.begin() + Ci[node], node);
    return ret;
}

int main()
{
    cin >> n;
    for(int pa, i = 1; i <= n; i++)
    {
        cin >> pa >> Ci[i];
        chil[pa].push_back(i);
    }

    root = chil[0][0];

    vii order = dfs(root);

    for(int i = 0; i < order.size();)
        ans[order[i]] = ++i;

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}
