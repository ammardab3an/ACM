// Problem: C. Ball in Berland
// Contest: Codeforces - Codeforces Round #697 (Div. 3)
// URL: https://codeforces.com/contest/1475/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

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
const int BLOCK = ceil(sqrt(double(NMAX)));

int a, b, k;
pii pi[NMAX];
int cnt[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> a >> b >> k;
		for(int i = 0; i < k; i++) cin >> pi[i].first;
		for(int i = 0; i < k; i++) cin >> pi[i].second;
		
		sort(pi, pi+k);
		
		int tcnt = k;
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i < k; i++) cnt[pi[i].second]++;
		
		int cans = 0;
		
		int r = 0;
		
		for(int i = 0; i < k; i++){
			
			int f = pi[i].first;
			int x = pi[i].second;
			
			while(r < k && pi[r].first == f){
				tcnt--;
				cnt[pi[r++].second]--;
			}
			
			cans += tcnt - cnt[x];
		}
		
		cout << cans << endl;
    }	
}
