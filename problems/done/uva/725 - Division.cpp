// Problem: 725 - Division
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=666
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

bool alldiff(int n, int m) {
	if (n >= 100000)
		return false;

	int c, mask = 0;
	for (int i = 0; i < 5; i++) {
		c = (int) (n / pow(10, i)) % 10;
		if ((mask >> c) % 2)
			return false;
		mask |= 1 << c;
	}
	for (int i = 0; i < 5; i++) {
		c = (int) (m / pow(10, i)) % 10;
		if ((mask >> c) % 2)
			return false;
		mask |= 1 << c;
	}

	return true;
}


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
	int n, count = 0;

	while (scanf("%d", &n), n) {
	    
		bool found = false;
		
// لان طلب نطبع سطر فاضي بين التستات (ما حنطبع سطر فاضي اخر شي) فنحن رح نطبع سطر فاضي قبل كل تست معدا التست الاول
		if (count++)
			printf("\n");

		for (int abcde = 1234; abcde < 98765; abcde++) {
		    
			int fghij = abcde * n;
			
			if (alldiff(fghij, abcde)) {
				printf("%05d / %05d = %d\n", fghij, abcde, n);
				found = true;
			}
		}
		
		if (!found)
			printf("There are no solutions for %d.\n", n);
	}

}
