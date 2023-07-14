// Problem: G. Swapping Places
// Contest: Codeforces - 2019-2020 ICPC Southwestern European Regional Programming Contest (SWERC 2019-20)
// URL: https://codeforces.com/gym/102501/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

vi pos[202];
bool good[202][202];

int32_t main(){
    
    fastIO;
    
	int s, l, n;
	cin >> s >> l >> n;
	
	vector<string> vec(s);
	for(auto &s : vec) cin >> s;
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < s; i++){
		good[i][i] = true;
	}
	
	for(int i = 0; i < l; i++){
		string str_u, str_v;
		cin >> str_u >> str_v;
		int u = lower_bound(vec.begin(), vec.end(), str_u)-vec.begin();
		int v = lower_bound(vec.begin(), vec.end(), str_v)-vec.begin();
		good[u][v] = good[v][u] = true;
	}
	
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		int u = lower_bound(vec.begin(), vec.end(), str)-vec.begin();
		pos[u].push_back(i);
	}
	
	for(int i = 0; i < s; i++){
		reverse(pos[i].begin(), pos[i].end());
	}
	
	vi ans(n);
	for(auto &p : ans){
		
		for(int i = 0; i < s; i++) if(!pos[i].empty()){
			
			bool bad = false;
			
			for(int j = 0; j < s; j++) if(!good[i][j]) if(!pos[j].empty() && pos[j].back() < pos[i].back()){
				bad = true;
				break;
			}
			
			if(!bad){
				p = i;
				pos[i].pop_back();
				break;
			}
		}		
	}
	
	for(auto e : ans){
		cout << vec[e] << ' ';
	}
}
