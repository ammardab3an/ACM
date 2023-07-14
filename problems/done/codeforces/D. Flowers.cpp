// Problem: D. Flowers
// Contest: Codeforces - AGM 2022, Final Round, Day 2
// URL: https://codeforces.com/gym/104072/problem/D
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int NMAX = 3e3 + 10;

struct FenwickTree {
	
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int n;
int grid[NMAX][NMAX];
int tmp[4][NMAX][NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	cin >> n;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++){
		cin >> grid[i][j];
	}
	
	for(int i = n-1; i >= 0; i--)
	for(int j = n-1; j >= 0; j--){
		
		if(!grid[i][j]){
			tmp[0][i][j] = 0;
			tmp[1][i][j] = 0;
		}
		else{
			
			tmp[0][i][j] = 1;
			tmp[1][i][j] = 1;
			
			if(i+1<n){
				tmp[0][i][j] += tmp[0][i+1][j];
			}
			
			if(j+1<n){
				tmp[1][i][j] += tmp[1][i][j+1];
			}
		}
		
		tmp[2][i][j] = min(tmp[0][i][j], tmp[1][i][j]);
	}
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++){
		
		if(!grid[i][j]){
			tmp[0][i][j] = 0;
			tmp[1][i][j] = 0;
		}
		else{
			
			tmp[0][i][j] = 1;
			tmp[1][i][j] = 1;
			
			if(i){
				tmp[0][i][j] += tmp[0][i-1][j];
			}
			
			if(j){
				tmp[1][i][j] += tmp[1][i][j-1];
			}
		}
		
		tmp[3][i][j] = min(tmp[0][i][j], tmp[1][i][j]);
	}	
	
	int ans = 0;
	
	for(int d = -(n-1); d <= (n-1); d++){
		
		vector<vi> cur(2);
		
		for(int i = 0; i < n; i++){
			int j = i-d;
			if(0 <= j && j < n){
				cur[0].push_back(tmp[2][i][j]);
				cur[1].push_back(tmp[3][i][j]);
			}
		}
		
		// for(auto e : cur[0]) cout << e << ' '; cout << endl;
		// for(auto e : cur[1]) cout << e << ' '; cout << endl;
		
		int sz = cur[0].size();
		FenwickTree bit(sz);
		set<pii> st;
		int water_level = 0;
		
		for(int i = 0; i < sz; i++){
			
			water_level++;
			while(!st.empty() && st.begin()->first <= water_level){
				int p = st.begin()->second;
				st.erase(st.begin());
				bit.add(p, -1);
			}
			
			if(!cur[0][i]) continue;
			
			bit.add(i, 1);
			st.insert({cur[0][i]+water_level, i});
			
			int l = max(int(0), i-cur[1][i]+1);
			int r = i;
			ans += bit.sum(l, r);
		}
	}
	
	cout << ans << endl;
}
