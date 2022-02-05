
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
char grid[1010][1010];
int mem[1010][1010];
bool vist[1010][1010];
pii mvArr[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < n;
}

int go(int i, int j){
	
	if(i == n-1 && j == n-1) return 1;
	
	int & ret = mem[i][j];
	if(~ret) return ret;

	lli ans = 0;

	if(j+1 < n) if(grid[i][j+1] == '.') ans += go(i, j+1);
	if(i+1 < n) if(grid[i+1][j] == '.') ans += go(i+1, j);

	return ret = ans % ((1 << 31)  -1);
}

bool check(){
	
	queue<pii> que;
	que.push({0, 0});
	vist[0][0] = 1;

	while(!que.empty()){
	
		auto fr = que.front(); que.pop();
		int ci = fr.first;
		int cj = fr.second;

		if(ci == n-1 && cj == n-1) return 1;

		for(auto p : mvArr){
			int ni = ci + p.first;
			int nj = cj + p.second;
			if(in(ni, nj) && !vist[ni][nj] && grid[ni][nj] == '.'){
				vist[ni][nj] = 1;
				que.push({ni, nj});
			}
		}
	}

	return 0;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n;
    for(int i = 0; i < n; i++) cin >> grid[i];

    memset(mem, -1, sizeof mem);

    int ans = go(0, 0);

    if(ans){
		cout << ans << endl;
	}
	else if(check()){
		cout << "THE GAME IS A LIE" << endl;
	}
	else{
		cout << "INCONCEIVABLE" << endl;
	}

}
