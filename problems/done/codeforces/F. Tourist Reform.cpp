// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

using namespace std;
typedef long long int   lli;
typedef pair<int, int>  pii;

// Global Variables

const int N = 4e5 + 10;

int n, m;
vector<pii> adj[N];
vector<pii> edg(N);

int Low[N], Num[N], clk;
int ans, idx;
stack<int> comp;

void init()
{
    memset(Low, -1, sizeof Low);
    memset(Num, -1, sizeof Num);
    while(comp.size()) comp.pop();
    clk = ans = 0;
}

void dfs(int u, int par)
{
    comp.push(u);
    Num[u] = Low[u] = clk++;

    for(auto el : adj[u])
    {
        int v = el.first;
        int i = el.second;

        if(v == par)
            continue;

        if(Num[v] == -1)
        {
            dfs(v, u);
            edg[i] = {v, u};
            Low[u] = min(Low[u], Low[v]);
        }
        else
        {
            edg[i] = {u, v};
            Low[u] = min(Low[u], Num[v]);
        }
    }

    if(Num[u] == Low[u])
    {
        int compSize = 1;
        while(comp.top() != u){
            compSize++;
            comp.pop();
        }
        comp.pop();

        if(compSize > ans)
        {
            ans = compSize;
            idx = u;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    init();
    dfs(1, 0);
    cout << ans << endl;

    init();
    dfs(idx, 0);

    for(int i = 0; i < m; i++)
        cout << edg[i].first << ' ' << edg[i].second << endl;
}
