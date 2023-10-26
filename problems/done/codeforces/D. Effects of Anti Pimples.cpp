// Problem: D. Effects of Anti Pimples
// Contest: Codeforces - Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
// URL: https://codeforces.com/contest/1877/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

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
const int MOD = 998244353; // 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int NMAX = 1e5 + 10;

vi factors[NMAX];
bool used[NMAX];

void init(){
	for(int i = 1; i < NMAX; i++)
	for(int j = i; j < NMAX; j+=i){
		factors[j].push_back(i);
	}
}

int32_t main(){
    
    fastIO;
	init();
    
    int n;
	cin >> n;
	
	vi vec(n);
	for(int i = 0; i < n; i++){
		cin >> vec[i];
	}
	
	map<int, vi> mp;
	for(int i = 0; i < n; i++){
		mp[vec[i]].push_back(i);
	}
	
	int ans = 0;
	int cnt_used = 0;
	
	for(auto it = mp.rbegin(); it != mp.rend(); it++){
		
		auto &[v, pos] = *it;
		
		vi cur;
		
		for(auto p : pos){
			for(auto f : factors[p+1]){
				if(!used[f]){
					used[f] = true;
					cur.push_back(f);
				}
			}
		}
		
		// cout << v << ' ' << n << ' ' << cnt_used << ' ' << cur.size() << endl << flush;
		
		int p0 = pow_exp(2, (int)cur.size());
		int p1 = pow_exp(2, n - cnt_used - (int)cur.size());
		int p = mul(p0-1, p1);
		int cans = mul(v, p);
		ans = add(ans, cans);
		
		cnt_used += cur.size();
	}
	
	cout << ans << endl;
}
