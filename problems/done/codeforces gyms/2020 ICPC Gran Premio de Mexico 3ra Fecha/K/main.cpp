#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

const int NMAX = 1e6 + 10;
const int MOD = 1e9+7;

int add(int x, int y){
    int ret = (1ll*x+y)%MOD;
    return (ret+MOD)%MOD;
}
int mul(int x, int y){
    int ret = (x*1ll*y)%MOD;
    return (ret+MOD)%MOD;
}

int pow_exp(int n, int p){
    if(!p) return 1;
    if(p&1) return mul(n, pow_exp(n, p-1));
    int ret = pow_exp(n, p/2);
    return mul(ret, ret);
}

int fac[NMAX], ifac[NMAX];

void init(){
    fac[0] = 1;
    for(int i = 1; i < NMAX; i++){
        fac[i] = mul(fac[i-1], i);
    }
    ifac[NMAX-1] = pow_exp(fac[NMAX-1], MOD-2);
    for(int i = NMAX-2; i >= 0; i--){
        ifac[i] = mul(ifac[i+1], i+1);
    }
}

int choose(int n, int c){
    if(c > n || c < 0) return 0;
    return mul(mul(fac[n], ifac[c]), ifac[n-c]);
}

signed main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    init();

    int t; cin >> t; while(t--){

        int A, B, C, K, c;
        cin >> A >> B >> C >> K >> c;

        int K1 = K-c;

        if(K1 < 2){
            cout << 0 << endl;
            continue;
        }

        int c0 = choose(C, c);
        int a0 = choose(A+B, K1);
        int a1 = choose(A, K1);
        int a2 = choose(B, K1);

        int ans = mul(c0, add(a0, mul(-1, add(a1, a2))));
        cout << ans << endl;
    }
}

