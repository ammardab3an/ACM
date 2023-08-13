// Problem: D. To Be Named
// Contest: Codeforces - 2023 ICPC HIAST Collegiate Programming Contest
// URL: https://codeforces.com/gym/104493/problem/D
// Memory Limit: 256 MB
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

int MOD = 1e9 + 7;

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

int32_t main(){
    
    fastIO;
    
    int t; cin >> t; while(t--){

		int n, m, a;
		cin >> n >> m >> a;
		
		::MOD = m;
		
		string str;
		cin >> str;
		
		vi frq(10);
		for(auto c : str) frq[c-'0']++;
		
		vi dp(n+1);
		vi dp_cnt(n+1);
		dp_cnt[0] = 1;
		
		for(int d = 0; d < 10; d++) if(frq[d]) {
			
			vi ndp(n+1);
			vi ndp_cnt(n+1);
			
			int j = 0;
			int cans = 0;
			int cans_cnt = 0;
			int sum = 0;
			
			int val = pow_exp(d, a);
			
			for(int i = 0; i <= n; i++){
				
				cans = add(cans, sum+dp[i]);
				cans_cnt = add(cans_cnt, dp_cnt[i]);
				sum = add(sum, mul(val, dp_cnt[i]));
				
				if(i-j > frq[d]){
					cans = add(cans, mul(-1, add(mul(frq[d]+1, mul(val, dp_cnt[j])), dp[j])));
					cans_cnt = add(cans_cnt, -dp_cnt[j]);
					sum = add(sum, mul(-1, mul(val, dp_cnt[j])));
					j++;
				}
				
				ndp[i] = cans;
				ndp_cnt[i] = cans_cnt;
			}
			
			dp = ndp;
			dp_cnt = ndp_cnt;
		}
		
		for(int i = 1; i <= n; i++){
			dp[i] = add(dp[i], dp[i-1]);
		}
		
		int q;
		cin >> q;
		while(q--){
			int l, r;
			cin >> l >> r;
			cout << add(dp[r], -dp[l-1]) << endl;
		}
    }	
}
