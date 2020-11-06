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

int n;
lli arr[MAX];
lli seg[MAX << 2];

void build(int nd, int l, int r){

    if(l == r){
        seg[nd] = arr[l];
        return;
    }

    int mid = (l + r)/2;
    build(nd*2, l, mid);
    build(nd*2+1, mid+1, r);

    seg[nd] = seg[nd*2] + seg[nd*2+1];
}

lli query(int nd, int l, int r, int a, int b){

    if(b < l || r < a)
        return 0;

    if(a <= l && r <= b)
        return seg[nd];

    int mid = (l + r)/2;
    lli stPath = query(nd*2, l, mid, a, b);
    lli ndPath = query(nd*2+1, mid+1, r, a, b);

    return stPath + ndPath;
}

void update(int nd, int l, int r, int a, int b){

    if(b < l || r < a)
        return;

    if(seg[nd] == (r-l+1))
        return;

    if(l == r){
        seg[nd] = (lli)sqrt(seg[nd]);
        return;
    }
    int mid = (l + r)/2;
    update(nd*2, l, mid, a, b);
    update(nd*2+1, mid+1, r, a, b);

    seg[nd] = seg[nd*2] + seg[nd*2+1];
}

int main(){

    int T = 1;

	while(scanf("%d", &n) != EOF){

        printf("Case #%d:\n", T++);

        for(int i = 1; i <= n; i++)
            scanf("%lld", &arr[i]);

        build(1, 1, n);

        int q; scanf("%d", &q); while(q--){

            int fn, a, b;
            scanf("%d%d%d", &fn, &a, &b);

            if(a > b) swap(a, b);

            if(fn)
                printf("%lld\n", query(1, 1, n, a, b));

            else
                update(1, 1, n, a, b);

        }

        printf("\n");
	}
}
