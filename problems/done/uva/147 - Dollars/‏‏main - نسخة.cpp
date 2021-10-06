// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

// Global Variables

int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
lli mem[11][30030];

lli dp(int idx, int rem){

    if(rem == 0)
        return 1;

    if(rem < coins[idx] || idx == 11)
        return 0;

    lli & ret = mem[idx][rem];

    if(ret != -1)
        return ret;
    else
        return ret = dp(idx+1, rem) + dp(idx, rem - coins[idx]);
}

int main(){

    memset(mem, -1, sizeof mem);

    for(double num; cin >> num && num;){
        cout << setw(6)  << fixed << setprecision(2) << num
             << setw(17) << dp(0, int(num * 100 + 1e-7)) << endl;
    }
}
