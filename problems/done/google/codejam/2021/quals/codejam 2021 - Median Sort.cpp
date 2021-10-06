// Problem: Median Sort
// Contest: Google Coding Competitions - Qualification Round 2021 - Code Jam 2021
// URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284
// Memory Limit: 1024 MB
// Time Limit: 40000 ms
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

int32_t main(){

    int t, n, q, res;
    cin >> t >> n >> q;

    while(t--){

        vi vec = {1, 2, 3};

        cout << "1 2 3" << endl;
        cin >> res;

        if(res == 1) vec = {2, 1, 3};
        if(res == 3) vec = {1, 3, 2};

        for(int i = 4; i <= n; i++){

            int l = 0;
            int r = vec.size()-2;

            int ans = -1;

            while(l <= r){

                int m = (l+r)/2;

                cout << vec[m] << ' ' << vec[m+1] << ' ' << i << endl;
                cin >> res;
                assert(res != -1);

                if(res == i){
                    ans = m+1;
                    break;
                }

                if(res == vec[m]){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }

            if(ans == -1){
                if(l == 0) ans = 0;
                else ans = vec.size();
            }

            vec.insert(vec.begin() + ans, i);
        }

        for(auto i : vec) cout << i << ' ' ; cout << endl;
        cin >> res;
        assert(res != -1);
    }
}
