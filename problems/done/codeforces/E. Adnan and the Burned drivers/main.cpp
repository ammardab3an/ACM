
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

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
const int POW = 2e5 + 3;

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
char str[2][NMAX];
int  seg[2][NMAX << 2];
int fast_power[NMAX];

void seg_build(int nd, int L, int R, bool k){

    if(L == R){
        seg[k][nd] = str[k][L] - 'a' + 1;
        return;
    }

    int mid = (L+R) >> 1;
    seg_build(nd << 1, L, mid, k);
    seg_build(nd << 1 | 1, mid+1, R, k);

    seg[k][nd] = (seg[k][nd << 1] + (fast_power[mid-L+1] * seg[k][nd << 1 | 1])%MOD)%MOD;
}

void seg_update(int nd, int L, int R, int idx, char val, bool k){

    if(L == R){
        str[k][L] = val;
        seg[k][nd] = str[k][L] - 'a' + 1;
        return;
    }

    int mid = (L+R) >> 1;

    if(idx <= mid)
        seg_update(nd << 1, L, mid, idx, val, k);
    else
        seg_update(nd << 1 | 1, mid+1, R, idx, val, k);

    seg[k][nd] = (seg[k][nd << 1] + (fast_power[mid-L+1] * seg[k][nd << 1 | 1])%MOD)%MOD;
}

int seg_query(int nd, int L, int R, int from, int to, bool k){

    if(to < L || R < from)
        return 0;

    if(from <= L && R <= to)
        return fast_power[L-from] * seg[k][nd];

    int mid = (L+R) >> 1;
    int leftAns  = seg_query(nd << 1, L, mid, from, to, k);
    int rightAns = seg_query(nd << 1 | 1, mid+1, R, from, to, k);

    return (leftAns + rightAns)%MOD;
}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    fast_power[0] = 1;
    for(int i = 1; i < NMAX; i++){
        fast_power[i] = fast_power[i-1] * POW;
        fast_power[i] %= MOD;
    }

    int t; cin >> t; while(t--){

        cin >> n >> m;

        char tmp[n];
        cin >> tmp;

        strcpy(str[0]+1, tmp);
        reverse(tmp, tmp+n);
        strcpy(str[1]+1, tmp);

        seg_build(1, 1, n, 0);
        seg_build(1, 1, n, 1);

        while(m--){

            int k;
            cin >> k;

            if(k == 1){
                int idx; char c;
                cin >> idx >> c;
                seg_update(1, 1, n, idx, c, 0);
                seg_update(1, 1, n, n-idx+1, c, 1);
            }

            else{
                int l, r;
                cin >> l >> r;
                int a0 = seg_query(1, 1, n, l, r, 0);
                int a1 = seg_query(1, 1, n, n-r+1, n-l+1, 1);
                cout << (a0 == a1 ? "Adnan Wins" : "ARCNCD!") << endl;
            }
        }

    }
}
