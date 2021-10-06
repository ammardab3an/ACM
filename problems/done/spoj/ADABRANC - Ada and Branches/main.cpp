// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

const int nMAX = 1e5 + 10;
const int qMAX = 3e5 + 10;

struct query{

    int type;
    int id;
    int a, b, w;

    query(int _type, int _id, int _a, int _b, int _w):
    type(_type), id(_id), a(_a), b(_b), w(_w) {
    }

    bool operator < (const query other) const{
        if(w != other.w)
            return w > other.w;
        else
            return type < other.type;
    }
};

int parent[nMAX];
int compSz[nMAX];
int output[qMAX];

vector<query> queries;

int par(int nd){
    return (parent[nd] == nd) ? nd : parent[nd] = par(parent[nd]);
}

void mrg(int a, int b){

    int parA = par(a);
    int parB = par(b);

    if(parA == parB)
        return;

    parent[parB] = parA;
    compSz[parA] += compSz[parB];
    compSz[parB] = 0;
}

int main(){

    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++){
        parent[i] = i;
        compSz[i] = 1;
    }

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        queries.push_back(query(0, -1, a, b, w));
    }

    for(int i = 0; i < q; i++){
        int a, w;
        cin >> a >> w;
        queries.push_back(query(1, i, a, -1, w));
    }

    sort(queries.begin(), queries.end());

    for(query q : queries){

        if(q.type == 0)
            mrg(q.a, q.b);
        else
            output[q.id] = compSz[par(q.a)];
    }

    for(int i = 0; i < q; i++)
        cout << output[i] << endl;
}
