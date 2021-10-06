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

const int MAX = 1e3 + 10;

vector<int> vec;
int mem[MAX][MAX];

int best(int i, int j){

    if(j-i+1  < 3)
        return 0;
    if(j-i+1 == 3)
        return vec[i] * vec[j];

    int & ret = mem[i][j];
    if(ret != -1) return ret;

    ret = 0;

    for(int k = i+1; k < j; k++){

        ret = max(ret, best(i, k) + best(k, j) + (vec[i] * vec[j]));
    }

    return ret;
}

void solve(){

    cout << best(0, vec.size() -1);
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
        memset(mem, -1, sizeof mem);
		solve();
	}
}
