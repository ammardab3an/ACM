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

int n;
bool vis[MAX];
int p[MAX], a[MAX], b[MAX];

void solve(){

    cin >> n;

    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    priority_queue< pii, vector<pii>, greater<pii> > que[4];

    for(int i = 0; i < n; i++){
        que[a[i]].push({p[i], i});
        que[b[i]].push({p[i], i});
    }

    memset(vis, false, sizeof vis);

    int q; cin >> q; while(q--){

        int Q; cin >> Q;

        try_again:;

        if(que[Q].empty()){
            cout << -1 << ' ';
            continue;
        }

        if(vis[que[Q].top().second]++){
            que[Q].pop();
            goto try_again;
        }
        else{
            cout << que[Q].top().first << ' ';
            que[Q].pop();
        }
    }
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
