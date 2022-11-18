#include<bits/stdc++.h>

using namespace std;

char buf[220];
string read(){
    scanf("%s", buf);
    return buf;
}

string a ,b;

int delu[202][202];
int calcu(int l, int r){
    if(l > r) return 1;
    if(delu[l][r] != -1) return delu[l][r];
    if(l%2 == r%2) return delu[l][r] = 0;
    if(l+1 == r) return delu[l][r] = (a[l] == a[r]);
    if(l+3 == r && (a.substr(l, 4) == "ABAB" || a.substr(l, 4) == "BCBC")) return delu[l][r] = 1;
    for(int i = l; i < r; i++){
        if(calcu(l, i) && calcu(i+1, r)) return delu[l][r] = 1;
    }
    return delu[l][r] = 0;
}

int delv[202][202];
int calcv(int l, int r){
    if(l > r) return 1;
    if(delv[l][r] != -1) return delv[l][r];
    if(l%2 == r%2) return delv[l][r] = 0;
    if(l+1 == r) return delv[l][r] = (b[l] == b[r]);
    if(l+3 == r && (b.substr(l, 4) == "ABAB" || b.substr(l, 4) == "BCBC")) return delv[l][r] = 1;
    for(int i = l; i < r; i++){
        if(calcv(l, i) && calcv(i+1, r)) return delv[l][r] = 1;
    }
    return delv[l][r] = 0;
}

int dp[220][220];
int solve(int i, int j){

    if(i == a.length() && j == b.length()) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int f = 0;

    if(a[i] == b[j]){
        f = solve(i+1, j+1);
    }

    int s = 0, t = 0;

    for(int l = i; l < a.length(); l++){
        if(delu[i][l] == 1) s = max(s, solve(l+1, j));
    }
    for(int l = j; l < b.length(); l++){
        if(delv[j][l] == 1) t = max(t, solve(i, l+1));
    }

    return dp[i][j] = max({f, s, t});

}

int main()
{

    int t;
    scanf("%d" ,&t);
    while(t--){

        a = read();
        b = read();
        a += "#";
        b += "#";
        int n = a.length();
        int m = b.length();

        memset(delu, -1, sizeof delu);
        memset(delv, -1, sizeof delv);

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                delu[i][j] = calcu(i, j);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = i; j < m; j++){
                delv[i][j] = calcv(i, j);
            }
        }

        memset(dp, -1, sizeof dp);

        int ans = solve(0, 0);
        puts(ans ? "YES" : "NO");
    }

    return 0;
}
