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

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= n; i++)
        nxt[i] = i+1;

    while(m--){

        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);

        for(int i = nxt[l-1]; i <= x; i = nxt[i]){
            if(!ans[i]) ans[i] = x;
            nxt[i-1] = x;
        }

        for(int i = nxt[x]; i <= r; i = nxt[i]){
            if(!ans[i]) ans[i] = x;
            nxt[i-1] = r+1;
        }

        ans[x] = 0;
        nxt[x] = r+1;
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
}

