
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

class PipeCuts{
public:
	double probability(vi vec, int l){
		
		int tot = 0;
		int can = 0;

		int n = vec.size();
		sort(vec.begin(), vec.end());

		for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++){
			tot ++;
			if(vec[i] >  l || (vec[j]-vec[i] >  l) || (100-vec[j] >  l)) can++;
		}
		
		return double(can)/double(tot);
	}
};

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    PipeCuts x;
    cout << fixed << setprecision(15);
    cout << x.probability({99, 88, 77, 66, 55, 44, 33, 22, 11}, 50) << endl;
	cout << x.probability({25, 50, 75}, 24) << endl;
}
