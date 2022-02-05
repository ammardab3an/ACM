// Problem: Sky Code
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/MSKYCODE/en/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int NMAX = 1e4 + 10;
const int AMAX = 1e4 + 10;

int n;
int arr[NMAX];
int fac[AMAX];
int p[AMAX], cnt;
bool is_prime[AMAX], vis[AMAX];

void fill_prime_arr(){
	memset(is_prime, true, sizeof is_prime);
	is_prime[1] = false;
	for(int i = 2; i < AMAX; i++) if(is_prime[i])
		for(lli j = i*i; j < AMAX; j += i)
			is_prime[j] = false;
}

lli dfs(int d, int k, int pos){
	
	if(k > AMAX) return 0;
	if(k > 1 && fac[k] < 4) return 0;

	lli ret = 0;

	if(d){
		lli s = fac[k];
		lli sum = s * (s-1) * (s-2) * (s-3) / (4 * 3 * 2);
		if(d&1) ret -= sum;
		else    ret += sum;
	}

	for(int i = pos; i < cnt; i++) if(!vis[i]){
		vis[i] = true;
		ret += dfs(d+1, k*p[i], i+1);
		vis[i] = false;
	}

	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	fill_prime_arr();

	while(cin >> n){
		
		cnt = 0;
		memset(fac, 0, sizeof fac);

		for(int i = 0; i < n; i++) 
			cin >> arr[i];

		for(int i = 0; i < n; i++){
			lli ai = arr[i], j = 1;
			for(; j*j < ai; j++) if(ai%j == 0)
				fac[j]++, fac[ai/j]++;
			if(j*j == ai) fac[j]++;
		}

		for(int i = 2; i < AMAX; i++) if(is_prime[i] && fac[i] >= 4)
			p[cnt++] = i;

		lli ans = 1ll * n * (n-1) * (n-2) * (n-3) / (4 * 3 * 2);
		ans += dfs(0, 1, 0);
		
		cout << ans << endl;
	}
}
