
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

#define endl '\n'
#define multiCases false
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int MAX = 1e6 + 10;

int sum[MAX];

int main(){

    string str; int n;

    for(int t = 1; cin >> str >> n; t++){

        int s = str.size();

        sum[0] = str[0] == '1';
        for(int i = 1; i < s; i++){
            sum[i] = sum[i-1] + (str[i] == '1');
        }

        cout << "Case " << t << ":" << endl;

        while(n--){
            int i, j;
            cin >> i >> j;

            if(i > j) swap(i, j);

            int sm = sum[j];
            if(i > 0) sm -= sum[i-1];

            cout << (!sm || (sm == (j-i+1)) ? "Yes" : "No") << endl;

        }
    }
}
