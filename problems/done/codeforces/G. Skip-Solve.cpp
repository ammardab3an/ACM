// Problem: G. Skip-Solve
// Contest: Codeforces - STAR Contest 2022
// URL: https://starcontest22.contest.codeforces.com/group/ZbfYu7B821/contest/378214/problem/G
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
typedef pair<int, int> pii;
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

int n, k;
int arr[NMAX];
pii tree[NMAX << 2];
vector<int> tmp;

void build(int nd, int l, int r, int b = 0)
{

    if (l == r)
    {
        tree[nd] = {arr[l], l};
        return;
    }

    int mid = (l + r) / 2;

    build(nd * 2, l, mid);
    build(nd * 2 + 1, mid + 1, r);

    tree[nd] = min(tree[nd * 2], tree[nd * 2 + 1]);
}

pii query(int nd, int l, int r, int x, int y, int b = 0)
{

    if (l > r || r < x || l > y || x > y)
    {
        return {INF, 0};
    }

    if (l >= x && r <= y)
    {
        return tree[nd];
    }

    int mid = (l + r) / 2;

    pii st_path = query(nd * 2, l, mid, x, y);
    pii nd_path = query(nd * 2 + 1, mid + 1, r, x, y);

    return min(st_path, nd_path);
}

void update(int nd, int l, int r, int idx, int val, int b = 0)
{

    if (l == r)
    {
        tree[nd] = {val, l};
        return;
    }

    int mid = (l + r) / 2;

    if (idx <= mid)
        update(nd * 2, l, mid, idx, val);
    else
        update(nd * 2 + 1, mid + 1, r, idx, val);

    tree[nd] = min(tree[nd * 2], tree[nd * 2 + 1]);
}

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        
        build(1, 1, n);

        tmp.clear();
        
        int ii = 2;
        for (int i = 1; i <= n; i++)
        {
        	pii p = query(1, 1, n, 1, min(ii, n));
        	
        	int v = p.first;
        	
            if (v > k){
                break;
            }
            
            if (ii < n){
                ii += 2;
            }
            
            k -= v;
            tmp.push_back(p.second);
            update(1, 1, n, p.second, INF);
        }
        
        cout << tmp.size() << endl;
        
        for (auto i : tmp) cout << i << ' '; cout << endl;
    }
}