// Problem: G. Wael-utiful Array
// Contest: Codeforces - The 2023 Damascus University Collegiate Programming Contest
// URL: https://codeforces.com/gym/104468/problem/G
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// By AmmarDab3an 

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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

const int NMAX = 2e5 + 10;

int n;
int arr[NMAX];
int lst[NMAX];

int32_t main(){
    
    fastIO;
    
	rng = mt19937(0);
	memset(lst, -1, sizeof lst);
	
	vi tmp;
	for(int i = 2; i*i <= 200000; i++){
		tmp.push_back(i*i);
	}
	vi pre = tmp;
	for(int i = 1; i < tmp.size(); i++){
		pre[i] += pre[i-1];
	}	
	
    int t; cin >> t; while(t--){

		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		if(n==0){
			n = 2e5;
			for(int i = 0; i < n; i++){
				arr[i] = rand((int)1, (int)1e5);
			}
		}
		
		vector<vi> nxt(n), val(n);
		
		for(int i = n-1; i >= 0; i--){
			
			for(int x = 2; x*x <= 200000; x++){
				int k = x*x-arr[i];
				if(1 <= k && k <= 100000 && (lst[k] != -1)){
					nxt[i].push_back(lst[k]);
				}
			}
			
			lst[arr[i]] = i;
		}
		
		for(int i = 0; i < n; i++){
			lst[arr[i]] = -1;
		}
		
		for(int i = 0; i < n; i++){
			for(auto j : nxt[i]){
				
				int a = arr[i];
				int b = arr[j];
				
				if(a > b) swap(a, b);
				
				int cval = 0;
				
				int p0 = floor(sqrtl(a+1))-1;
				int p1 = floor(sqrtl(b+1))-1;
				int p2 = floor(sqrtl(a+b))-1;
				
				if(p0){
					cval += pre[p0-1] - p0;
				}
				
				if(p1 > p0){
					cval += a * (p1-p0);
				}
				
				if(p2 > p1){
					cval -= pre[p2-1];
					if(p1) cval += pre[p1-1];
					cval += (a+b) * (p2-p1);
					cval += p2-p1;
				}
				
				val[i].push_back(cval);
			}
		}
		
		vl dp(n);
		for(int i = n-1; i >= 0; i--){
			
			ll cans = 0;
			
			for(int j = 0; j < nxt[i].size(); j++){
				
				int p = nxt[i][j];
				int v = val[i][j];
				
				cans = max(cans, dp[p] + v);
			}
			
			dp[i] = cans;
		}
		
		ll ans = *max_element(dp.begin(), dp.end());
		cout << ans << endl;
    }	
}
