// Problem: E. Baby Ehab's X(OR)
// Contest: Codeforces - ECPC 2019 Kickoff
// URL: https://codeforces.com/gym/102881/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define endl '\n'

using namespace std;

const int OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int pi = acos(-1);
const double EPS = 1e-9;

const int NMAX = 3e5 + 10;

int n, q;
int arr[NMAX];
long long tree[NMAX << 2];
int odds[NMAX << 2];
int ones[NMAX << 2];

void build(int nd, int l, int r){

    if(l == r){

        tree[nd] = arr[l];
        odds[nd] = arr[l]%2==1;
        ones[nd] = arr[l]==1;

        return;
    }

    int mid = (l+r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);

    tree[nd] = tree[nd*2] + tree[nd*2+1];
    odds[nd] = odds[nd*2] + odds[nd*2+1];
    ones[nd] = ones[nd*2] + ones[nd*2+1];
}

void update_or(int nd, int l, int r, int q_l, int q_r){

    if(l > q_r || q_l > r) return;

    if(q_l <= l && r <= q_r){

        if(odds[nd] == (r-l+1)){
            return;
        }
    }

    if(l == r){
        arr[l] |= arr[l]-1;
        tree[nd] = arr[l];
        odds[nd] = arr[l]%2==1;
        ones[nd] = arr[l]==1;
        return;
    }

    int mid = (l+r)/2;
    update_or(nd*2, l, mid, q_l, q_r);
    update_or(nd*2+1, mid+1, r, q_l, q_r);

    tree[nd] = tree[nd*2] + tree[nd*2+1];
    odds[nd] = odds[nd*2] + odds[nd*2+1];
    ones[nd] = ones[nd*2] + ones[nd*2+1];
}

void update_and(int nd, int l, int r, int q_l, int q_r){

    if(l > q_r || q_l > r) return;

    if(q_l <= l && r <= q_r){

        if(ones[nd] == (r-l+1)){
            return;
        }
    }

    if(l == r){

        arr[l] ^= arr[l]-1;
        tree[nd] = arr[l];
        odds[nd] = arr[l]%2==1;
        ones[nd] = arr[l]==1;
        return;
    }

    int mid = (l+r)/2;
    update_and(nd*2, l, mid, q_l, q_r);
    update_and(nd*2+1, mid+1, r, q_l, q_r);

    tree[nd] = tree[nd*2] + tree[nd*2+1];
    odds[nd] = odds[nd*2] + odds[nd*2+1];
    ones[nd] = ones[nd*2] + ones[nd*2+1];
}

int32_t main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("orxor.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n-1);

    while(q--){

        int x;
        cin >> x;

        int l, r;
        cin >> l >> r;
        l--, r--;

        if(x == 1){
            update_or(1, 0, n-1, l, r);
        }
        else{
            update_and(1, 0, n-1, l, r);
        }

        cout << tree[1] << endl;
    }
}