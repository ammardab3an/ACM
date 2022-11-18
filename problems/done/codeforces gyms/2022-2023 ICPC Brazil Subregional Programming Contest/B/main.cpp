#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int add(int x, int y){
    return ((1ll*x+y)%MOD + MOD)%MOD;
}

int mul(int x, int y){
    return ((x*1ll*y)%MOD + MOD)%MOD;
}

int pow_exp(int n, int p){
    if(!p) return 1;
    if(p&1) return mul(n, pow_exp(n, p-1));
    int ret = pow_exp(n, p/2);
    return mul(ret, ret);
}

int l[3], r[3];
int mem[33][2][2][2][2][2][2];

int go(int p, bool low0, bool hi0, bool low1, bool hi1, bool low2, bool hi2){

    if(p==-1){
        return 1;
    }

    int &ret = mem[p][low0][hi0][low1][hi1][low2][hi2];
    if(ret+1) return ret;

    int l0 = low0 ? 0 : ((l[0]>>p)&1);
    int r0 = hi0  ? 1 : ((r[0]>>p)&1);
    int l1 = low1 ? 0 : ((l[1]>>p)&1);
    int r1 = hi1  ? 1 : ((r[1]>>p)&1);
    int l2 = low2 ? 0 : ((l[2]>>p)&1);
    int r2 = hi2  ? 1 : ((r[2]>>p)&1);

    int ans = 0;

    for(int i = l0; i <= r0; i++)
    for(int j = l1; j <= r1; j++)
    for(int k = l2; k <= r2; k++) if((i^j^k) == 0){

        int cans = go(
                      p-1,
                      low0 || (i > l0),
                      hi0  || (i < r0),
                      low1 || (j > l1),
                      hi1  || (j < r1),
                      low2 || (k > l2),
                      hi2  || (k < r2)
                    );

        ans = add(ans, cans);
    }

    return ret = ans;
}

int main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for(int i = 0; i < 3; i++){
        cin >> l[i] >> r[i];
    }

    memset(mem, -1, sizeof mem);

    int cnt = go(31, 0, 0, 0, 0, 0, 0);

    int tot = 1;
    for(int i = 0; i < 3; i++){
        tot = mul(tot, r[i]-l[i]+1);
    }

    int pro_fail = mul(cnt, pow_exp(tot, MOD-2));
    int pro_succ = add(1, mul(-1, pro_fail));

    cout << pro_succ << endl;
}
