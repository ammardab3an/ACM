// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long lli;

// Global Variables

const int MAX = 66;

string str;
lli mem[MAX][MAX];

lli best(int i, int j){

    if(i >  j) return 0;
    if(i == j) return 1;

    lli & ret = mem[i][j];
    if(ret != -1) return ret;

    ret = 0;
    if(str[i] == str[j])
        ret += best(i+1, j-1) +1;

    ret += best(i+1, j);
    ret += best(i, j-1);
    ret -= best(i+1, j-1);

    return ret;
}

void solve(){
    cin >> str;
    memset(mem, -1, sizeof mem);
    cout << best(0, str.size()-1) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
