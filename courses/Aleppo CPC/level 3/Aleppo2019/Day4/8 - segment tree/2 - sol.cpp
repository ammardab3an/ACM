#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a ; i <= b ; i++)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

const int OO = 1e9+7;
const int MOD = 1e9+7;
const int N = 4e5+7;

int c[N];
ll a[N];
ll st[N*4];
ll lazy[N*4];
int in[N],out[N];
int timer;
vi G[N];

void dfs(int u,int par)
{
    in[u] = ++timer;
    //cout << u << endl;
    for(auto v:G[u])
    {
        if (v != par)
        {
            dfs(v,u);
        }
    }

    out[u] = timer;
}

void build(int p,int l,int r)
{
    if (l==r) {st[p] = (1LL<<a[l]);return;}
    int mid = (l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    st[p] = st[p*2]|st[p*2+1];
}

void update(int p,int l,int r,int i,int j,ll f)
{
    if (lazy[p])
    {
        st[p] = lazy[p];
        if( l!=r )
        lazy[p*2] = lazy[p*2+1] = lazy[p];
        lazy[p] = 0;
    }

    if (l >= i && r <= j)
    {
        st[p] = (1LL<<f);
        if( l!=r )
        lazy[p*2] = lazy[p*2+1] = st[p];
        return;
    }
    else if (r < i || l > j) return;
    int mid = (l+r)/2;
    update(p*2,l,mid,i,j,f);
    update(p*2+1,mid+1,r,i,j,f);
    st[p] = st[p*2]|st[p*2+1];
}

ll rsq(int p,int l,int r,int i,int j)
{
    if(lazy[p])
    {
        st[p] = lazy[p];
        if( l!=r )
        lazy[p*2] = lazy[p*2+1] = lazy[p],
        lazy[p] = 0;

    }

    if (l >= i && r <= j) return st[p];
    else if (r < i || l > j) return 0;
    int mid = (l+r)/2;
    ll p1 = rsq(p*2,l,mid,i,j);
    ll p2 = rsq(p*2+1,mid+1,r,i,j);
    return p1|p2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m;
    cin >> n >> m;
    REP(i,1,n)
    {
        cin >> c[i];
    }
    REP(i,1,n-1)
    {
        int x,y;
        cin >> x >> y;
        G[x].PB(y);
        G[y].PB(x);
    }
    dfs(1,1);
    REP(i,1,n)
    {
        //cout << in[i] <<endl;
        a[in[i]] = c[i];
    }
    build(1,1,n);

    REP(k,0,m-1)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v,c;
            cin >> v >> c;
            update(1,1,n,in[v],out[v],c);
        }
        else
        {
            int v;
            cin >> v;
            ll d = rsq(1,1,n,in[v],out[v]);
            cout << __builtin_popcountll(d) << endl;
        }
    }
    return 0;
}