// Problem: ASeDatAb
// Contest: Google Coding Competitions - Round 1B 2022 - Code Jam 2022
// URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000acd29b
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

//#define endl '\n'
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

int ask(int x){

    cout << bitset<8>(x) << endl << flush;

    int ret;
    cin >> ret;

    if(ret==-1){
        exit(0);
    }

    return ret;
}

int32_t main()
{

    int t; cin >> t; while(t--){

        int cnt = ask(0);

        vector<int> vec;

        for(int i = 0; i < (1<<8); i++) if(__builtin_popcount(i)==cnt){
            vec.push_back(i);
        }

        while(cnt){

            vi tmp_x(8);
            tmp_x[0] = vec[rand(0, vec.size()-1)];

            for(int i = 1; i < 8; i++){
                tmp_x[i] = tmp_x[i-1];
                int b = tmp_x[i]&1;
                tmp_x[i] >>= 1;
                tmp_x[i] |= b << 7;
            }

            cnt = ask(tmp_x[0]);

            vector<int> nvec;
            for(auto i : vec)
            for(auto x : tmp_x){
                if(__builtin_popcount(i^x) == cnt){
                    nvec.push_back(i^x);
                }
            }

            sort(nvec.begin(), nvec.end());
            nvec.resize(unique(nvec.begin(), nvec.end()) - nvec.begin());
            vec = nvec;
        }

    }
}
