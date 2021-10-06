// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

// Global Variables
const int MAX = 30030;
int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
lli mem[MAX];

int main(){

    mem[0] = 1;

    for(int idx = 0; idx < 11; idx++)
        for(int coin = coins[idx]; coin < MAX; coin += 5)
            mem[coin] += mem[coin - coins[idx]];

    for(double num; cin >> num && num;){
        cout << setw(6)  << fixed << setprecision(2) << num
             << setw(17) << mem[int(num * 100 + FLT_EPSILON)]
             << endl;
    }
}
