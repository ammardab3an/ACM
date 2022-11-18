#include <bits/stdc++.h>

using namespace std;

int hh, ww;

int dp[33][33][33];

int solve(int w, int h, int i){
    if(dp[w][h][i] != -1) return dp[w][h][i];
    int res = 0;
    int f = w+i+1;
    int s = max(i+1, h);
    if(f <= ww && s <= hh){
        res = 1+solve(f, s, i+1);
    }
    if(f <= hh && s <= ww){
        res = max(res, 1+solve(s, f, i+1));
    }
    f = h + i + 1;
    s = max(w, i+1);
    if(f <= ww && s <= hh){
        res = max(res, 1+solve(f, s, i+1));
    }
    if(f <= hh && s <= ww){
        res = max(res, 1+solve(s, f, i+1));
    }
    return dp[w][h][i] = res;
}

int main()
{

    int sum = 0;
    for(int i = 0; i < 14; i++) sum += i*i;
    cout << sum << endl;

    cin >> ww >> hh;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0);

    return 0;
}
