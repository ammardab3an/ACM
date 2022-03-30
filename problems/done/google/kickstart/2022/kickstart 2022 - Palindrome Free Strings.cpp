// Problem: Palindrome Free Strings
// Contest: Google Coding Competitions - Round A 2022 - Kick Start 2022
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e762e
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
 
const int NMAX = 5e4 + 10;

int n;
string str;
int mem[NMAX][1 << 5];
int vis[NMAX][1 << 5], vid;

bool test_5(int cur){
	int i = 0, j = 4;
	while(i <= j){
		if(((cur>>i)&1) != ((cur>>j)&1)){
			return false;
		}
		i++, j--;
	}	
	return true;
}

bool test_6(int cur){
	int i = 0, j = 5;
	while(i <= j){
		if(((cur>>i)&1) != ((cur>>j)&1)){
			return false;
		}
		i++, j--;
	}	
	return true;
}

int go(int i, int pst){
	
	if(i == n){
		return true;
	}
	
	pst &= (1 << 5)-1;
	
	if(vis[i][pst] == vid){
		return mem[i][pst];
	}
	else{
		vis[i][pst] = vid;
	}
	
	if(str[i] != '?'){
		
		int cur = pst*2+(str[i]-'0');
		
		if((i<=3 || !test_5(cur)) && (i<=4 || !test_6(cur))){
			return mem[i][pst] = go(i+1, cur);
		}
		else{
			return mem[i][pst] = false;
		}
	}
	
	bool st_path = false;
	bool nd_path = false;
		
	// st_path
	{
		int cur = pst*2;
		if((i<=3 || !test_5(cur)) && (i<=4 || !test_6(cur))){
			st_path = go(i+1, cur);
		}
	}	
	
	// nd_path
	{
		int cur = pst*2+1;
		if((i<=3 || !test_5(cur)) && (i<=4 || !test_6(cur))){
			nd_path = go(i+1, cur);
		}
	}
	
	return mem[i][pst] = st_path || nd_path;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int tt = 1;
    int t; cin >> t; while(t--){

		cout << "Case #" << tt++ << ": ";
		
		cin >> n;
		cin >> str;
		
		vid++;
		
		if(go(0, 0)){
			cout << "POSSIBLE" << endl;
		}
		else{
			cout << "IMPOSSIBLE" << endl;
		}
    }	
}
