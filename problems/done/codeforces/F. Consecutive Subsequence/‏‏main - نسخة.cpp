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

const int MAX = 2e5 + 10;

int n;
int arr[MAX];
int mem[MAX];
int nxt[MAX];

int dp(int pos){

    int & ret = mem[pos];
    if(ret) return ret;

    for(int i = pos+1; i < n; i++)
        if(arr[pos]+1 == arr[i]){
            nxt[pos] = i;
            return ret = 1 + dp(i);
        }

    return ret = 1;
}

void printAns(int pos){
    if(pos == -1) return;
    printf("%d ", pos+1);
    printAns(nxt[pos]);
}

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    memset(nxt, -1, sizeof nxt);

    int ansPos, ansSz = 0;
    for(int i = 0; i < n; i++)
        if(dp(i) > ansSz)
            ansPos = i, ansSz = mem[i];

    printf("%d\n", ansSz);
    printAns(ansPos);
}
