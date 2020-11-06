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

const int MAX = 1e3 + 10;

int n, l;
int  arr[55];
int  mem[MAX][MAX];

int dp(int L, int R){

    if(R == L)
        return 0;

    int & ret = mem[L][R];
    if(ret != -1) return ret;

    ret = 1e6;

    for(int i = 0; i < n; i++) if(L < arr[i] && arr[i] < R){

        ret = min(ret, (R - L) + dp(L, arr[i]) + dp(arr[i], R));

    }

    return ret = (ret == 1e6) ? 0 : ret;
}

int main(){

    while(cin >> l >> n){

        for(int i = 0; i < n; i++)
            cin >> arr[i];

        memset(mem, -1, sizeof mem);

        cout << "The minimum cutting is " << dp(0, l) << ".\n";
    }
}
