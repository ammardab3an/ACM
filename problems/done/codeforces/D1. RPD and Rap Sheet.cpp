
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

//#define endl '\n'
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

int read(){
    int ret;
    cin >> ret;
    return ret;
}

int write(int i){
    cout << i << endl;
    cout.flush();
    return read();
}

int32_t main(){

    int t; cin >> t; while(t--){

        int n, k;
        cin >> n >> k;

        int _xor = 0;

        for(int i = 0; i < n; i++){

            int cur = _xor ^ i;

            if(write(cur)){
                break;
            }
            else{
                _xor ^= cur;
            }
        }
    }
}
