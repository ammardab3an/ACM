// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

// Global Variables

const int MAX = 1e6 + 10;

int seg[MAX << 2];
int lazy[MAX << 2];
int arr[MAX];
int ans[MAX];

void updateRange(int nd, int L, int R, int left, int right, int val){

    if(right < L || R < left)
        return;

    if(lazy[nd]){
        seg[nd] += (R - L +1) * lazy[nd];
        if(L != R){
            lazy[nd << 1]     += lazy[nd];
            lazy[nd << 1 | 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }

    if(left <= L && R <= right){
        seg[nd] += (R - L +1) * val;
        if(L != R){
            lazy[nd << 1]     += val;
            lazy[nd << 1 | 1] += val;
        }
        return;
    }

    int mid = (L + R) >> 1;
    updateRange(nd << 1, L, mid, left, right, val);
    updateRange(nd << 1 | 1, mid+1, R, left, right, val);

    seg[nd] = seg[nd << 1] + seg[nd << 1 | 1];
}

int queryRange(int nd, int L, int R, int left, int right){

    if(right < L || R < left)
        return 0;

    if(lazy[nd]){
        seg[nd] += (R - L +1) * lazy[nd];
        if(L != R){
            lazy[nd << 1]     += lazy[nd];
            lazy[nd << 1 | 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }

    if(left <= L && R <= right)
        return seg[nd];

    int mid = (L + R) >> 1;
    int leftAns  = queryRange(nd << 1, L, mid, left, right);
    int rightAns = queryRange(nd << 1 | 1, mid+1, R, left, right);

    return leftAns + rightAns;
}
void solve(){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        updateRange(1, 1, n, l, r, 1);
    }

    for(int i = 1; i <= n; i++)
        arr[i] = queryRange(1, 1, n, i, i);

    memset(seg,  0, sizeof seg);
    memset(lazy, 0, sizeof lazy);

    for(int i = 1; i <= n; i++)
        updateRange(1, 1, n, 1, arr[i], 1);

    int q; cin >> q; while(q--){
        int x; cin >> x;
        cout << queryRange(1, 1, n, x, x) << endl;
    }
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
