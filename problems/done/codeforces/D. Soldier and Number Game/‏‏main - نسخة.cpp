
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

const int MAX = 5e6 + 10;

int fac[MAX];
int mem[MAX];

void solve(){

	int a, b;
	cin >> a >> b;

	int cnt = 0;

    for(int n = a; n > b; n--){

        if(!mem[n]){

            for(int cur = n; cur != 1; cur /= fac[cur]){

                mem[n]++;

                if(!fac[cur]) for(int i = 2; i*i <= cur; i++) if(cur % i == 0){
                    fac[cur] = i;
                    break;
                }

                if(!fac[cur])
                    break;
            }
        }
        cnt += mem[n];
    }

    cout << cnt << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
