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

const int MAX = 3e5 + 10;

int ans[MAX];
int nxt[MAX];

int getNxt(int i){
    return (nxt[i] == i) ? i : nxt[i] =  getNxt(nxt[i]);
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= n+1; i++)
        nxt[i] = i;

    while(m--){

        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);

        for(int i = getNxt(l); i < x; i = getNxt(i+1)){
            ans[i] = nxt[i] = x;
        }
        for(int i = getNxt(x+1); i <= r; i = getNxt(i+1)){
            ans[i] = x;
            nxt[i] = getNxt(r+1);;
        }
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
}
