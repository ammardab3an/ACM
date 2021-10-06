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
const int AMAX = 2e4 + 10; // after translating
const int BLOCK = ceil(sqrt(double(NMAX)));

int cans;
int ans[MMAX];
int bit[AMAX];

struct query{
    int lo, hi, idx;
    bool operator < (query other){
        if(lo/BLOCK != other.lo/BLOCK) return lo/BLOCK < other.lo/BLOCK;
        return lo/BLOCK % 2 ? hi > other.hi : hi < other.hi;
    }
} q[MMAX];

int sum(int r){

	int ret = 0;

	int idx = r+1;
	for(; idx > 0; idx -= idx & (-idx))
		ret += bit[idx];

	return ret;
}

int get_sum(int l, int r){
	return sum(r) - sum(l-1);
}

void update(int num, int k, bool dir){
	
	cans += k * (dir ? get_sum(num+1, 2e4) : get_sum(0, num-1));
	
	int idx = num+1;
	for(; idx <= 2e4; idx += idx & (-idx))
		bit[idx] += k;
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
    
    {
	    vector<int> nvec(vec.begin(), vec.end());
	    sort(nvec.begin(), nvec.end());
	    
		map<int, int> mp;
		int cur(-1), lst(-1);
		for(auto i : nvec){
			if(i == lst) continue;
			mp[i] = ++cur;
			lst = i;
		}
		
		for(int &i : vec) i = mp[i];
    }

    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++){
    	cin >> q[i].lo >> q[i].hi;
    	q[i].lo--, q[i].hi--, q[i].idx = i;
    }
    
    sort(q, q+m);
    
    int l = 1, r = 0;
    for(int i = 0; i < m; i++){
    	
    	int cl = q[i].lo;
    	int cr = q[i].hi;
    	int ci = q[i].idx;
    	
    	while(r < cr) update(vec[++r], +1, 1);
    	while(cl < l) update(vec[--l], +1, 0);
    	while(cr < r) update(vec[r--], -1, 1);
    	while(l < cl) update(vec[l++], -1, 0);
    	
    	ans[ci] = cans;
    }
    
    for(int i = 0; i < m; i++) cout << ans[i] << endl;
}
