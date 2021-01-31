// Problem: D. fst_powerful array
// Contest: Codeforces - Yandex.Algorithm 2011: Round 2
// URL: https://codeforces.com/contest/86/problem/D
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// fst_powered by CP Editor (https://cpeditor.org)


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

const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int AMAX = 1e6 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

int n, m, cans;
int arr[NMAX];
int ans[MMAX];
int cnt[AMAX];
int fst_pow[AMAX];

struct query{
	int l, r, idx, b_idx;
	bool operator < (query other){
		if(b_idx != other.b_idx) return l < other.l;
		return b_idx % 2 ? r > other.r : r < other.r;
	}
} q[MMAX];


void add(int idx){
	int a = arr[idx];
	cans -= a * fst_pow[cnt[a]];
	cnt[a]++;
	cans += a * fst_pow[cnt[a]];
}

void rem(int idx){
	int a = arr[idx];
	cans -= a * fst_pow[cnt[a]];
	cnt[a]--;
	cans += a * fst_pow[cnt[a]];
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
	for(int i = 1; i < AMAX; i++) fst_pow[i] = i*i;
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < m; i++){
		cin >> q[i].l >> q[i].r;
		q[i].l--, q[i].r--, q[i].idx = i, q[i].b_idx = q[i].l/BLOCK;
	}
	sort(q, q+m);
	
	int l = 1, r = 0;
	for(int i = 0; i < m; i++){

		int cl = q[i].l;
		int cr = q[i].r;
		int ci = q[i].idx;
		
		while(r < cr) add(++r);
		while(cl < l) add(--l);
		while(cr < r) rem(r--);
		while(l < cl) rem(l++);
		
		ans[ci] = cans;
	}
	
	for(int i = 0; i < m; i++) cout << ans[i] << endl;
}
