// Problem: G - Longest Y
// Contest: AtCoder - NEC Programming Contest 2021(AtCoder Beginner Contest 229)
// URL: https://atcoder.jp/contests/abc229/tasks/abc229_g
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    string str;
    cin >> str;
    
    int k;
    cin >> k;
    
    int n = str.size();
    vector<vi> pre(2, vi(n));
    vector<vi> suf(2, vi(n));
    
    pre[0][0] = str[0]=='.';
    pre[1][0] = str[0]=='Y';
    
    for(int i = 1; i < n; i++){
    	pre[0][i] = pre[0][i-1] + (str[i]=='.');
    	pre[1][i] = pre[1][i-1] + (str[i]=='Y');
    }
    
    suf[0][n-1] = str[n-1]=='.';
    suf[1][n-1] = str[n-1]=='Y';
    
    for(int i = n-2; i >= 0; i--){
    	suf[0][i] = suf[0][i+1] + (str[i]=='.');
    	suf[1][i] = suf[1][i+1] + (str[i]=='Y');
    }
    
    vi ppre(n), ssuf(n);
    
    ppre[0] = 0;
    for(int i = 1; i < n; i++){
    	ppre[i] = ppre[i-1] + pre[0][i] * (str[i]=='Y');
    }
    
    ssuf[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
    	ssuf[i] = ssuf[i+1] + suf[0][i] * (str[i]=='Y');
    }
    
    auto get_pre_cnt = [&](int k, int l, int r){
    	return pre[k][r] - pre[k][l] + (str[l]==".Y"[k]);
    };
    
    vi pst(n);
    pst[0] = 0;
    for(int i = 1; i < n; i++){
    	pst[i] = pst[i-1];
    	if(str[i]=='Y') pst[i] = i;
    }
    
    auto query = [&](int l, int r){
    	
    	r = pst[r];
    	
    	int m_l = l;
    	int m_r = r;
    	int bs_ans = l;
    	int cnt_1 = get_pre_cnt(1, l, r);
    	
    	while(m_l <= m_r){
    		
    		int mid = (m_l + m_r)/2;
    		
    		if(get_pre_cnt(1, l, mid) >= (cnt_1+1)/2){
    			bs_ans = mid;
    			m_r = mid-1;
    		}
    		else{
    			m_l = mid+1;
    		}
    	}
		
		int i = bs_ans;
		int st_path = ssuf[l] - (i+1 < n ? (ssuf[i+1] + get_pre_cnt(1, l, i) * suf[0][i+1]) : 0);
		int nd_path = ppre[r] - (i-1 >=0 ? (ppre[i-1] + get_pre_cnt(1, i, r) * pre[0][i-1]) : 0);
		int ret = st_path + nd_path;
		
		// cout << i << ' ' << st_path << ' ' << nd_path << endl;
		
		return ret;
    };
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) if(str[i]=='Y'){
    	
    	int l = i;
    	int r = n-1;
    	
    	int cans = 0;
    	
    	while(l <= r){
    		
    		int mid = (l+r)/2;
    		
    		if(query(i, mid) <= k){
    			cans = get_pre_cnt(1, i, mid);
    			l = mid+1;
    		}
    		else{
    			r = mid-1;
    		}
    	}
    	
    	ans = max(ans, cans);
    }
    
    cout << ans << endl;
}
