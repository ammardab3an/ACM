// Problem: B. The Great Hero
// Contest: Codeforces - Codeforces Round #700 (Div. 2)
// URL: https://codeforces.com/contest/1480/problem/B
// Memory Limit: 512 MB
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

int n, m;
int A, B;
int a[NMAX];
int b[NMAX];
int c[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> A >> B >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		
		int tot = 0;
		
		for(int i = 0; i < n; i++) c[i] = ((b[i] + A -1)/A) * a[i], tot += c[i];
		
		bool ans = false;
		
		for(int i = 0; i < n; i++){
			
			int ctot = tot - c[i];
			
			if(ctot >= B) continue;
			
			int cb = B - ctot;
			
			int cnt = (b[i] + A - 1)/A;
			
			if(((cnt-1) * a[i] < cb) && (cnt * A >= b[i])){
				ans = true;
				break;
			}
		}
		
		cout << (ans ? "YES" : "NO") << endl;
    }	
}
