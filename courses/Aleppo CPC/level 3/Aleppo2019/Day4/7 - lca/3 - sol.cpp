#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define ld long double
#define pb push_back
#define sz size

using namespace std;

const int N=1e5+5,L=18;

int t,n,q,EXTRA_EDGE,U,V;

ll dis[N];

int p[N][L] , dep[N] , P[N];
int timer , in[N] , out[N];

vector<pair<int,int> >adj[N];

void dfs(int u,int par)
{
    p[u][0]=par;
    dep[u]=1+dep[par];
    in[u]=++timer;
    for(auto X:adj[u])
        if( X.F!=par )
        {
            dis[X.F]=dis[u]+X.S;
            dfs(X.F,u);
        }
    out[u]=timer;
}

int jump(int u,int k)
{

    for(int i=0; i<L; i++)
    {
        if( k&(1<<i) )
        {
            u=p[u][i];
        }
    }
    return u;
}

int LCA(int u,int v)
{
    if(u==v)
    {
        return u;
    }
    if( dep[u]<dep[v] )
    {
        swap(u,v);
    }
    int dif = dep[u]-dep[v];
    u=jump(u,dif);
    if(u==v)
    {
        return u;
    }

    for(int i=L-1; i>=0; i--)
    {
        if( p[u][i]!=p[v][i] )
        {
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}

ll DIS(int u,int v)
{
    return dis[u]+dis[v]-2*dis[LCA(u,v)];
}

int par(int u)
{
    if (u==P[u])
    {
        return  u;
    }
    return par(P[u]);
}

void join(int u,int v)
{
    if (rand()&1)swap(u,v);
    P[par(u)]=par(v);
    return;
}


int main()
{
    scanf("%d",&t);
    while(t--)
    {

		for (int i=1;i<N;i++)P[i]=i;
		timer=0;

        int u,v,w;
        EXTRA_EDGE=U=V=-1;
        for (int i=1; i<N; i++)adj[i].clear();
        for (int i=1; i<=n; i++)p[i][0]=i;
        scanf("%d%d",&n,&q);
        for (int i=0; i<n; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            if (par(u)!=par(v))
            {
                adj[u].pb({v,w});
                adj[v].pb({u,w});
                join(u,v);
            }
            else
            {
                EXTRA_EDGE=w;
                U=u;
                V=v;
            }
        }
        p[1][0]=1;
        dfs(1,p[1][0]);
        for (int j=1;j<L;j++)
        {
            for (int i=1;i<=n;i++)
            {
                p[i][j]=p[p[i][j-1]][j-1];
            }
        }

        for (int i=0;i<q;i++)
        {
            scanf("%d%d",&u,&v);
            ll ans=min(DIS(u,v),min(DIS(u,U)+EXTRA_EDGE+DIS(v,V),DIS(u,V)+EXTRA_EDGE+DIS(v,U)));
            printf("%lld\n",ans);
        }
    }
}

