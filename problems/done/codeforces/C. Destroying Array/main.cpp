// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

using namespace std;

typedef long long lli;

const int nMAX = 1e5 + 10;

int add[nMAX];

int parent[nMAX];
int compSz[nMAX];
lli compVl[nMAX];
bool alive[nMAX];

int par(int nd){
    return (parent[nd] == nd) ? nd : parent[nd] = par(parent[nd]);
}

void mrg(int a, int b){

    int parA = par(a);
    int parB = par(b);

    if(parA == parB)
        return;

    parent[parB]  = parA;
    compVl[parA] += compVl[parB];
    compSz[parA] += compSz[parB];
}

int main(){

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> compVl[i];
    for(int i = 1; i <= n; i++) cin >> add[i];

    for(int i = 1; i <= n; i++){
        compSz[i] = 1;
        parent[i] = i;
    }

    lli mx = 0;
    vector<lli> ans;

    for(int i = n; i > 0; i--){

        int pos = add[i];

        alive[pos] = true;

        if(pos+1 <= n && alive[pos+1]) mrg(pos, pos+1);
        if(pos-1 >= 1 && alive[pos-1]) mrg(pos, pos-1);

        ans.push_back(mx);
        mx = max(mx, compVl[par(pos)]);
    }

    reverse(ans.begin(), ans.end());
    for(auto i : ans)
        cout << i << endl;
}
