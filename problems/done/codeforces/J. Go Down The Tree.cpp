// Problem: J. Go Down The Tree
// Contest: Codeforces - STAR Contest 2022
// URL: https://starcontest22.contest.codeforces.com/group/ZbfYu7B821/contest/378214/problem/J
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>  pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> iii;
typedef pair<ll, pll> lll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define endl '\n'
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int x, int y)
{
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b)
{
    int ret = (1ll * (a % MOD) * (b % MOD)) % MOD;
    return (ret + MOD) % MOD;
}

int add(int a, int b)
{
    int ret = (1ll * (a % MOD) + (b % MOD)) % MOD;
    return (ret + MOD) % MOD;
}

int pow_exp(int n, int p)
{
    if (!p)
        return 1;
    if (p & 1)
        return mul(n, pow_exp(n, p - 1));
    int tmp = pow_exp(n, p / 2);
    return mul(tmp, tmp);
}

const int MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
vector<int> adj[NMAX];

int in[NMAX], out[NMAX], tt;
int dist[NMAX], id[NMAX], par[NMAX], vis[NMAX];

int lazy[NMAX << 2];
pii tree[NMAX << 2];

int ans;
vi _ans;

void go(int u, int p)
{

    in[u] = ++tt;
    id[tt] = u;
    par[u] = p;

    for (auto v : adj[u])
    {
        if (v != p)
        {
            dist[v] = dist[u] + 1, go(v, u);
        }
    }

    out[u] = tt;
}

void build(int node, int l, int r, int b = rand())
{

    if (l == r)
    {
        int u = id[l];
        if (adj[u].size() == 1){
            tree[node] = make_pair(dist[u], l);
        }
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void push(int node, int l, int r)
{
    tree[node].first += lazy[node];
    
    if (l != r){	
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    
    lazy[node] = 0;
}

void update(int node, int l, int r, int x, int y, int val, int b = rand())
{
    push(node, l, r);
    
    if (l > r || r < x || l > y || x > y)
        return;
    
    if (l >= x && r <= y)
    {
        lazy[node] += val;
        push(node, l, r);
        return;
    }
    
    int mid = (l + r) / 2;

    update(node * 2, l, mid, x, y, val);
    update(node * 2 + 1, mid + 1, r, x, y, val);
    
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

pii query(int node, int l, int r, int x, int y)
{
    push(node, l, r);
    
    if (l > r || r < x || l > y || x > y)
        return make_pair(0, 0);
    
    if (l >= x && r <= y)
        return tree[node];
    
    int mid = (l + r) / 2;

    pii st_path = query(node * 2, l, mid, x, y);
    pii nd_path = query(node * 2 + 1, mid + 1, r, x, y);
    
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    
    return max(st_path, nd_path);
}

int32_t main()
{

    fastIO;

    cin >> n;
    
    for (int i = 0; i < n-1; i++)
    {
        int u;
        cin >> u;
        adj[i+2].push_back(u);
        adj[u].push_back(i+2);
    }

    dist[1] = 1;
    
    go(1, 0);
    build(1, 1, n);
    
    while (tree[1].first)
    {
        pii p = tree[1];
        ans += p.first;
        
        int u = id[p.second];
        
        while (u != 0 && vis[u] == 0){
            vis[u] = 1;
            update(1, 1, n, in[u], out[u], -1);	
            u = par[u];
        }
        
        _ans.push_back(ans);
    }
    
    while (_ans.size() < n){
        _ans.push_back(_ans.back());
    }
        
    for (auto i : _ans) cout << i << ' '; cout << endl;
}
