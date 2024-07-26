// E. Sheep Eat Wolves
// https://contest.ucup.ac/contest/1449/problem/7781

// By AmmarDab3an 

#include <bits/stdc++.h>

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

// int fac[NMAX], ifac[NMAX];
// 
// void init(){
// 	
	// fac[0] = 1;
	// for(int i = 1; i < NMAX; i++){
		// fac[i] = mul(fac[i-1], i);
	// }
// 	
	// ifac[NMAX-1] = inv(fac[NMAX-1]);
	// for(int i = NMAX-2; i >= 0; i--){
		// ifac[i] = mul(ifac[i+1], i+1);
	// }
// }
// 
// int choose(int n, int c){
	// assert(n >= c);
	// return mul(fac[n], mul(ifac[c], ifac[n-c]));
// }

int dist[111][111][2];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int a, b, sz, q;
	cin >> a >> b >> sz >> q;
	
	memset(dist, INF, sizeof dist);
	
	priority_queue<pair<pii, pii>> que;
	dist[a][b][0] = 0;
	que.push({{0, 0}, {a, b}});
	
	int ans = -1;
	
	while(!que.empty()){
		
		auto [cd, bb] = que.top().first;
		auto [c0, c1] = que.top().second;
		que.pop();
		cd *= -1;
		
		// cout << c0 << ' ' << c1 << ' ' << bb << endl;
		
		if(bb && c0==a){
			ans = cd;
			break;
		}
		
		if(cd > dist[c0][c1][bb]){
			continue;
		}
		
		for(int i = 0; i <= c0; i++)
		for(int j = 0; j <= c1; j++) if(i+j <= sz){
			
			int nc0 = c0-i;
			int nc1 = c1-j;
			
			if(nc0) if(nc1) if(nc1 > (nc0+q)) continue;
			
			int &nxt_d = dist[a-nc0][b-nc1][!bb];
			
			if(nxt_d > cd+1){
				nxt_d = cd+1;
				que.push({{-nxt_d, !bb}, {a-nc0, b-nc1}});
			}
		}
	}
	
	cout << ans << endl;
}
