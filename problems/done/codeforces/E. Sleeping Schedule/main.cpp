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

const int nMAX = 2020;
int n, h, l, r;
int arr[nMAX];
int mem[nMAX][nMAX];

int dfs(int pos, int time){

    int & ans = mem[pos][time];
    if(ans != -1) return ans;

    if(pos == n) return ans = 0;

    int nxt;

    nxt = (time + arr[pos]) % h;
    int stPath = (l <= nxt && nxt <= r) + dfs(pos+1, nxt);

    nxt = (time + arr[pos] - 1) % h;
    int ndPath = (l <= nxt && nxt <= r) + dfs(pos+1, nxt);

    return ans = max(stPath, ndPath);
}

void solve(){
    cin >> n >> h >> l >> r;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    memset(mem, -1, sizeof mem);
    cout << dfs(0, 0);
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
