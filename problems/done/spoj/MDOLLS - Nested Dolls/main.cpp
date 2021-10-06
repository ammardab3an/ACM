// By AmmarDab3an - Aleppo University.

#include <bits/stdc++.h>

using namespace std;

#define MEM(a, b)       memset(a, b, sizeof a)

#define FOR(i, f, t, s)     for(int i = f; i <  t; i += s)
#define RFOR(i, f, t, s)    for(int i = f; i >= t; i -= s)
#define REP(i, n)           FOR(i, 0, n, 1)
#define RREP(i, n)          RFOR(i, n, 0, 1)

#define inputInt(i)     scanf("%d", &i)
#define inputII(i, j)   scanf("%d %d", &i, &j)
#define inputLli(i)     scanf("%lld", &i)
#define inputF(f)       scanf("%f", &f)
#define inputC(c)       scanf("%c", &c)
#define printInt(i)     printf("%d", i)
#define printII(i, j)   printf("%d %d", i, j)
#define printLli(i)     printf("%lld", i)
#define printStr(s)     printf("%s", s.c_str())
#define printC(c)       printf("%c", c)
#define printEndl()     printf("\n")

#define INF      1e9
#define EPS      1e-9
#define PI       3.1415926535897932384626433832795
#define MOD      1000000007

typedef long long           lli;
typedef pair<int, int>      pii;
typedef pair<pii, int>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

//Declarations
const bool  UVA = true;
const int   MAX = 20020;

int n;
pii dolls[MAX];

void go()
{
    inputInt(n);
    REP(i, n)
        inputII(dolls[i].first, dolls[i].second);

    auto comp = [](const pii &p1, const pii &p2)
    {
        if(p1.first != p2.first)
            return p1.first > p2.first;
        return p1.second < p2.second;
    };

    sort(dolls, dolls + n, comp);

    vector<pii> LIS;
    LIS.push_back(dolls[0]);

    for(int i = 1; i < n; i++)
    {
        int ans = -1;
        int l = 0, r = LIS.size() -1;

        while(l <= r)
        {
            int mid = (l + r)/2;
            if(LIS[mid].second > dolls[i].second)
            {
                ans = mid;
                r = mid -1;
            }
            else
                l = mid +1;
        }

        if(ans == -1)
            LIS.push_back(dolls[i]);
        else
            LIS[l] = dolls[i];
    }

    printInt(LIS.size());
    printEndl();
}
int main()
{
    int t = 1;
    if(UVA) inputInt(t); while(t--)
        go();
}
