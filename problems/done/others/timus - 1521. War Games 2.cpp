// Problem: 1521. War Games 2
// Contest: Timus Online Judge - Timus Top Coders: Third Challenge
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1521
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
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
 
const int MAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(MAX)));

int bitSz;
int bit[(1<<LOG_MAX) + 1];

void bitUpdate(int idx, int val){
    for(int i = idx; i <= bitSz; i += i & (-i)){
        bit[i] += val;
    }
}

int bitQuery(int idx){
    int res = 0;
    for(int i = idx; i >= 1; i -= i & (-i))
        res += bit[i];
    return res;
}

int binaryLifting(int val){

    int ptr = 0;
    int sum = 0;

    for(int i = bitSz/2; i >= 1; i /= 2) {
        if(sum + bit[ptr+i] < val){
            sum += bit[ptr+i];
            ptr += i;
        }
    }
    
    return ptr+1;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, k;
    cin >> n >> k;
    
    // cout << MAX << endl;
    // cout << (1<<LOG_MAX) << endl;
    
    int m = 2*n;
    bitSz = 1 << int(ceil(log2(double(m))));
    
    for(int i = 1; i <= n; i++){
    	bitUpdate(i, +1);
    	bitUpdate(n+i, +1);
    }
    
    int tot = n;
    int ans = 0;
    
    int lst = k;
    ans = abs(lst-1);
    bitUpdate(k, -1);
    bitUpdate(n+k, -1);
    tot--;
    
    cout << k << ' ';
    
    for(int i = 2; i <= n; i++){
    	
    	int cur = k;
    	cur--;
    	cur %= tot;
    	cur++;
    	
    	int lst_cnt = bitQuery(lst);
    	int cur_ans = binaryLifting(lst_cnt+cur);
    	if(cur_ans > n) cur_ans -= n;
    	
    	// cout << lst << ' ' << cur << ' ' << lst_cnt+cur << ' ' << cur_ans << endl;
    	
    	lst = cur_ans;
    	cout << cur_ans << ' ';
    	bitUpdate(cur_ans, -1);
    	bitUpdate(n+cur_ans, -1);
    	tot--;
    }
}
