// Problem: Investigation
// Contest: Virtual Judge - LightOJ
// URL: https://vjudge.net/problem/LightOJ-1068
// Memory Limit: 32 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef unsigned int		uint;
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

//#define int int64_t

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int k, sz;
vi vec_l, vec_h;
int mem[20][2][2][100][100];

int go(int pos, bool b_l, bool b_h, int k_c, int k_m, int p){

	if(pos == sz) return !k_c && !k_m;
	
	int & ret = mem[pos][b_l][b_h][k_c][k_m];
	if(ret + 1) return ret;
	
	int ans = 0;
	
	int mn = b_l ? 0 : vec_l[pos];
	int mx = b_h ? 9 : vec_h[pos];
	
	for(int i = mn; i <= mx; i++){
				
		ans += go(pos+1, 
			
			b_l | (i > vec_l[pos]), 
			b_h | (i < vec_h[pos]), 
			
			(k_c + i) % k, 

			( k_m + i*(int)round(pow(10, p)) ) % k, 

			p-1);	
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	int tc; cin >> tc;
	
	for(int t = 1; t <= tc; t++){
		
		int a, b;
		cin >> a >> b >> k;
		
		if(k > 85){
			cout << "Case " << t << ": " << 0 << endl;
			continue;
		}
		
		int ans = 0;
		
		vec_l.clear();
		vec_h.clear();

		while(a){vec_l.push_back(a%10); a/=10;};
		while(b){vec_h.push_back(b%10); b/=10;};
		
		int dif = vec_h.size() - vec_l.size();
		while(dif--) vec_l.push_back(0);
		
		reverse(vec_l.begin(), vec_l.end());
		reverse(vec_h.begin(), vec_h.end());
		
		sz = vec_h.size();
		
		memset(mem, -1, sizeof mem);
		ans += go(0, 0, 0, 0, 0, sz-1);
		
		cout << "Case " << t << ": " << ans << endl;
	}

}
