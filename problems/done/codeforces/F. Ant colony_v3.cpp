// Problem: F. Ant colony
// Contest: Codeforces - Codeforces Round #271 (Div. 2)
// URL: https://codeforces.com/problemset/problem/474/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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

const int NMAX = 1e5 + 10;
const int LOG = ceil(log2(NMAX));

int n;
int arr[NMAX];
int lg2[NMAX];
int st[NMAX][LOG];

void init(){
    
    lg2[1] = 0;
    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i/2] + 1;
}

void build(){
    
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];
    
    for (int j = 1; j < LOG; j++)
    for (int i = 0; i + (1 << j) <= n; i++)
        st[i][j] = __gcd(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    	
	cin >> n;
	for(int i = 0; i < n; i++) 
	    cin >> arr[i];
	
	init();
	build();
    
	vpii vec;
	for(int i = 0; i < n; i++){
	    vec.emplace_back(arr[i], i);
	}
	
	sort(vec.begin(), vec.end());
	
	int q; cin >> q; while(q--){
		
		int l, r;
		cin >> l >> r; l--, r--;
		int j = lg2[r-l+1];
		
        int cgcd = __gcd(st[l][j], st[r-(1 << j) + 1][j]);
		int mn_cnt = upper_bound(vec.begin(), vec.end(), (pii){cgcd, r}) - lower_bound(vec.begin(), vec.end(), (pii){cgcd, l});
		cout << r-l+1 - mn_cnt << endl;
	}
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    