
// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define multiCases true
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int MAX = 2e5 + 10;

void solve(){

	int n;
	string str;
	cin >> str >> n;

	vi arr(n);
	for(int & i : arr)
        cin >> i;

    vector<vi> groups;

    while(true){

        vi pos;

        for(int i = 0; i < n; i++)
            if(!arr[i]) pos.push_back(i);

        if(pos.empty())
            break;
        else
            groups.push_back(pos);

        for(int i = 0; i < n; i++){
            if(!arr[i])
                arr[i] = INT_MAX;
            else
                for(int j : pos) arr[i] -= abs(i - j);
        }
    }

    int idx = 'z';
    int chars[200]{};
    for(char c : str) chars[c]++;

    string ans(n, '*');

    for(vi g : groups){
        while(chars[idx] < g.size()) idx--;
        for(int i : g) ans[i] = idx;
        idx--;
    }

    cout << ans << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
