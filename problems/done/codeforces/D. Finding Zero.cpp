// Problem: D. Finding Zero
// Contest: Codeforces - Codeforces Round #770 (Div. 2)
// URL: https://codeforces.com/contest/1634/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

void ans(int i, int j){
    cout << "! " << i+1 << ' ' << j+1 << endl;
    return;
}

int ask(int i, int j, int k){
    cout << "? " << i+1 << ' ' << j+1 << ' ' << k+1 << endl << flush;
    int ret;
    cin >> ret;
    return ret;
}

int32_t main(){

    int t; cin >> t; while(t--){

        int n;
        cin >> n;

    //    4 3 2 1
    //
    //    4 3 2
    //    4 3 1
    //    4 2 1
    //    3 2 1

        vector<pair<int, vi>> tmp;

        for(int i = 0; i < 4; i++)
        for(int j = i+1; j < 4; j++)
        for(int k = j+1; k < 4; k++){
            int cans = ask(i, j, k);
            tmp.push_back({cans, {i, j, k}});
        }

        sort(tmp.begin(), tmp.end());

        int dif = tmp.back().first;

        vi mnmx;
        for(auto i : tmp[tmp.size()-1].second)
        for(auto j : tmp[tmp.size()-2].second) if(i==j){
            mnmx.push_back(i);
            break;
        }

        if(n==4){
            ans(mnmx[0], mnmx[1]);
            continue;
        }

        int md = 0;
        for(auto i : mnmx) if(md==i) md++;

        for(int i = 4; i < n; i++){

            int t0 = ask(mnmx[0], md, i);
            int t1 = ask(mnmx[1], md, i);

            if(t0 > dif || t1 > dif){
            	
            	dif = max({dif, t0, t1});
            	
                if(t0 > t1){
                    mnmx[1] = i;
                }
                else{
                    mnmx[0] = i;
                }
            }

        }

        ans(mnmx[0], mnmx[1]);
    }
}
