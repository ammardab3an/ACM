
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

    string str0, str1;
    cin >> str0 >> str1;

    int n = str0.size();

    int fpos0 = 0, fpos1 = 0;

    for(int i = 0; i < n; i++) 
		fpos0 += (str0[i] == '+') - (str0[i] == '-');

    int numq = 0;

    for(int i = 0; i < n; i++) {
		if(str1[i] != '?'){
			fpos1 += (str1[i] == '+') - (str1[i] == '-');
		}
		else{
			numq++;
		}
	}
    
	double ans = 0;

	for(int i = 0; i < (1 << numq); i++){
		int cpos = fpos1;
		for(int j = 0; j < numq; j++) cpos += bool(i & (1 << j)) - bool(!(i & (1 << j)));
		if(cpos == fpos0) ans += pow(0.5, numq);
	}

	cout << fixed << setprecision(12) << ans << endl;

}
