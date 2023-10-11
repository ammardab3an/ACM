// Problem: C. LuoTianyi and the Show
// Contest: Codeforces - Codeforces Round 872 (Div. 2)
// URL: https://codeforces.com/contest/1825/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n, m;
		cin >> n >> m;
		
		vi vec(n);
		for(int &i : vec) cin >> i;
		
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		
		int cnt_2 = 0;
		int cnt_1 = 0;
		
		while(!vec.empty() && vec.back()==-2){
			cnt_2++;
			vec.pop_back();
		}
		while(!vec.empty() && vec.back()==-1){
			cnt_1++;
			vec.pop_back();
		}
		
		reverse(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		
		cnt_1 = min(cnt_1, m);
		cnt_2 = min(cnt_2, m);
		int st_path = max(cnt_1, cnt_2);
		
		if(vec.empty()){
			cout << st_path << endl;
			continue;	
		}
		
		int nd_path = 0;
		
		vi pre(vec.size());
		for(int i = 0; i < vec.size(); i++){
			if(i==0){
				pre[i] = vec[i]-1;
			}
			else{
				pre[i] = pre[i-1] + vec[i]-vec[i-1]-1;
			}
		}
		
		vi suf(vec.size());
		for(int i = (int)vec.size()-1; i >= 0; i--){
			if(i+1==vec.size()){
				suf[i] = m - vec[i];
			}
			else{
				suf[i] = suf[i+1] + vec[i+1]-vec[i]-1;
			}
		}
		
		for(int i = 0; i < vec.size(); i++){
			
			int cans = vec.size();
			cans += min(cnt_1, pre[i]);
			cans += min(cnt_2, suf[i]);
			
			nd_path = max(nd_path, cans);
		}
		
		int rd_path = min(m, (int)vec.size() + cnt_2);
		int th_path = min(m, (int)vec.size() + cnt_1);
		
		// cout << st_path << ' ' << nd_path << ' ' << rd_path << ' ' << th_path << endl;
		
		cout << max({st_path, nd_path, rd_path, th_path}) << endl;
    }	
}
