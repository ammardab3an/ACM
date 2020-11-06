
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

//#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

const int MAX = 2e5 + 10;

int main(){

    fastIO;

	int n;
	while(cin >> n){

        if(!n) break;

        vector <int> vec(n);

        for(int i = 0; i < n; i++) cin >> vec[i];

        sort(vec.begin(), vec.end());

        bool b = true;
        for(int i = 1; i < n; i++){
            if(vec[i] - vec[i-1] > 200){
                b = false;
                break;
            }
        }

        if(vec.back() < 1322) b = false;

        cout << (b ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	}
}
