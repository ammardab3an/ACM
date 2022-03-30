// Problem: Interesting Integers
// Contest: Google Coding Competitions - Round A 2022 - Kick Start 2022
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e73ea
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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

int n;
string num;
int sm;
int mem[22][222][222][2][2];
int vis[22][222][222][2][2], vid;
int mem_0[22][222][2][2];
int vis_0[22][222][2][2], vid_0;

int go(int i, int md, int rm, bool b, bool d){
	
	if(i == n){
		return md==0 && rm==0;
	}	
	
	if(vis[i][md][rm][b][d] == vid){
		return mem[i][md][rm][b][d];
	}
	else{
		vis[i][md][rm][b][d] = vid;
	}
	
	int ret = 0;
	
	int mx = b ? 9 : num[i]-'0';
	mx = min(mx, rm);
	
	for(int j = 0; j <= mx; j++){
		if(d && j==0) continue;
		int nmd = d ? (md*j)%sm : j%sm;
		ret += go(i+1, nmd, rm-j, b || (j<(num[i]-'0')), d || j);
	}
	
	return mem[i][md][rm][b][d] = ret;
}


int go_0(int i, int md, bool b, bool d){
	
	if(i == n){
		return md==0 && d;
	}	
	
	if(vis_0[i][md][b][d] == vid){
		return mem_0[i][md][b][d];
	}
	else{
		vis_0[i][md][b][d] = vid;
	}
	
	int ret = 0;
	
	int mx = b ? 9 : num[i]-'0';
	
	for(int j = 0; j <= mx; j++){
		int nmd = d ? (md==0 ? 0 : j) : j;
		ret += go_0(i+1, nmd, b || (j<(num[i]-'0')), d || j);
	}
	
	return mem_0[i][md][b][d] = ret;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    
	vi vec, _vec;
	for(int i = 1; i < 120; i++){
		int t = i;
		while(t%2==0) t /= 2;
		while(t%3==0) t /= 3;
		while(t%5==0) t /= 5;
		while(t%7==0) t /= 7;
		if(t==1) vec.push_back(i);
		else _vec.push_back(i);
	}
	
	int tt = 1;
    int t; cin >> t; while(t--){
		
		cout << "Case #" << tt++ << ": ";
		
		int a, b;
		cin >> a >> b;
		
		// a = 1;
		// b = 1e12;
		
		int ans = 0;
		
		{
			num = to_string(b);
			n = num.size();
			
			for(auto i : vec){	
				vid++;
				sm = i;
				int cans = go(0, 0, sm, 0, 0);
				ans += cans;
			}
			
			vid_0++;
			ans += go_0(0, 0, 0, 0);
		}
		
		if(a){
			
			num = to_string(a-1);
			n = num.size();
			
			for(auto i : vec){
				vid++;
				sm = i;
				int cans = go(0, 0, sm, 0, 0);
				ans -= cans;
			}
			
			
			vid_0++;
			ans -= go_0(0, 0, 0, 0);
		}
		
		cout << ans << endl;
    }	
}
