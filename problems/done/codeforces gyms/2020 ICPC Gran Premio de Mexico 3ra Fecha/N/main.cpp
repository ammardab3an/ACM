#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

const int INFLL = 0x3f3f3f3f3f3f3f3f;

int d, b, m;
int arr[101];
int frq[5050];
int pre_dis[5050];
int mem[5050][201];
int mx;

int calc_frq(int l, int r){
    int ret = frq[r];
    if(l) ret -= frq[l-1];
    return ret;
}

int calc_dist(int l, int r){
    int ret = pre_dis[r];
    if(l) ret -= pre_dis[l-1];
    return calc_frq(l, r) * r - ret;
}

int go(int i, int rm){

    if(rm < 0){
        return INFLL;
    }

    if(i==d+1){
        return rm ? INFLL : 0;
    }

    int &ret = mem[i][100+rm];
    if(ret+1) return ret;

    int ans = INFLL;

    for(int j = i+1; (j <= d) && (j-i <= mx); j++){
        int cans = (rm*(j-i)+calc_dist(j, i)) + go(j+1, rm+calc_frq(j, i)-1);
        ans = min(ans, cans);
    }

    return ret = ans;
}

signed main(){

    cin >> d >> b >> m;
    for(int i = 0; i < m; i++){
        cin >> arr[i];
        frq[arr[i]]++;
    }

    for(int i = 1; i <= d; i++){
        pre_dis[i] = pre_dis[i-1] + frq[i]*i;
        frq[i] += frq[i-1];
    }

    for(int i = 0; i <= d; i++) cout << frq[i] << ' '; cout << endl;
    for(int i = 0; i <= d; i++) cout << pre_dis[i] << ' '; cout << endl;

    int l = 0;
    int r = d;

    int ans = 1e9;

    while(l <= r){

        int mid = (l+r)/2;

        ::mx = mid;
        memset(mem, -1, sizeof mem);
        int que = go(0, 0);

        cout << mid << ' ' << que << endl;

        if(que <= b){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    cout << ans << endl;
}
