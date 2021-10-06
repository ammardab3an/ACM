#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second

using namespace std;

typedef unsigned long long  ull;
typedef long long int       ll;
typedef long double         ld;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<ll, ll>        pll;
typedef pair<ll, pll>       lll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<pii>         vpii;

const int OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int pi = acos(-1);
const double EPS = 1e-9;

const int NMAX = 1E4 + 10;

int tree[NMAX << 2];
char str[NMAX];

void update(int nd, int l, int r, int q_r){

    int q_l = 0;

    if(l > q_r || q_l > r){
        return;
    }

    if(q_l <= l && r <= q_r){
        tree[nd] = 1;
    }

    if(tree[nd]) return;

    int mid = (l+r)/2;
    update(nd*2, l, mid, q_r);
    update(nd*2+1, mid+1, r, q_r);
}

bool query(int nd, int l, int r, int q_r){

    if(tree[nd]) return 1;

    if(l == r){
        return tree[nd];
    }

    int mid = (l+r)/2;

    if(q_r <= mid) return query(nd*2, l, mid, q_r);
    else return query(nd*2+1, mid+1, r, q_r);
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int t; cin >> t; while(t--){

        int n, m, k;
        cin >> n >> m >> k;

        for(int i = 0; i < n; i++) cin >> str[i];

        memset(tree, 0, sizeof tree);

        update(1, 0, n-1, k);

        int ans = 0;

        while(m--){

            char c;
            cin >> c;

            if(c == 'W'){
                int idx;
                cin >> idx;
                idx--;
                int que = query(1, 0, n-1, idx);
                ans += (que == 1) && (str[idx] == 'S');

//                cout << que << ' ' << str[idx] << endl;

                update(1, 0, n-1, idx);
            }
            else{
                update(1, 0, n-1, n-1);
            }
        }

        cout << ans << endl;
    }

}