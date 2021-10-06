// Problem: 441 - Lotto
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=382
// Memory Limit: 32 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	int k, S[12], count = 0;
	
	while (scanf("%d", &k), k) {
	
	            // لان طلب نطبع سطر فاضي بين التستات (ما حنطبع سطر فاضي اخر شي) فنحن رح نطبع سطر فاضي قبل كل تست معدا التست الاول
		if (count++)
			printf("\n");
			
		for (int i = 0; i < k; i++)
			scanf("%d", &S[i]);

        for (int a = 0; a < k - 5; a++)
        for (int b = a + 1; b < k - 4; b++)
        for (int c = b + 1; c < k - 3; c++)
        for (int d = c + 1; d < k - 2; d++)
        for (int e = d + 1; e < k - 1; e++)
        for (int f = e + 1; f < k; f++)
            printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
	}

}
