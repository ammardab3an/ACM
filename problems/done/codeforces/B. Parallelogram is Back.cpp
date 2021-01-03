// Problem: B. Parallelogram is Back
// Contest: Codeforces - Codeforces Round #388 (Div. 2)
// URL: https://codeforces.com/problemset/problem/749/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

typedef unsigned int		uint;
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
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

typedef complex<int> pt;

void inputPt(pt &p){
	int x, y;
	cin >> x >> y;
	p = {x, y};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	pt a, b, c;
	
	inputPt(a);
	inputPt(b);
	inputPt(c);
	
	cout << 3 << endl;
	for(pt d : (vector<pt>){a+(b-c), a+(c-b), c+(b-a)})
		cout << d.real() << ' ' << d.imag() << endl;;
}
