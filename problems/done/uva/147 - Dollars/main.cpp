// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

// Global Variables
const int MAX = 30030;
int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
lli mem[2][MAX];

int main(){

    int p;

    for(int i = 0; i < 2; i++)
        mem[i][0] = 1;

    for(int idx = 0; idx < 11; idx++){

        p = idx % 2;

        for(int coin = coins[0]; coin < MAX; coin += 5){

            if(coin - coins[idx] >= 0)
                mem[p][coin] += mem[p][coin - coins[idx]];

            mem[(p+1)%2][coin] = mem[p][coin];
        }
    }

    for(double num; cin >> num && num;){
        cout << setw(6)  << fixed << setprecision(2) << num
             << setw(17) << mem[p][int(num * 100 + FLT_EPSILON)]
             << endl;
    }
}
