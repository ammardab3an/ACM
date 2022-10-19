// Problem: D. Tournament Countdown
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int ask(int i, int j){

    cout << "? " << i << ' ' << j << endl << flush;
    int ret;
    cin >> ret;

    assert(ret != -1);

    return ret;
}

void ans(int i){
    cout << "! " << i << endl << flush;
}

int32_t main(){

    int t; cin >> t; while(t--){

        int n;
        cin >> n;

        int m = 1 << n;

        vi vec(m);
        iota(vec.begin(), vec.end(), 1);

        while(vec.size() > 1){

            if((int)vec.size()==2){
                if(ask(vec[0], vec[1])==1){
                    vec = {vec[0]};
                }
                else{
                    vec = {vec[1]};
                }
                break;
            }

            vi nvec;

            for(int i = 0; i < (int)vec.size(); i += 4){

                int r = ask(vec[i+1], vec[i+2]);

                if(r==0){
                    if(ask(vec[i], vec[i+3])==1){
                        nvec.push_back(vec[i]);
                    }
                    else{
                        nvec.push_back(vec[i+3]);
                    }
                }
                else if(r==1){
                    if(ask(vec[i+1], vec[i+3])==1){
                        nvec.push_back(vec[i+1]);
                    }
                    else{
                        nvec.push_back(vec[i+3]);
                    }
                }
                else if(r==2){
                    if(ask(vec[i], vec[i+2])==1){
                        nvec.push_back(vec[i]);
                    }
                    else{
                        nvec.push_back(vec[i+2]);
                    }
                }
            }

            vec = nvec;
        }

        ans(vec[0]);
    }
}
