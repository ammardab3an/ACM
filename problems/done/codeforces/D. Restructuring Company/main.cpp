// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

const int nMAX = 2e5 + 10;

int parent[nMAX];
int    nxt[nMAX];

int par(int nd){
    return (parent[nd] == nd) ? nd : parent[nd] = par(parent[parent[nd]]);
}

int main(){

    int n, q;
    scanf("%d%d", &n, &q);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
        nxt[i] = i+1;
    }

    while(q--){

        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);

        switch(type){

            case 1:
                parent[par(y)] = par(x);

            break; case 2:
                while(x < y){
                    parent[par(x)] = par(y);
                    int tmp = nxt[x]; nxt[x] = nxt[y]; x = tmp;
                }

            break; case 3:
                puts(par(x) == par(y) ? "YES" : "NO");
        }
    }
}
