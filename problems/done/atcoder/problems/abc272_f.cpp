// Problem: F - Two Strings
// Contest: AtCoder - AtCoder Beginner Contest 272
// URL: https://atcoder.jp/contests/abc272/tasks/abc272_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

void count_sort(vector<int> &p, vector<int> &c){

    int n = p.size();
	
	vector<int> cnt(n), pos(n), p_new(n);
	
	for(auto i : c) {
		cnt[i]++;	
	}
	
    pos[0] = 0;
    for(int i = 1; i < n; i++){
    	pos[i] = pos[i-1] + cnt[i-1];
    }
    
	for(auto x : p){
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}
	
	p = p_new;
}

vi suffix(string &str){

    str += "$";
    int n = str.size();

    vector<int> p(n), c(n);

    {
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
        	a[i] = {str[i], i};        	
        }

        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++){
        	p[i] = a[i].second;        	
        }

        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else
                c[p[i]] = c[p[i-1]] +1;

        }
    }

    for(int k = 0; (1 << k) < n; k++){

        for(int i = 0; i < n; i++){
        	p[i] = (p[i] - (1 << k) + n) % n;
        }
        
		count_sort(p, c);
		
		vector<int> c_new(n);
		
        c_new[p[0]] = 0;
        for(int i = 1; i < n; i++){
            
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
            pair<int, int> now  = {c[p[ i ]], c[(p[ i ] + (1 << k)) % n]};

            if(now == prev)
                c_new[p[i]] = c_new[p[i-1]];
            else
                c_new[p[i]] = c_new[p[i-1]] +1;

        }
        
        c = c_new;
    }

	return p;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n;
    cin >> n;
    
    string a, b;
    cin >> a >> b;
    
    if(n==0){
    	n = 2e5;
    	a = b = string(n, 'a');
    }
    
    string t = a+a + string(n, 'a') + b+b + string(n, 'z');
    
    vi suf_t = suffix(t);
    
    int64_t ans = 0;
    
    int cnt = 0;
    for(auto i : suf_t){
    	if(i < n){
    		cnt++;
    	}	
    	else if(3*n <= i && i < 4*n){
    		ans += cnt;
    	}
    }
    
    cout << ans << endl;
}
