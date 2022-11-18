#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

signed main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t; while(t--){

        int n, m;
        cin >> n >> m;

        int mx_r=0, mx_w=0;
        for(int i = 0; i < m; i++){
            int r, w;
            cin >> r >> w;
            mx_r = max(mx_r, r);
            mx_w = max(mx_w, w);
        }

        if(mx_r+mx_w > n){
            cout << "IMPOSSIBLE" << endl;
        }
        else{
            cout << string(mx_r, 'R')+string(n-mx_r, 'W') << endl;
        }
    }
}
