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

const int MAX = 3e5 + 10;

lli qArr[MAX];
deque<int> dque;
pii beAns[MAX];
pii afAns[MAX];

void solve(){

    int n, q;
    cin >> n >> q;

    int mx = 0;
    for(int i = 0; i < n; i++){
        int j; cin >> j;
        dque.push_back(j);
        mx = max(mx, j);
    }

    for(int i = 0; i < q; i++)
        cin >> qArr[i];

    int pos = 1;
    for(int i = 1; dque.front() != mx; i++){

        int A = dque.front(); dque.pop_front();
        int B = dque.front(); dque.pop_front();

        dque.push_front(max(A, B));
        dque.push_back(min(A, B));

        beAns[i] = {A, B};
        pos++;
    }

    int A = dque.front(); dque.pop_front();
    for(int i = 0; !dque.empty(); i++){
        int B = dque.front(); dque.pop_front();
        afAns[i] = {A, B};
    }


    for(int i = 0; i < q; i++){

        pii ans;

        if(qArr[i] < pos)
            ans = beAns[qArr[i]];
        else
            ans = afAns[ (qArr[i] - lli(pos)) % lli(n-1) ];

        cout << ans.first << ' ' << ans.second << endl;
    }
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
