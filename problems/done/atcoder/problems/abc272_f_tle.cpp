// Problem: F - Two Strings
// Contest: AtCoder - AtCoder Beginner Contest 272
// URL: https://atcoder.jp/contests/abc272/tasks/abc272_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

vi suffix(string str){

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

struct hash_struct{
	
	int n;
	string str;
	
	array<int, 2> p, m;
	vector<array<int, 2>> pre;
	vector<array<int, 2>> pow_m;
	
	hash_struct(){}
	
	hash_struct(string _str){
		str = _str;
		n = str.size();
		init();
		build();
	}
	
	bool is_prime(int x){
		for(ll i = 2; i*i <= x; i++) if(x%i==0){
			return false;
		}
		return true;
	}
	
	void init(){
		
		p = {130807, 1250284429}; // {rand(1e5, 2e5), rand(1e9, 2e9)};
		m = {53, 79}; // {rand(30, 50), rand(50, 100)};
		
		// for(int j = 0; j < 2; j++){
			// while(!is_prime(p[j])) p[j]++;
			// while(!is_prime(m[j])) m[j]++;
		// }
		
		pow_m.resize(n, array<int, 2>({0, 0}));
		
		pow_m[0][0] = pow_m[0][1] = 1;
		for(int i = 1; i < n; i++)
		for(int j = 0; j < 2; j++){
			pow_m[i][j] = (pow_m[i-1][j] *1ll* m[j])%p[j];
		}
	}
	
	void build(){
		
		pre.resize(n);
		
		array<int, 2> cval = {0, 0};
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 2; j++){
				cval[j] = ((cval[j] *1ll* m[j])%p[j] + (str[i]-'a'+1))%p[j];
			}
			pre[i] = cval;
		}
	}
	
	array<int, 2> query(int l, int r){
		array<int, 2> ret = pre[r];
		if(l) for(int j = 0; j < 2; j++){
			ret[j] = (ret[j] - (pre[l-1][j] *1ll* pow_m[r-l+1][j])%p[j] + p[j])%p[j];
		}
		return ret;
	}
	
};

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
    
    a += a;
    b += b;
    
    vi suf_b = suffix(b);
    
    {
    	vi nsuf_b;
    	for(auto i : suf_b) if(i < n){
    		nsuf_b.push_back(i);
    	}
    	swap(suf_b, nsuf_b);
    }
    
    assert(suf_b.size()==n);
    
    hash_struct hs_a(a), hs_b(b);
    
    int64_t ans = 0;
    
    auto same = [&](int i, int j, int len){
    	return hs_a.query(i, i+len-1) == hs_b.query(j, j+len-1);
    };
    
    auto test = [&](int i, int j){
    	
    	int l = 1;
    	int r = n;	
    	
    	int bs_ans = 0;
    	
    	while(l <= r){
    		
    		int mid = (l+r)/2;
    		
    		if(same(i, j, mid)){
    			bs_ans = mid;
    			l = mid+1;
    		}
    		else{
    			r = mid-1;
    		}
    	}
    	
    	return bs_ans==n || (a[i+bs_ans] < b[j+bs_ans]);
    };
    
    for(int i = 0; i < n; i++){
    	
    	int l = 0;
    	int r = n-1;
    	
    	int bs_ans = 0;
    	
    	while(l <= r){
    		
    		int mid = (l+r)/2;
    		
    		if(test(i, suf_b[mid])){
    			bs_ans = n-mid;
    			r = mid-1;
    		}
    		else{
    			l = mid+1;
    		}
    	}
    	
    	ans += bs_ans;
    }
    
    cout << ans << endl;
}
