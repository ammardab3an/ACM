// Problem: C. Pair Programming
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/contest/1547/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

int mul(int a, int b){
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 500 + 10;

int k, n, m;
int arr[2][NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> k >> n >> m;
		
		for(int i = 0; i < n; i++) cin >> arr[0][i];
		for(int i = 0; i < m; i++) cin >> arr[1][i];
		
		vi vec;
		
		int i = 0;
		int j = 0;
		
		int cnt = k;
		
		bool good = true;
		
		while(i<n && j<m){
			
			if(arr[0][i] == 0){
				vec.push_back(0);
				cnt++;
				i++;
				continue;
			}	
			if(arr[1][j] == 0){
				vec.push_back(0);
				cnt++;
				j++;
				continue;
			}
			
			if(arr[0][i] < arr[1][j]){
				if(arr[0][i] > cnt){
					good = false;
					break;
				}
				else{
					vec.push_back(arr[0][i]);
					i++;
				}
			}
			else{
				if(arr[1][j] > cnt){
					good = false;
					break;
				}
				else{
					vec.push_back(arr[1][j]);
					j++;
				}
			}
		}
		
		if(good){
			
			while(i<n){
				if(arr[0][i] == 0){
					vec.push_back(0);
					cnt++;
					i++;
					continue;
				}
				else if(arr[0][i] > cnt){
					good = false;
					break;
				}
				else{
					vec.push_back(arr[0][i]);
					i++;
				}
			}
			
			while(j<m){
				if(arr[1][j] == 0){
					vec.push_back(0);
					cnt++;
					j++;
					continue;
				}
				else if(arr[1][j] > cnt){
					good = false;
					break;
				}
				else{
					vec.push_back(arr[1][j]);
					j++;
				}
			}
		}
		
		if(!good){
			cout << -1 << endl;
		}
		else{
			for(auto i : vec) cout << i << ' ';
			cout << endl;
		}
    }	
}