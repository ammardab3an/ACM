#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int st[4*N];

void add(int v, int l, int r, int idx, int val){
    if(l == r){
        st[v] = val;
        return;
    }
    int mid = (l+r)/2;
    if(idx <= mid) add(2*v, l, mid, idx, val);
    else add(2*v+1, mid+1, r, idx, val);
    st[v] = max(st[2*v], st[2*v+1]);
}

int get(int v, int l, int r, int tl, int tr){
    if(tl > tr) return 0;
    if(l == tl && r == tr) return st[v];
    int mid = (l+r)/2;
    int f = get(2*v, l, mid, tl, min(tr, mid));
    int s = get(2*v+1, mid+1, r, max(mid+1, tl), tr);
    return max(f, s);
}

int main()
{

    int n;
    scanf("%d", &n);

    vector<int> g(n), l(n), r(n);

    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &g[i], &l[i], &r[i]);
    }

    vector<int> dp(n);
    int ans = 0;
    for(int i = n-1; i>= 0; i--){
        dp[i] = g[i];
        dp[i] += get(1, 0, 2*n+5, i+l[i], i+r[i]);
        add(1, 0, 2*n+5, i, dp[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
