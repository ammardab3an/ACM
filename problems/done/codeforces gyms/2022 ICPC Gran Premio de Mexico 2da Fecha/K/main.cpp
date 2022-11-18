#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

const int NMAX = 1e5 + 10;
const int MOD = 1e9+7;

int add(int x, int y){
    int ret = (1ll*x+y)%MOD;
    return (ret+MOD)%MOD;
}

int mul(int x, int y){
    int ret = (x*1ll*y)%MOD;
    return (ret+MOD)%MOD;
}

int n, q;
int arr[NMAX];

struct node{
    int sm;
    int sm2;
    int lazy;
} tree[NMAX << 2];

void push(int nd, int l, int r){

    if(!tree[nd].lazy){
        return;
    }

    tree[nd].sm2 = add(tree[nd].sm2, add(mul(2, mul(tree[nd].sm, tree[nd].lazy)), mul(mul(tree[nd].lazy, tree[nd].lazy), r-l+1)));
    tree[nd].sm = add(tree[nd].sm, mul(tree[nd].lazy, r-l+1));

    if(l != r){
        tree[nd*2].lazy = add(tree[nd*2].lazy, tree[nd].lazy);
        tree[nd*2+1].lazy = add(tree[nd*2+1].lazy, tree[nd].lazy);
    }

    tree[nd].lazy = 0;
    return;
}

node merge(const node &a, const node &b){
    assert(!a.lazy && !b.lazy);
    node ret;
    ret.sm = add(a.sm, b.sm);
    ret.sm2 = add(a.sm2, b.sm2);
    ret.lazy = 0;
    return ret;
}

void build(int nd, int l, int r){

    if(l==r){
        tree[nd] = (node){add(arr[l], 0), mul(arr[l], arr[l]), 0};
        return;
    }

    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);

    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int x){

    push(nd, l, r);

    if(q_r < l || r < q_l){
        return;
    }

    if(q_l <= l && r <= q_r){
        tree[nd].lazy = add(tree[nd].lazy, x);
        push(nd, l, r);
        return;
    }

    int mid = (l+r)/2;
    update(nd*2, l, mid, q_l, q_r, x);
    update(nd*2+1, mid+1, r, q_l, q_r, x);

    tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

int query(int nd, int l, int r, int q_l, int q_r){

    push(nd, l, r);

    if(q_r < l || r < q_l){
        return 0;
    }

    if(q_l <= l && r <= q_r){
        return tree[nd].sm2;
    }

    int mid = (l+r)/2;
    int st_path = query(nd*2, l, mid, q_l, q_r);
    int nd_path = query(nd*2+1, mid+1, r, q_l, q_r);

    return add(st_path, nd_path);
}

signed main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    build(1, 0, n-1);

    while(q--){

        char c;
        cin >> c;

        if(c=='u'){
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            update(1, 0, n-1, l, r, x);
        }
        else{
            int l, r;
            cin >> l >> r;
            l--, r--;
            int ans = query(1, 0, n-1, l, r);
            cout << ans << endl;
        }
    }
}
