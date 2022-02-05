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

#define multiCases true
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int MAX = 2e5 + 10;

int main(){

    fastIO; //freopenI; freopenO;

    int t;
    cin >> t;

    string str;
    getline(cin, str);
    getline(cin, str);

    while(t--){

		int cnt = 0;
        map<string, int> mp;

        while(getline(cin, str) && !str.empty()){
            mp[str]++;
            cnt++;
        }

        for(auto p : mp)
            cout << p.first << ' ' << fixed << setprecision(4) << 100.0*p.second/cnt << endl;

        if(t) cout << endl;
    }
}
