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

int qArr[MAX];

void solve(){

    int n, q;
    cin >> n >> q;

    deque<int> dque;
    while(n--){
        int i; cin >> i;
        dque.push_back(i);
    }

    int mx = 0;
    map<lli, pii> ansMp;
    for(int i = 0; i < q; i++){
        cin >> qArr[i];
        mx = max(mx, qArr[i]);
        ansMp[qArr[i]] = {0, 0};
    }

    for(lli i = 1; i <= mx; i++){

        int A = dque.front(); dque.pop_front();
        int B = dque.front(); dque.pop_front();

        if(ansMp.find(i) != ansMp.end())
            ansMp[i] = {A, B};

        dque.push_front(max(A, B));
        dque.push_back(min(A, B));
    }

    for(int i = 0; i < q; i++){
        pii Ans = ansMp[qArr[i]];
        cout << Ans.first << ' ' << Ans.second << endl;
    }
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
