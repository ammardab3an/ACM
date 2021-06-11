// Problem: J. Saeed and Folan
// Contest: Codeforces - ACM International Collegiate Programming Contest, Damascus University Collegiate Programming Contest(2018)
// URL: https://codeforces.com/gym/101808/problem/J
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}

int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
}

int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int l1, r1, p1, d1;
        int l2, r2, p2, d2;
        int k;

        cin >> l1 >> r1 >> p1 >> d1;
        cin >> l2 >> r2 >> p2 >> d2;
        cin >> k;

        int cnt = 0;
        int ans = 0;

        int nxt[2] = {-1, +1};

        for(int i = 0; i < k; i++){

            if(p1 == r1 && d1 == 1) d1 = 0;
            if(p1 == l1 && d1 == 0) d1 = 1;

            if(p2 == r2 && d2 == 1) d2 = 0;
            if(p2 == l2 && d2 == 0) d2 = 1;

            p1 += nxt[d1];
            p2 += nxt[d2];

            ans += (p1 == p2);
        }

        cout << ans << endl;
    }
}

/*
  arrays sizes
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'

  notes :


*/