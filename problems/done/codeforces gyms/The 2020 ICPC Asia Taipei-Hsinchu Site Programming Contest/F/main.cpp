#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 10010;

#define int ll

struct edge {

    int a, b, c;
    bool active = 0;
    bool active1 = 0;

};

vector<int> v[N];

int dsu[N], sz[N];

int fnd(int x){
    if(dsu[x] == x) return x;
    return dsu[x] = fnd(dsu[x]);
}

void add(int x, int y){
    x = fnd(x);
    y = fnd(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    dsu[x] = y;
    sz[y] += sz[x];
}

int32_t main(){

    int n, m;
    scanf("%lld%lld", &n, &m);

    vector<edge> e;
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        e.push_back({a, b, c});
    }

    sort(e.begin(), e.end(), [&](edge a, edge b){
            return a.c > b.c;
         } );

    iota(dsu, dsu + N, 0);
    for(int i = 0; i < N; i++) sz[i] = 1;

    for(int i = 0; i < m; i++){
        int from = e[i].a, to = e[i].b;
        from = fnd(from);
        to = fnd(to);
        e[i].active = 1;
        add(to, from);
        from = fnd(from);
        if(sz[from] == n) break;
    }

    sort(e.begin(), e.end(), [&](edge a, edge b){
            return a.c < b.c;
         } );

    iota(dsu, dsu + N, 0);
    for(int i = 0; i < N; i++) sz[i] = 1;

    int test = 0;
    for(int i = 0; i < m; i++){
        if(!e[i].active) continue;
        int from = e[i].a, to = e[i].b;
        from = fnd(from);
        to = fnd(to);
        if(from != to){
            test++;
            e[i].active1 = 1;
            add(from, to);
        }
    }

    assert(test == n-1);

    sort(e.begin(), e.end(), [&](edge a, edge b){
            return a.c > b.c;
         } );

    iota(dsu, dsu + N, 0);
    for(int i = 0; i < N; i++) sz[i] = 1;

    int total = 0;
    int ans = 0;

    for(int i = 0; i < m; i++){
        if(!e[i].active1) continue;
        int from = e[i].a, to = e[i].b;
//        cout << "from " << from << " and " << to << " and " << e[i].c << endl;
        from = fnd(from);
        to = fnd(to);
        if(from != to){
            int sz1 = sz[from];
            int sz2 = sz[to];
//            cout << "sz1 " << sz1 << " and " << sz2 << endl;
            total += sz1*sz2;
            ans += sz1*sz2*e[i].c;

            add(from , to);

        } else assert(false);
    }

//    assert(total == n*(n-1)/2);

//    cout << total << endl;
    cout << ans << endl;

}

/*
1 4 12
1 3 10
4 5 2
2 4 8
1 2 6
3 4 4
2 5 3

*/
