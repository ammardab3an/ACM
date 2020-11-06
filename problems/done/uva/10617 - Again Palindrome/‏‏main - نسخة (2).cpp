// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long lli;

// Global Variables

const int MAX = 66;

string str;
lli mem[MAX][MAX];

void solve(){

    cin >> str;
    int sz = str.size();

    memset(mem, 0, sizeof mem);

    for(int len = 1; len <= sz; len++){

        for(int i = 0; (i+len-1) < sz; i++){

            int j = (i+len-1);

            if(i == j)
                mem[i][j] = 2;

            else if(i+1 == j)
                mem[i][j] = 3 + (str[i] == str[j]);

            else if(str[i] == str[j])
                mem[i][j] = mem[i+1][j] + mem[i][j-1];

            else
                mem[i][j] = mem[i+1][j] + mem[i][j-1] - mem[i+1][j-1];

//                mem[i][j] = mem[i+1][j] + mem[i][j-1] - ((i+1 <= j-1) ? mem[i+1][j-1] : 1);
        }
    }
    cout << mem[0][sz-1] -1 << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
