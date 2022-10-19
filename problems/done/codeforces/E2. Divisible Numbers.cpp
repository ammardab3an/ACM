// Problem: E2. Divisible Numbers (hard version)
// Contest: Codeforces - Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/E2
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

vi cc(int x){
	
	vi f_x;
	
	while(x%2==0){
		f_x.push_back(2);
		x /= 2;
	}
	
	for(int i = 3; i*i <= x; i += 2){
		while(x%i==0){
			f_x.push_back(i);
			x /= i;
		}
	} 	
	
	if(x>1) f_x.push_back(x);
	
	return f_x;
}

vi calc(int x, int y){
	
	vi f_x = cc(x);
	vi f_y = cc(y);
	
	vpii tt;
	
	int i = 0, j = 0;
	int lst = -1, cnt = 0;
	
	while(i < f_x.size() || j < f_y.size()){
		
		if(i==f_x.size() || (j != f_y.size() && f_x[i] > f_y[j])){
			swap(i, j);
			swap(f_x, f_y);
		}	
		
		if(f_x[i]==lst){
			cnt++;
		}
		else{
			if(cnt){			
				tt.emplace_back(lst, cnt);
			}
			cnt = 1;
			lst = f_x[i];
		}
		
		i++;
	}
	
	if(cnt){
		tt.emplace_back(lst, cnt);
	}
	
	vi ret;
	queue<pii> que;
	que.push({0, 1});
	while(!que.empty()){
		
		pii fr = que.front();
		que.pop();
		
		int i = fr.first;
		int x = fr.second;
		
		if(i==tt.size()){
			ret.push_back(x);
			continue;
		}
		
		auto [f, c] = tt[i];
		
		int y = 1;
		for(int j = 0; j <= c; j++){
			que.push({i+1, x*y});
			y *= f;
		}
	}
	
	return ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){
    	
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		pii ans = {-1, -1};
		
		vi factors = calc(a, b);
		
		int ab = a*b;
		for(auto f : factors){
			
			int kx = f;
			int ky = ab/f;
			
			int x = (c/kx)*kx;
			int y = (d/ky)*ky;
			
			if(a < x && b < y){
				ans = {x, y};
				break;
			}
		}
		
		auto [x, y] = ans;
		if(x != -1 || y != -1){
			assert(a < x && x <= c);
			assert(b < y && y <= d);
			assert((x*y)%(a*b)==0);
		}
		
		cout << ans.first << ' ' << ans.second << endl;
    }	
}
