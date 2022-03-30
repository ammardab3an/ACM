// Problem: E. Masha-forgetful
// Contest: Codeforces - Codeforces Round #764 (Div. 3)
// URL: http://codeforces.com/contest/1624/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int vid;
int vis_2[10][10];
iii loc_vis_2[10][10];
int vis_3[10][10][10];
iii loc_vis_3[10][10][10];

int n, m;
string num;
int mem[1010];

int go(int i){
	
	if(i == m){
		return 0;
	}	
	if(i == m-1){
		return INF;
	}
	
	int &ret = mem[i];
	if(ret+1) return ret;
	
	int ans = INF;
	
	// st_path
	if(i+1 < m){
		if(vis_2[num[i]-'0'][num[i+1]-'0'] == vid){
			int cans = 1+go(i+2);
			ans = min(ans, cans);
		}
	}
	
	// nd_path
	if(i+2 < m){
		if(vis_3[num[i]-'0'][num[i+1]-'0'][num[i+2]-'0'] == vid){
			int cans = 1+go(i+3);
			ans = min(ans, cans);
		}
	}
	
	return ret = ans;
}

void calc(int i){
	
	if(i == m){
		return;
	}
	if(i == m-1){
		assert(false);
	}
	
	int ans = go(i);
	int st_path = INF;
	int nd_path = INF;
	
	// st_path
	if(i+1 < m){
		if(vis_2[num[i]-'0'][num[i+1]-'0'] == vid){
			st_path = 1+go(i+2);
		}
	}
	
	// nd_path
	if(i+2 < m){
		if(vis_3[num[i]-'0'][num[i+1]-'0'][num[i+2]-'0'] == vid){
			nd_path = 1+go(i+3);
		}
	}
	
	if(st_path == ans){
		auto t = loc_vis_2[num[i]-'0'][num[i+1]-'0'];
		cout << t.second.first+1 << ' ' << t.second.second+1 << ' ' << t.first+1 << endl;
		calc(i+2);
	}
	else if(nd_path == ans){
		auto t = loc_vis_3[num[i]-'0'][num[i+1]-'0'][num[i+2]-'0'];
		cout << t.second.first+1 << ' ' << t.second.second+1 << ' ' << t.first+1 << endl;
		calc(i+3);
	}
	else{
		assert(false);
	}
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

		cin >> n >> m;
		
		vid++;
		memset(mem, -1, sizeof mem);
		
		for(int i = 0; i < n; i++){
			
			string tmp;
			cin >> tmp;
			
			for(int j = 0; j+1 < m; j++){
				vis_2[tmp[j]-'0'][tmp[j+1]-'0'] = vid;
				loc_vis_2[tmp[j]-'0'][tmp[j+1]-'0'] = {i, {j, j+1}};
			}
			
			for(int j = 0; j+2 < m; j++){
				vis_3[tmp[j]-'0'][tmp[j+1]-'0'][tmp[j+2]-'0'] = vid;
				loc_vis_3[tmp[j]-'0'][tmp[j+1]-'0'][tmp[j+2]-'0'] = {i, {j, j+2}};
			}
		}
		
		cin >> num;
		int ans = go(0);
		
		if(ans > m){
			cout << -1 << endl;
		}
		else{
			cout << ans << endl;
			calc(0);
		}
    }	
}
