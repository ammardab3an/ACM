// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

// Global Variables

int n, m;
pii tree[16];
int group[16][16];
int mem[1 << 16];

void fillGroupArr(){

    for(int i = 0  ; i < n; i++)
    for(int j = i+1; j < n; j++){

        group[i][j] ^= (1 << i) ^ (1 << j);

        int x1 = tree[i].first  - tree[j].first;
        int y1 = tree[i].second - tree[j].second;

        for(int k = 0; k < n; k++) if(k != i && k != j){

            int x2 = tree[i].first  - tree[k].first;
            int y2 = tree[i].second - tree[k].second;

            if(x1 * y2 == x2 * y1)
                group[i][j] ^= 1 << k;
        }
    }
}

int dp(int msk){

    int & ret = mem[msk];
    if(ret != -1) return ret;

    int cnt = __builtin_popcount(msk);
    if(cnt == m) return ret = 0;

    ret = 20;

    for(int i = 0; i < n; i++) if(~msk & (1 << i)){

        for(int j = i+1; j < n; j++) if(~msk & (1 << j)){

            ret = min(ret, 1 + dp(msk | group[i][j]));
        }
    }

    if(ret == 20){
        for(int i = 0; i < n; i++) if(~msk & (1 << i)){
            ret = min(ret, 1 + dp(msk | (1 << i)));
        }
    }

    return ret;
}

void solve(){

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> tree[i].first >> tree[i].second;

    memset(mem,  -1, sizeof mem);
    memset(group, 0, sizeof group);

    fillGroupArr();
    cout << dp(0) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ":\n";
		solve();
        cout << endl;
	}
}
