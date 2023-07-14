// Problem: E. Palindrome Partition
// Contest: Codeforces - Codeforces Round 873 (Div. 2)
// URL: https://codeforces.com/contest/1828/problem/E
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		string str;
		cin >> str;
		
		string &s = str;
		vector<int> d2(n);  // maximum even length palindrome centered at i
		  // here d2[i]=the palindrome has d2[i]-1 right characters from i
		  // e.g. for abba, d2[2]=2;
		  for (int i = 0, l = 0, r = -1; i < n; i++) {
		    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
		      k++;
		    }
		    d2[i] = k--;
		    if (i + k > r) {
		      l = i - k - 1;
		      r = i + k ;
		    }
		  }
		  
		// for(auto i : d2) cout << i << ' '; cout << endl;
		
		vi nxt(n, n+1);
		
		vpii cur;
		for(int i = n-2; i >= 0; i--){
			
			while(!cur.empty() && cur.back().second > i){
				cur.pop_back();
			}
			
			if(d2[i+1]){
				cur.push_back({i, i+1-d2[i+1]});
			}
			
			if(!cur.empty()){
				
				int m = cur.back().first;
				nxt[i] = m + (m-i) + 2;
				
				// cout << cur.back().first << ' ' << cur.back().second << endl;
			}
		}
		
		// cout << str << endl;
		// for(auto i : nxt) cout << i << ' '; cout << endl;
		
		int lg_2 = ceil(log2(double(n))) + 1;
		vector<vi> jmp(n, vi(lg_2, n+1));
		
		for(int i = n-1; i >= 0; i--){
			
			jmp[i][0] = nxt[i];
			
			// cout << i << ' ' << nxt[i] << endl << flush;
			
			for(int j = 1; j < lg_2; j++){
				if(jmp[i][j-1]>=n) break;
				// cout << i << ' ' << j << ' ' << jmp[i][j-1] << endl << flush;
				jmp[i][j] = jmp[jmp[i][j-1]][j-1];
			}
		}
		
		// continue;
		
		int ans = 0;
		for(int i = 0; i < n; i++){
			
			int j = i;
			int cnt = 0;
			
			for(int i = lg_2-1; i >= 0; i--){
				
				if(j==n) break;
				
				if(jmp[j][i] <= n){
					j = jmp[j][i];
					cnt += 1<<i;
				}
			}
			
			// cout << i << ' ' << cnt << endl;
			
			ans += cnt;
		}
		
		cout << ans << endl;
    }	
}
