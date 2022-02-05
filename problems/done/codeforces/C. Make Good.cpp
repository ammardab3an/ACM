// By AmmarDab3an - Aleppo University.

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, f, t, s)     for(int i = f; i <  t; i += s)
#define RFOR(i, f, t, s)    for(int i = f; i >= t; i -= s)
#define REP(i, n)           FOR(i, 0, n, 1)
#define RREP(i, n)          RFOR(i, n, 0, 1)

#define MEM(a, b)       memset(a, b, sizeof a)

#define inputInt(i)     scanf("%d", &i)
#define inputII(i, j)   scanf("%d%d", &i, &j)
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
const int   MAX = 100010;
const bool  UVA = true;

int n;
int arr[MAX];

void go()
{
    inputInt(n);
    lli sum = 0, xr = 0;
    for(int i = 0; i < n; i++)
    {
        inputInt(arr[i]);
        sum += arr[i];
        xr  ^= arr[i];
    }

    printf("2\n");
    printf("%lld %lld\n", xr, xr + sum);

}
int main()
{
    #ifdef LOCAL_PROJECT
        cout << "local" << endl;
        int choice; inputInt(choice); if(choice){
            freopen("input.txt" , "r", stdin);
            freopen("output.txt", "w", stdout);
        }
    #endif

    int t = 1;
    if(UVA) inputInt(t); while(t--)
        go();
}
