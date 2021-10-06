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

int n;
lli arr[110];
bool vis[110];
vector<lli> ans;

bool dfs(int curPos){

    bool b = true;
    vis[curPos] = true;

    for(int i = 0; i < n; i++) if(!vis[i]){
        b = false;
        if(arr[curPos]*2 == arr[i]) if(dfs(i)){
            ans.push_back(arr[curPos]);
            return true;
        }
    }

    if(arr[curPos] % 3 == 0) for(int i = 0; i < n; i++) if(!vis[i]){
        if(arr[curPos]/3 == arr[i]) if(dfs(i)){
            ans.push_back(arr[curPos]);
            return true;
        }
    }

    vis[curPos] = false;
    if(b) ans.push_back(arr[curPos]);
    return b;
}

void solve(){

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
        if(dfs(i))
            break;

    reverse(ans.begin(), ans.end());
    for(lli i : ans)
        cout << i << ' ';
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
