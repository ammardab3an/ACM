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

const int MAX = 1e5 + 10;

vpii vec;
int  vecSz;
lli  mem[MAX];

lli dp(int pos){

    if(pos >= vecSz)
        return 0;

    lli & ret = mem[pos];
    if(ret != -1) return ret;

    lli stPath = dp(pos+1);
    lli ndPath = (lli)vec[pos].first * vec[pos].second + dp(vec[pos+1].first != vec[pos].first+1 ? pos+1 : pos+2);

    return ret = max(stPath, ndPath);
}

void solve(){

    int n;
    cin >> n;

    map<int, int> mp;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }

    vec = vpii(mp.begin(), mp.end());
    vec.push_back({1e6, 0});
    vecSz = vec.size();

    memset(mem, -1, sizeof mem);
    cout << dp(0);
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
