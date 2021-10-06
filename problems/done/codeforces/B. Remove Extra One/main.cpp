// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 10;
int cnt[MAX];

int main(){

    int n;
    cin >> n;

    int stMax = 0, ndMax = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > stMax) ndMax = stMax, stMax = x, cnt[x] = -1;
        else if(x > ndMax) ndMax = x, cnt[stMax]++;
    }

    int ans = 1;
    for(int i = 1; i <= n; i++)
        if(cnt[i] > cnt[ans])
            ans = i;

    cout << ans;
}
