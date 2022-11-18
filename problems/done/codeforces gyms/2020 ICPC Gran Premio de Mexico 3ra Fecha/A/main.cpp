#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

int n, m;
int arr_e[11];
int arr_d[105], arr_s[105];
int mem[105][1<<10];
int mem1[11][101][101][101];

int calc(int i, int l, int r, int rm){

    if(l > r || !rm){
        return 0;
    }

    int &ret = mem1[i][l][r][rm];
    if(ret+1) return ret;

    int ans = calc(i, l+1, r, rm);

    if(rm >= arr_d[l]){
        int cans = arr_s[l] + calc(i, l+1, r, rm-arr_d[l]);
        ans = max(ans, cans);
    }

    return ret = ans;
}

int go(int i, int msk){

    if(i==m){
        return 0;
    }

    int &ret = mem[i][msk];
    if(ret+1) return ret;

    int ans = go(i+1, msk);

    for(int j = 0; j < n; j++) if((msk>>j)&1){

        for(int k = i; k < m; k++){
            int cans = calc(j, i, k, arr_e[j]) + go(k+1, msk^(1<<j));
            ans = max(ans, cans);
        }
    }

    return ret = ans;
}

signed main(){

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr_e[i];
    for(int i = 0; i < m; i++) cin >> arr_d[i];
    for(int i = 0; i < m; i++) cin >> arr_s[i];

    memset(mem, -1, sizeof mem);
    memset(mem1, -1, sizeof mem1);

    int ans = go(0, (1<<n)-1);
    cout << ans << endl;
}
