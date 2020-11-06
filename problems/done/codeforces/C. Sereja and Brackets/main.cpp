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

string str;

struct node{
    int mx, lt, rt;
    node(){
        mx = lt = rt = 0;
    }
};

node seg[MAX << 2];

void build(int nd, int l, int r){

    if(l == r){

        if(str[l] == '(')
            seg[nd].rt = 1;
        else
            seg[nd].lt = 1;

        return;
    }

    int mid = (l + r) /2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);

    int tmp = min(seg[nd*2].rt, seg[nd*2+1].lt);

    seg[nd].mx = seg[nd*2].mx + seg[nd*2+1].mx + tmp;
    seg[nd].rt = seg[nd*2].rt + seg[nd*2+1].rt - tmp;
    seg[nd].lt = seg[nd*2].lt + seg[nd*2+1].lt - tmp;
}

node query (int nd, int l, int r, int a, int b){

    if(b < l || r < a)
        return node();

    if(a <= l && r <= b)
        return seg[nd];

    int mid = (l + r)/2;
    node stPath = query(nd*2, l, mid, a, b);
    node ndPath = query(nd*2+1, mid+1, r, a, b);

    int tmp = min(stPath.rt, ndPath.lt);

    node ret = node();
    ret.mx = stPath.mx + ndPath.mx + tmp;
    ret.rt = stPath.rt + ndPath.rt - tmp;
    ret.lt = stPath.lt + ndPath.lt - tmp;

    return ret;
}

int main(){

    cin >> str;
    str = " " + str;
    int n = str.size();

    build(1, 1, n);

    int q; cin >> q; while(q--){

        int a, b;
        cin >> a >> b;

        cout << 2 * query(1, 1, n, a, b).mx << endl;
    }
}

