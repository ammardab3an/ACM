// Problem: E. Guess the Cycle Size
// Contest: Codeforces - Codeforces Round #820 (Div. 3)
// URL: https://codeforces.com/contest/1729/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}

int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
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

int ask(int i, int j, int &left){

    if(i==j){
        return 0;
    }

    left--;
    cout << "? " << i << ' ' << j << endl << flush;
    int ret;
    cin >> ret;
    if(ret==0) exit(0);
    return ret;
}

int32_t main(){

    int mx = 1;
    int r = 50;

    int left = 50;

    while(left && r > 1){

        int rn = rand(2, r);

        int a = rn;
        int b = rand(1, rn-1);

//        cout << r << ' ' << a << ' ' << b << endl;

        int a0 = ask(a, b, left);

        if(a0 == -1){
            r = rn-1;
            continue;
        }

        mx = max(mx, a0);

        if(left){
            int a1 = ask(b, a, left);
            if(a0 != a1){
                mx = max(mx, a0+a1);
            }
        }
    }

    if(r==2){
        mx = 2;
    }

    cout << "! " << mx << endl << flush;
}