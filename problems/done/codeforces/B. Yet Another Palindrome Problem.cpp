// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

// Global Variables

const int MAX = 5050;
int arr[MAX];
int vis[MAX];

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bool b = false;
    for(int i = 0; i < n; i++){

        if((vis[arr[i]] != -1) && ((i - vis[arr[i]]) > 1))
            b = true;

        if(vis[arr[i]] == -1)
            vis[arr[i]] = i;
        else
            vis[arr[i]] = min(vis[arr[i]], i);
    }

    cout << (b ? "YES" : "NO") << endl;
}

int main(){

	int t = 1; if(true) cin >> t;

	while(t--){
        memset(vis, -1, sizeof vis);
		solve();
	}
}
