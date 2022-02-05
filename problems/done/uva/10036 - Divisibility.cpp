// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

// Global Variables

int n, k;
int arr[10010];
int mem[10010][100];

inline int fix(int i){
    return (i % k + k) % k;
}

bool dp(int pos, int mod){

    if(pos == n) return !mod;

    int & ret = mem[pos][mod];

    if(ret != -1)
        return ret;
    else
        return ret = dp(pos+1, fix(mod + arr[pos])) || dp(pos+1, fix(mod - arr[pos]));
}

void solve(){

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << (dp(0, 0) ? "Divisible" : "Not divisible") << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
        memset(mem, -1, sizeof mem);
		solve();
	}
}
