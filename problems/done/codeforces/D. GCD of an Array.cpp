// tle cause by the primes numbers greater than sqrt(n) you idiot 
// 
// Problem: D. GCD of an Array
// Contest: Codeforces - Codeforces Round #705 (Div. 2)
// URL: https://codeforces.com/contest/1493/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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

//#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n, m;
lli ans = 1;
multiset<int> gcd_fac[NMAX];
map<int, int> arr[NMAX];

vpii get(int num){

	vpii ret;

	for(int i = 2; i * i <= num; i++){
		int cnt = 0;
		while(num % i == 0) cnt++, num /= i;
		if(cnt) ret.emplace_back(i, cnt);
	}

	if(num != 1) ret.emplace_back(num, 1);

	return ret;
}

int fast_pow(int n, int p){
	if(!p) return 1;
	if(p & 1) return (1LL * n * fast_pow(n, p-1)) % MOD;
	lli tmp = fast_pow(n, p/2);
	return (tmp * tmp) % MOD;
}

void update(int idx, int num){

	auto factors = get(num);

	for(auto p : factors){

        int old_p = 0;

	if(arr[idx].find(p.first) != arr[idx].end()){
		old_p = *gcd_fac[p.first].begin();
		gcd_fac[p.first].erase(gcd_fac[p.first].find(arr[idx][p.first]));
	}

        arr[idx][p.first] += p.second;
        gcd_fac[p.first].insert(arr[idx][p.first]);

        if(gcd_fac[p.first].size() == n)
            ans = (ans * fast_pow(p.first, *gcd_fac[p.first].begin() - old_p)) % MOD;
	}
}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	cin >> n >> m;

	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		update(i, num);
	}

	while(m--){
		int i, x;
		cin >> i >> x;
		update(i-1, x);
		cout << ans << endl;
	}
}
