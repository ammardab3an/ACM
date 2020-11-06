
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef unsigned int		uint;
typedef long long int       lli;
typedef unsigned long long  ull;
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
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int MAX = 5e3 + 10;
const int MAX_VAL = 1e5 + 10;

int n, k;
int h[MAX];
int cntC[MAX_VAL];
int cntF[MAX_VAL];
int mem[MAX][MAX];

int main(){

    fastIO;

	cin >> n >> k;
	for(int ci, i = 0; i < n*k; i++) cin >> ci, cntC[ci]++;
	for(int fi, i = 0; i < n  ; i++) cin >> fi, cntF[fi]++;


	for(int i = 1; i <= k; i++) cin >> h[i];


	for(int i = 0; i < n  ; i++)
	for(int j = 0; j < n*k; j++){

		for(int cur = 0; cur <= k; cur++){
			mem[i+1][j+cur] = max(mem[i+1][j+cur], mem[i][j] + h[cur]);
		}

	}

	int ans = 0;

	for(int i = 0; i < MAX_VAL; i++) if(cntF[i])
		ans += mem[cntF[i]][cntC[i]];

	cout << ans << endl;
}
