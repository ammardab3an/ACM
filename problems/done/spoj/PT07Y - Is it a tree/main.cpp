#include <bits/stdc++.h>

using namespace std;

int n, N, E;
vector<int> graph[10010];
bool         vist[10010];

void go(int v)
{
    vist[v] = true; n++;
    for(auto nv : graph[v]) if(!vist[nv])
        go(nv);
}
bool dfs(int v, int lv)
{
    vist[v] = true;

    for(auto nv : graph[v]) if(nv != lv)
    {
        if(vist[nv] || !dfs(nv, v))
            return false;
    }
    return true;
}
int main()
{
    // input section
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E;

    for(int fr, to, e = 0; e < E; e++)
    {
        cin >> fr >> to;
        graph[fr].push_back(to);
        graph[to].push_back(fr);
    }

    // check that it is one graph and the number of nodes minus one equal to the number of edges
    memset(vist, false, sizeof vist);
    n = 0; go(1);

    if(((N-1) != E) || (n != N))
        goto no;

    // check that there is no circuits in the graph
    memset(vist, false, sizeof vist);
    for(int v = 1; v <= N; v++) if(!vist[v])
    {
        if(!dfs(v, 0))
            goto no;
    }

    yes : cout << "YES"; return 0;

    no  : cout << "NO";  return 0;
}
