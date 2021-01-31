
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
const int NMAX = 1e5 + 10;
const int MMAX = 1e5 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m;
int arr[NMAX];
int ans[MMAX];

struct query{
    int lo, hi, idx;
    bool operator < (query other){
        if(lo/BLOCK != other.lo/BLOCK) return lo < other.lo;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
} q[MMAX];

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    while(cin >> n >> m){

        for(int i = 0; i < n; i++) cin >> arr[i];

        for(int i = 0; i < m; i++) {
            cin >> q[i].lo >> q[i].hi;
            q[i].lo--, q[i].hi--, q[i].idx = i;
        }

        sort(q, q+m);

        map<int, int> mp;
        priority_queue<pii> que;

        int l = 1, r = 0;

        for(int i = 0; i < m; i++){

            int cl = q[i].lo;
            int cr = q[i].hi;
            int ci = q[i].idx;

            while(r < cr){
                mp[arr[++r]]++;
                que.push({mp[arr[r]], arr[r]});
            }

            while(cl < l){
                mp[arr[--l]]++;
                que.push({mp[arr[l]], arr[l]});
            }

            while(cr < r){
                mp[arr[r]]--;
                que.push({mp[arr[r]], arr[r]}); r--;
            }

            while(l < cl){
                mp[arr[l]]--;
                que.push({mp[arr[l]], arr[l]}); l++;
            }

            int cans = 0;

            while(!que.empty()){

                auto tp = que.top();

                int cnt = tp.first;
                int val = tp.second;

                if(cnt != mp[val]) {
                    que.pop();
                    continue;
                }

                cans = cnt;
                break;
            }

            ans[ci] = cans;
        }

        for(int i = 0; i < m; i++) cout << ans[i] << endl;
    }
}
