#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

typedef long double dt;

const int NMAX = 1010;

int n, q;
int par[NMAX];
dt val[NMAX];
int sz[NMAX];
map<string, int> mp_si;
map<int, string> mp_is;

pair<int, dt> get_par(int u){
    if(par[u]==u) return {u, val[u]};
    auto nxt = get_par(par[u]);
    return {nxt.first, val[u]*nxt.second};
}

bool merge(int u, int v, dt w){

    auto par_u = get_par(u);
    auto par_v = get_par(v);

    u = par_u.first;
    v = par_v.first;

    if(u==v){
        return false;
    }

    if(sz[u] < sz[v]){
        swap(u, v);
        w = dt(1)/w;
    }

    assert(val[v]==1);

    par[v] = u;
    val[v] = par_u.second/w/par_v.second;
    sz[u] += sz[v];

    return true;
}

dt query(int u, int v, dt x){

    auto par_u = get_par(u);
    auto par_v = get_par(v);

    if(par_u.first != par_v.first){
        return -1;
    }

    dt ret = x * (par_u.second) * (dt(1)/par_v.second);
    return ret;
}

signed main(){

    cin >> n >> q;

    int id = 1;

    iota(par, par+(2*n+10), 0);
    for(int i = 0; i < (2*n+10); i++) sz[i] = 0, val[i] = 1;

    for(int i = 0; i < n; i++){

        dt a, b;
        string sa, sb;
        cin >> a >> sa >> sb >> b >> sb;

        int ai, bi;

        {
            ai = mp_si[sa];
            if(!ai){
                ai = id;
                mp_si[sa] = id;
                mp_is[id] = sa;
                id++;
            }
        }
        {
            bi = mp_si[sb];
            if(!bi){
                bi = id;
                mp_si[sb] = id;
                mp_is[id] = sb;
                id++;
            }
        }

        merge(ai, bi, b);
    }

    while(q--){

        dt x;
        string sa, sb;
        cin >> x >> sa >> sb >> sb;

        int ai = mp_si[sa];
        int bi = mp_si[sb];

        dt ans = query(ai, bi, x);

        if(ans==-1){
            cout << "impossible" << endl;
        }
        else{
            cout << setprecision(20) << ans << endl;
        }
    }
}
