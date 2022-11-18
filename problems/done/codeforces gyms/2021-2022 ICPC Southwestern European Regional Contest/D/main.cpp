#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'


signed main(){


    int n, m;
    cin >> n >> m;

    vector<int> val(n);
    for(auto &i : val) cin >> i;

    vector<int> pos(m);
    for(auto &i : pos) cin >> i;

    sort(pos.begin(), pos.end());

    n++;
    val.push_back(0);

    vector<int> pre = val;
    for(int i = 1; i < n; i++){
        pre[i] += pre[i-1];
    }

    vector<int> suf = val;
    for(int i = n-2; i >= 0; i--){
        suf[i] += suf[i+1];
    }


    int ans = 0;

    int l, r;
    l = 0, r = 0;

    for(int i = 0; i < m; i++){

        if(i==0){
            int p = pos[i]/100;
            p = min(p, n-1);
            int cans = pre[p] - (pos[i]%100==0)*val[p];
            ans = max(ans, cans);
        }

        if(i==m-1 && (pos[i] <= (n-1)*100)){
            int p = (pos[i]+100-1)/100;
            int cans = suf[p] - (pos[i]%100==0)*val[p];
            ans = max(ans, cans);
        }

        if(i+1 < m){

            int len = pos[i+1]-pos[i];

            int sm = 0;
            int p = (pos[i]+100-1)/100;
            if(pos[i]%100==0) p++;

            int r = p;
            for(int l = p; l < n && (100*l < pos[i+1]); l++){

                if(p < l){
                    sm -= val[l-1];
                }

                while(r < n && (100*r < pos[i+1]) && (100*r-100*l)*2 < len){
                    sm += val[r];
                    r++;
                }

                ans = max(ans, sm);
            }
        }
    }

    cout << ans << endl;
}
