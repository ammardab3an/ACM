// iiot
// https://training.olinfo.it/#/task/ois_scount/statement

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
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int NMAX = 1e5 + 10;

int fac[NMAX], ifac[NMAX];

void init(){
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	ifac[NMAX-1] = pow_exp(fac[NMAX-1], MOD-2);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(mul(fac[n], ifac[c]), ifac[n-c]);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init();
    
    int n;
    cin >> n;
   	
   	vi vec(n);
   	for(auto &i : vec) cin >> i;
   	
   	sort(vec.begin(), vec.end());
   	
   	vpii res;
   	
   	{
   		vi tmp;
	   	{
		   	int cnt = 1;
		   	for(int i = 1; i < n; i++){
		   		if(vec[i] != vec[i-1]){
		   			tmp.push_back(cnt);
		   			cnt = 0;
		   		}
		   		cnt++;
		   	}	 
		   	tmp.push_back(cnt);
	   	}
	   	
	   	sort(tmp.begin(), tmp.end());
	   	
	   	{
	   		int lst = tmp[0];
	   		int cnt = 1;
	   		for(int i = 1; i < tmp.size(); i++){
	   			if(tmp[i] != tmp[i-1]){
	   				res.push_back({tmp[i-1], cnt});
	   				lst = tmp[i];
	   				cnt = 0;
	   			}
	   			cnt++;
	   		}
	   		res.push_back({tmp.back(), cnt});
	   	}
	   	
	   	sort(res.begin(), res.end());
	   	reverse(res.begin(), res.end());
   	}
   	
   	int ans = 0;
   	
   	for(int i = res[0].first; i >= 1; i--){
   		
   		int fans = 1;
   		
   		for(int j = 0; j < res.size() && res[j].first >= i; j++){
   			int x = choose(res[j].first, i);
   			fans = mul(fans, pow_exp(x+1, res[j].second));
   		}
   		
   		ans = add(ans, fans);
   	}
   	
   	ans = (ans-res[0].first+1+MOD)%MOD;
   	cout << ans << endl;
}
