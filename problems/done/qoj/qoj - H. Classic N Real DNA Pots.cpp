
// H. Classic: N Real DNA Pots
// https://qoj.ac/contest/1221/problem/6401

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

typedef long double dt;

struct FenwickTreeMax {
    
    int n;
    vector<int> bit;

    FenwickTreeMax(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    int getmax(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};

int32_t main(){
    
    fastIO;
	
	int n, k;
	cin >> n >> k;
	
	vpii vec(n);
	for(auto &[x, y] : vec) cin >> x >> y;

	if(n==0){
		n = 1e5;
		k = 10;
		vec = vpii(n);
		for(auto &[x, y] : vec){
			x = rand(-1000000, 1000000);
			y = rand(-1000000, 1000000);
		}
	}
	
	auto check = [&](dt m){
		
		vector<dt> tmp(n);
		for(int i = 0; i < n; i++){
			auto [x, y] = vec[i];
			tmp[i] = y-m*x;
		}
		
		vi pos(n);
		iota(pos.begin(), pos.end(), 0);
		stable_sort(pos.begin(), pos.end(), [&](int i, int j){
			return tmp[i] < tmp[j];
		});
		
		vi npos(n);
		for(int i = 0; i < n; i++){
			npos[pos[i]] = i;
		}
		
		FenwickTreeMax bit(n);
		
		for(int i = 0; i < n; i++){
			int v = npos[i];
			int cans = bit.getmax(v) + 1;
			bit.update(v, cans);
		}
		
		return bit.getmax(n-1);
	};
	
	dt l = -1e9;
	dt r = +1e9;
	
	dt ans = -123;
	
	int cnt = 75;
	while(cnt--){
		
		dt mid = l + (r-l)/2;
		
		if(check(mid) >= k){
			ans = mid;
			l = mid;
		}
		else{
			r = mid;
		}
	}
	
	cout << fixed << setprecision(10) << ans << endl;
}
