#include<bits/stdc++.h>

#define int int64_t

using namespace std;

const int NMAX = 1e5 + 10;
const int MOD = 998244353 ;
const int INFLL = 0x3f3f3f3f3f3f3f3f;

int n, k;
int arr[101][2];
int mem[101][101][2*2605];

int go(int i, int k, int sm){

    if(k < 0){
        return -INFLL;
    }

    if(i==n){
        return sm==0 ? 0 : -INFLL;
    }

    int &ret = mem[i][k][sm+2600];
    if(ret+1) return ret;

    int st_path = arr[i][0] + go(i+1, k, sm+arr[i][1]);
    int nd_path = arr[i][0] + go(i+1, k, sm-arr[i][1]);
    int rd_path = arr[i][0] + go(i+1, k-1, sm+2*arr[i][1]);
    int th_path = arr[i][0] + go(i+1, k-1, sm-2*arr[i][1]);
    int fv_path = go(i+1, k, sm);

    return ret = max({st_path, nd_path, rd_path, th_path, fv_path});
}

signed main(){

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    memset(mem, -1, sizeof mem);

    int ans = go(0, k, 0);
    cout << ans << endl;
}
