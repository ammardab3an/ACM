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

const int MAX = 2e5 + 10;

void solve(){

    int n;
    cin >> n;

    map<int, vi> mp;

    for(int x, i = 0; i < n; i++){
        cin >> x;
        mp[x].push_back(i);
    }

    vector<pii> ans;

    for(auto p : mp){

        vi & vec = p.second;

        int dif = vec.size() > 1 ? vec[1] - vec[0] : 0;

        bool flag = true;
        for(int i = 2; i < vec.size(); i++){
            if(vec[i] - vec[i-1] != dif){
                flag = false;
                break;
            }
        }

        if(flag) ans.push_back({p.first, dif});
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto p : ans)
      cout << p.first << ' ' << p.second << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
