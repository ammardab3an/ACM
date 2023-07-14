// Problem: D2. Hot Start Up (hard version)
// Contest: Codeforces - Codeforces Round #854 by cybercats (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1799/problem/D2
// Memory Limit: 512 MB
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
 
const int NMAX = 3e5 + 10;

int arr[NMAX];
int val[NMAX][2];

int sz;
int narr[NMAX];
int nval[NMAX][2];
int lst[NMAX];
int nxt[NMAX];
int pre[NMAX];
int mem[NMAX];
int vis[NMAX], vid;

int go(int i){
	
	if(i==sz-1){
		return 0;
	}
	
	int &ret = mem[i+1];
	int &vis = ::vis[i+1];
	if(vis==vid) return ret;
	vis = vid;	
	
	int st_path = INFLL;
	int nd_path = INFLL;
	int rd_path = INFLL;
	
	{
		int sm = nval[i+1][0];
		if(i >= 1) if(narr[i-1]==narr[i+1]) sm += nval[i+1][1] - nval[i+1][0];
		st_path = sm + go(i+1);
	}
	
	if(i >= 0 && nxt[i] < sz){
		int sm = pre[nxt[i]-1] - pre[i] + nval[nxt[i]][1];
		if(i >= 1) if(narr[i-1]==narr[i+1]) sm += nval[i+1][1] - nval[i+1][0];
		nd_path = sm + go(nxt[i]);
	}
	
	if(i >= 1 && nxt[i-1] < sz){
		int sm = pre[nxt[i-1]-1] - pre[i] + nval[nxt[i-1]][1];
		rd_path = sm + go(nxt[i-1]);
	}
	
	return ret = min(st_path, min(nd_path, rd_path));
}

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
		
		for(int i = 0; i < n; i++){
			cin >> arr[i], --arr[i];
		}
		
		for(int i = 0; i < m; i++) cin >> val[i][0];
		for(int i = 0; i < m; i++) cin >> val[i][1];
			
		// 0 cold
		// 1 hot
		
		{
			sz = 0;
			
			int lst = arr[0], cnt = 1;
			for(int i = 1; i < n; i++){
				if(lst==arr[i]){
					cnt++;
				}
				else{
					narr[sz] = lst;
					nval[sz][0] = val[lst][0] + val[lst][1]*(cnt-1);
					nval[sz][1] = val[lst][1]*(cnt);
					lst = arr[i];
					cnt = 1;
					sz++;
				}
			}
			
			if(cnt){
				narr[sz] = lst;
				nval[sz][0] = val[lst][0] + val[lst][1]*(cnt-1);
				nval[sz][1] = val[lst][1]*(cnt);
				sz++;
			}
		}
		
		for(int i = 0; i < m; i++){
			lst[i] = sz;
		}
		
		for(int i = sz-1; i >= 0; i--){
			nxt[i] = lst[narr[i]];
			lst[narr[i]] = i;
		}
		
		pre[0] = nval[0][0];
		for(int i = 1; i < sz; i++){
			pre[i] = pre[i-1] + nval[i][0];
		}
		
		// for(int i = 0; i < sz; i++) cout << narr[i] << ' '; cout << endl;
		// for(int i = 0; i < sz; i++) cout << nval[i][0] << ' '; cout << endl;
		// for(int i = 0; i < sz; i++) cout << nval[i][1] << ' '; cout << endl;
		// for(int i = 0; i < sz; i++) cout << nxt[i] << ' '; cout << endl;
		
		vid++;
		int ans = go(-1);
		cout << ans << endl;
    }	
}
