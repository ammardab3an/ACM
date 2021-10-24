// By AmmarDab3an - Aleppo university

#include<bits/stdc++.h>

using namespace std;

typedef long long lli;

lli p[10010];
vector< pair<lli, pair<lli, lli> > > edge;


lli par(lli i){
    return p[i] = (i == p[i]) ? i : par(p[i]);
}

int main(){

    int t; cin >> t; while(t--){

        lli price, n, m;
        cin >> price >> n >> m;

        edge.clear();

        while(m--){
            lli a, b, c;
            cin >> a >> b >> c;
            edge.push_back({c, {a, b}});
        }

        sort(edge.begin(), edge.end());

        for(lli i = 1; i <= n; i++)
            p[i] = i;

        lli ans = 0;

        for(lli i = 0, cnt = 0; cnt != n-1; i++){

            auto Pair = edge[i];
            lli a = par(Pair.second.first);
            lli b = par(Pair.second.second);

            if(a != b){
                p[a] = b;
                ans += Pair.first;
                cnt++;
            }
        }
        cout << ans * price;
    }
}
