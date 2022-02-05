// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

// Global Variables

int mem[1 << 12];

int dp(int msk){

    int & ret = mem[msk];
    if(ret != -1) return ret;

    ret = __builtin_popcount(msk);

    for(int i = 1; i < 12; i++){

        if((msk & (1 << i-1)) && (msk & (1 << i))){

            if(i-2 >= 0 && !(msk & (1 << i-2)))

                ret = min(ret, dp(msk ^ (1 << i-2) ^ (1 << i-1) ^ (1 << i)));

            if(i+1 < 12 && !(msk & (1 << i+1)))

                ret = min(ret, dp(msk ^ (1 << i-1) ^ (1 << i) ^ (1 << i+1)));
        }
    }

    return ret;
}

void solve(){

    string inputStr;
    cin >> inputStr;

    int board = 0;
    for(int i = 0; i < 12; i++)
        board ^= (inputStr[i] == 'o') << i;

    memset(mem, -1, sizeof mem);

    cout << dp(board) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
