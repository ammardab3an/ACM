#include<bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;
const int maxn = 1111;
int n, m, u, v, c, tot, d, num[maxn];

struct Edge
{
    int from, to, cap, flow;
};

bool operator < (const Edge& a, const Edge& b)
{
    return a.from < b.from || (a.from == b.from && a.to < b.to);
}

int get_id(int day, int city)
{
    return day * n + city;
}

struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void init(int n)
    {
        for(int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap)
    {
        edges.push_back((Edge){from, to, cap, 0});
        edges.push_back((Edge){to, from, 0, 0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        vis[s] = 1;
        d[s] = 0;
        while(!Q.empty())
        {
            int x = Q.front(); Q.pop();

            for(int i = 0; i < G[x].size(); i++)
            {
                Edge& e = edges[G[x][i]];
                if(!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x, int a)
    {
        if(x == t || a == 0)
            return a;
        int flow = 0, f;
        for(int& i = cur[x]; i < G[x].size(); i++)
        {
            Edge& e = edges[G[x][i]];
            if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if(a == 0)
                    break;
            }
        }
        return flow;
    }

    int Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        while(BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
} g;


struct node
{
    int u, v, c, p, e;
    node(int u=0, int v=0, int c=0, int p=0, int e=0):u(u),v(v),c(c),p(p),e(e) {}
    bool operator < (const node& rhs) const
    {
        return p < rhs.p;
    }
} a[maxn];

bool solve(int P)
{
    g.init((n+1) * (d+1) + 10);
    int sor = (n+1)*(d+1) + 1;
    int tor = get_id(d, n);
    for(int i = 1; i <= n; i++)
    {
        int id = get_id(0, i);
        g.AddEdge(sor, id, num[i]);

        for(int j = 0; j < d; j++)
        {
            int id1 = get_id(j, i);
            int id2 = get_id(j+1, i);;
            g.AddEdge(id1, id2, INF);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(a[i].p <= P)
        {
            if(a[i].e >= d)
                continue;
            int id1 = get_id(a[i].e, a[i].u);
            int id2 = get_id(a[i].e+1, a[i].v);
            g.AddEdge(id1, id2, a[i].c);
        }
        else
            break;
    }
    int ans = g.Maxflow(sor, tor);
    if(ans == tot)
        return true;
    return false;
}

int main()
{
    int _T; scanf("%d", &_T);
    for(int T = 1; T <= _T; T++)
    {
        scanf("%d%d%d", &n, &d, &m);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%d%d%d", &a[i].u, &a[i].v, &a[i].c, &a[i].p, &a[i].e);
        }
        sort(a+1, a+m+1);
        tot = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            tot += num[i];
        }

        int ans = INF;
        for(int i = 1; i <= m; i++)
        {
            if(solve(a[i].p))
            {
                ans = a[i].p;
                break;

            }
        }
        printf("Case #%d: ", T);
        cout << ((ans == INF) ? "Impossible" : to_string(ans)) << endl;
    }
    return 0;
}
