// Problem: E. Request Throttling
// Contest: Codeforces - 2021-2022 ICPC, NERC, Southern and Volga Russian Regional Contest (problems intersect with Educational Codeforces Round 117)
// URL: https://codeforces.com/gym/103430/problem/E
// Memory Limit: 512 MB
// Time Limit: 6000 ms
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

struct node{
	
	int cnt = 0;
	node *nxt[2];
	
	node(){
		cnt = 0;
		nxt[0] = nxt[1] = nullptr;
	}
	
	node(int x){
		cnt = x;
		nxt[0] = nxt[1] = nullptr;
	}
};

int cnt[33];

bool test(node *cur, int x){
	
	for(int i = 0; i < 32; i++){
		
		if(!cur->cnt) return false;
	
		bool b = x & (1ll << (31-i));
		
		if(!cur->nxt[b]){
			cur->nxt[b] = new node(::cnt[i+1]);
		}
		
		cur = cur->nxt[b];
	}	
	
	return cur->cnt;
}

void update(node *cur, int x){
	
	for(int i = 0; i < 32; i++){
		
		assert(cur->cnt > 0);
		
		cur->cnt -= 1;
		
		bool b = x & (1ll << (31-i));
		
		if(!cur->nxt[b]){
			cur->nxt[b] = new node(::cnt[i+1]);
		}
		
		cur = cur->nxt[b];
	}
	
	cur-> cnt -= 1;
}
	
int conv(string str){
	
	str += '.';
	reverse(str.begin(), str.end());
	
	int x = 0;
	while(str.size()){
		
		int y = 0;
		while(str.back() != '.'){
			y *= 10;
			y += str.back()-'0';
			str.pop_back();
		}
		str.pop_back();
		
		x = (x << 8) + y;
	}	
	
	return x;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    for(int i = 0; i < 33; i++){
    	cin >> cnt[i];
    }
    
    int n;
    cin >> n;
    
    node root(cnt[0]);
    
    while(n--){
    	
    	string str;
    	cin >> str;
    	
    	int cur = conv(str);
    	
    	if(test(&root, cur)){
    		cout << 'a' << endl;
    		update(&root, cur);
    	}
    	else{
    		cout << 'b' << endl;
    	}
    	
    }
}
