// Problem: Kriti and her Birthday Gift
// Contest: HackerEarth - Algorithms - Searching - Binary Search
// URL: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kriti-and-her-birthday-gift/description/
// Memory Limit: 20 MB
// Time Limit: 4000 ms
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int BLOCK = ceil(sqrt(double(NMAX)));

int ans[MMAX];

struct query{
	
	int lo, hi, idx, lo_block;
	string str;
    
    bool operator < (query other){
        if(lo_block != other.lo_block) return lo_block < other.lo_block;
        return lo_block % 2 ? hi > other.hi : hi < other.hi;
    }
    
} q[MMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n;
    cin >> n;
    
    vector<string> vec(n);
    for(auto &s : vec) cin >> s;
    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++){
    	cin >> q[i].lo >> q[i].hi >> q[i].str;
    	q[i].lo--, q[i].hi--, q[i].idx = i, q[i].lo_block = q[i].lo/BLOCK;;
    }
    
    sort(q, q+m);
    
    unordered_map<string, int> mp;
    
    int l = 1, r = 0;
    for(int i = 0; i < m; i++){
    	
    	int cl = q[i].lo;
    	int cr = q[i].hi;
    	int ci = q[i].idx;
    	string cs = q[i].str;
    	
    	while(r < cr) mp[vec[++r]]++;
    	while(cl < l) mp[vec[--l]]++;
    	while(cr < r) mp[vec[r--]]--;
    	while(l < cl) mp[vec[l++]]--;
    	
    	auto it = mp.find(cs);
    	if(it != mp.end()) ans[ci] = it->second;
    }
    
    for(int i = 0; i < m; i++) cout << ans[i] << endl;
}
