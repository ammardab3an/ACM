// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long lli;

// Global Variables

const int MAX = 66;

string str;
lli mem[MAX][MAX];

lli dp(int f, int t){

    lli & ret = mem[f][t];
    if(ret != -1) return ret;

    ret = 1;
    for(int i = f+1; i < t; i++)
        for(int j = i; j < t; j++)
            if(str[i] == str[j])
                ret += 1 + dp(i, j);
    return ret;
}
void solve(){

    cin >> str;
    int sz = str.size();

    memset(mem, -1, sizeof mem);

    lli & ret = mem[0][sz] = 0;

    for(int i = 0; i < sz; i++)
        for(int j = i; j < sz; j++)
            if(str[i] == str[j])
                ret += 1 + dp(i, j);

    cout << ret/2 << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
