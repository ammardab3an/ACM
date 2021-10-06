// Problem: Sherlock and Inversions
// Contest: CodeChef - Practice(Extcontest)
// URL: https://www.codechef.com/problems/IITI15
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e4 + 10;
const int MMAX = 2e4 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

int cans = 0;
int ans[MMAX];

struct node{
	int cnt;
	node * nxt[2];
	node(){
		cnt = 0;
		nxt[0] = nxt[1] = nullptr;
	}
};

struct query{
    int lo, hi, idx;
    bool operator < (query other){
        if(lo/BLOCK != other.lo/BLOCK) return lo/BLOCK < other.lo/BLOCK;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
} q[MMAX];

int get_upper(node &cur, int num, int k, bool b_hi){
	
	if(b_hi) return cur.cnt;
	if(k == -1) return 0;
	
	int ret = 0;
	if(cur.nxt[0] && !(num & (1 << k)))
		ret += get_upper(*cur.nxt[0], num, k-1, 0);
		
	if(cur.nxt[1]) 
		ret += get_upper(*cur.nxt[1], num, k-1, !(num & (1 << k)));
	
	return ret;
}

void update(node &root, int num, int k, bool dir){
	
	if(dir){
		cans += k * get_upper(root, num, 30, 0);
	}
	else{
		cans += k * (root.cnt - get_upper(root, num-1, 30, 0));
	}
	
	node * cur = &root;
	cur->cnt += k;
	
	for(int i = 30; i >= 0; i--){
		
		bool nxtb = num & (1 << i);
		
		if(!cur->nxt[nxtb]) cur->nxt[nxtb] = new node();
		
		cur = cur->nxt[nxtb];
		cur->cnt += k;
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
	
    int n;
    cin >> n;
    
    vector<int> vec(n);
    for(int &i : vec) cin >> i;
    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++){
    	cin >> q[i].lo >> q[i].hi;
    	q[i].lo--, q[i].hi--, q[i].idx = i;
    }
    
    sort(q, q+m);
    
    node root = node();
    
    int l = 1, r = 0;
    for(int i = 0; i < m; i++){
    	
    	int cl = q[i].lo;
    	int cr = q[i].hi;
    	int ci = q[i].idx;
    	
    	while(r < cr) update(root, vec[++r], +1, 1);
    	while(cl < l) update(root, vec[--l], +1, 0);
    	while(cr < r) update(root, vec[r--], -1, 1);
    	while(l < cl) update(root, vec[l++], -1, 0);
    	
    	ans[ci] = cans;
    }
    
    for(int i = 0; i < m; i++) cout << ans[i] << endl;
}
