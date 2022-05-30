// Problem: E. Bring Balance
// Contest: Codeforces - Codeforces Round #794 (Div. 2)
// URL: https://codeforces.com/contest/1686/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

bool check(string &str){
	
	int sm = 0;
	for(auto c : str){
		sm += c=='(' ? +1 : -1;
		if(sm < 0) return false;
	}	
	return sm==0;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		string str;
		cin >> str;
		
		n = str.size();
		
		if(check(str)){
			cout << 0 << endl;
			continue;
		}
		
		{
			
			int l = n-1;
			int r = 0;
			
			int sm = 0;
			for(int i = 0; i < n; i++){
				sm += str[i]=='(' ? +1 : -1;
				if(sm < 0){
					l = min(l, i);
					r = max(r, i);
				}
			}
			
			int sm_l, sm_r;
			sm_l = sm_r = -1;
			
			sm = 0;
			for(int i = 0, ll=l; i < ll; i++){
				sm += str[i]=='(' ? +1 : -1;
				if(sm > sm_l){
					l = i+1;
					sm_l = sm;
				}
			}
			
			sm = 0;
			for(int i = r+1; i < n; i++){
				sm += str[i]=='(' ? +1 : -1;
				if(sm > sm_r){
					r = i;
					sm_r = sm;
				}
			}
			
			// cout << ' ' << l << ' ' << r << endl;
			
			string str_tmp = str;
			reverse(str.begin()+l, str.begin()+r+1);
			if(check(str)){
				cout << 1 << endl;
				cout << l+1 << ' ' << r+1 << endl;
				continue;
			}
			else{
				str = str_tmp;
			}
		}
		
		vpii ans;
		for(auto cc : {'(', ')'}){
			
			// cout << cc << ' ' << str << endl;
			
			int mx = -1;
			int mx_pos = 0;
			
			int ad = 0;
			multiset<pii> mst;
			
			for(int i = 0; i < n; i++){
				
				char c = str[i];
				int v = c==cc ? 1 : -1;
				ad += v;
				mst.insert({v-ad, i});
				
				int cur_mx = mst.rbegin()->first + ad;
				
				if(cur_mx > mx){
					mx = cur_mx;
					mx_pos = i;
				}
			}
			
			ans.push_back({0, mx_pos});
			reverse(str.begin(), str.begin() + mx_pos + 1);
			reverse(str.begin(), str.end());
		}
		
		// cout << n << ' ' << str << endl;
		
		ans[1].first = n-ans[1].first-1;
		ans[1].second = n-ans[1].second-1;
		swap(ans[1].first, ans[1].second);
		
		assert(check(str));
		
		cout << ans.size() << endl;
		for(auto p : ans){
			cout << p.first+1 << ' ' << p.second+1 << endl;
		}
    }	
}
