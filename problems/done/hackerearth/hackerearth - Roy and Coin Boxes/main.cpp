// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> vec(n+1, 0);

    while(m--){
        int l, r; cin >> l >> r;
        vec[ l ]++;
        vec[r+1]--;
    }

    for(int i = 1; i <= n; i++)
        vec[i] += vec[i-1];

    sort(vec.begin(), vec.end());

    int q; cin >> q; while(q--){
        int x; cin >> x;
        int ans = vec.end() - lower_bound(vec.begin(), vec.end(), x);
        cout << ans << endl;
    }
}

