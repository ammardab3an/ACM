// Problem: G. Weird Requirements
// Contest: Codeforces - ACM International Collegiate Programming Contest, Damascus University Collegiate Programming Contest(2018)
// URL: https://codeforces.com/gym/101808/problem/G
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

        int n, x, y;
        cin >> n >> x >> y;

        vi vec(n);
        for(auto &i : vec) cin >> i;

        if(y%x != 0){
            cout << -1 << endl;
            continue;
        }

        if(n == 1){

            if(x != y){
                cout << -1 << endl;
            }
            else if(vec[0] == x){
                cout << 0 << endl;
            }
            else{
                cout << 1 << endl;
            }
            continue;
        }

        int cnt = 0;
        vi vis(n);

        for(int i = 0; i < n; i++){

            if((vec[i]%x != 0) || (y%vec[i] != 0)){
                vis[i] = true;
                cnt++;
            }
        }

        int gcd_arr = 0;
        int lcm_arr = 1;

        for(int i = 0; i < n; i++) if(!vis[i]){
            gcd_arr = __gcd(gcd_arr, vec[i]);
            lcm_arr = (lcm_arr * vec[i]) / __gcd(lcm_arr, vec[i]);
        }

//        cout << gcd_arr << ' ' << lcm_arr << endl;

        if(cnt == 0){
            cout << (gcd_arr != x) + (lcm_arr != y) << endl;
        }

        else if(cnt == 1){

            if(gcd_arr == x){
                cout << 1 << endl;
            }
            else{
                cout << 2 << endl;
            }
        }

        else if(cnt >= 2){
            cout << cnt << endl;
        }
    }
}

/*
  arrays sizes
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'

  notes :


*/