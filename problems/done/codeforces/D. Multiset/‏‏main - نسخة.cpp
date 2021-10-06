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

const int MAX = 1 << 20;

int n;
int BIT[MAX + 16];

void add(int pos, int val){
    for(int i = pos; i <= MAX; i += i & (-i))
        BIT[i] += val;
}

int bSearch(int x){

    if(x == 0)  return 0;

    int ptr = 0;
    for(int i = MAX/2; i >= 1; i /= 2){
        if(BIT[ptr + i] < x){
            x -= BIT[ptr + i];
            ptr += i;
        }
    }

    return ptr+1;
}

void solve(){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int x; cin >> x; add(x, 1);
    }

    int cnt = n;
    while(m--){

        int x;
        cin >> x;

        if(x > 0){
            add(x, 1); cnt++;
        }
        else{
            int ptr = bSearch(-x);
            add(ptr, -1); cnt--;
        }
    }


    cout << (cnt ? bSearch(1) : 0) << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
