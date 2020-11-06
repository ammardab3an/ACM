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

const int MAX = 5000 + 10;

void solve(){

    int n;
    cin >> n;

    priority_queue< int, vector<int>, greater<int> > que;
    while(n--){
        int num; cin >> num;
        que.push(num);
    }

    int ans = 0;
    while(true){

        ans++;

        vector<int> vec;

        int last = -1;
        while(!que.empty()){

            int tp = que.top(); que.pop();

            if(tp == last) vec.push_back(tp);

            last = tp;
        }

        if(!vec.size()) break;

        for(int i : vec)
            que.push(i);

    }
    cout << ans << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
