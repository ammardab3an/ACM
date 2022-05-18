// Problem: H. Reverse the String
// Contest: Codeforces - 2021 Jiangsu Collegiate Programming Contest
// URL: https://codeforces.com/gym/103495/problem/H
// Memory Limit: 256 MB
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
const int NMAX = 1e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int p[] = {MOD, MOD+2};
int m[] = {31, 37};
int pow_m[NMAX][2];

struct hash_struct{

	int n;
	string str;

	vector<array<int, 2>> pre;

	hash_struct(){}

	hash_struct(string _str){
		str = _str;
		n = str.size();
		build();
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

void init(){
	
	pow_m[0][0] = pow_m[0][1] = 1;
	for(int i = 1; i < NMAX; i++)
	for(int j = 0; j < 2; j++){
		pow_m[i][j] = (pow_m[i-1][j] *1ll* m[j])%p[j];
	}	
} 

int32_t main(){

	fastIO;

#ifdef LOCAL
	freopenI;
	freopenO;
#endif

    // freopen("name.in", "r", stdin);

	init();
	
    int t; cin >> t; while(t--){

		string str;
		cin >> str;

		int n = str.size();

		reverse(str.begin(), str.end());

		char mn = 'z' + 1;
		int cnt = 0;
			
		for(int i = 0; i < n; i++){

			if(str[i] <= mn){
				cnt++;
			}
			else{
				cnt = 0;
			}

			mn = min(mn, str[i]);
		}
			
		string ans = str.substr(str.size()-cnt);
		reverse(ans.begin(), ans.end());
		n -= cnt;
		str.resize(n);
		
		hash_struct hash_pre(str);
		reverse(str.begin(), str.end());
		hash_struct hash_suf(str);
		reverse(str.begin(), str.end());

		auto calc = [&](int pos, int len){

			int len_l = pos;
			int len_r = n-pos;

			if(len <= len_r){
				return hash_pre.query(pos, pos+len-1);
			}

			array<int, 2> ret = hash_pre.query(pos, pos+len_r-1);
			len -= len_r;

			if(len){
				array<int, 2> tmp = hash_suf.query(len_r, len_r+len-1);
				for(int i = 0; i < 2; i++){
					ret[i] = (ret[i] * pow_m[len][i]) % p[i];
					ret[i] = (ret[i] + tmp[i]) % p[i];
				}
			}

			return ret;
		};

		auto get_ch = [&](int pos, int len){

			int len_l = pos;
			int len_r = n-pos;

			if(len <= len_r){
				return str[pos+len-1];
			}
			else{
				return str[pos-(len-len_r)];
			}
		};

		auto comp = [&](int p0, int p1, int len){
			array<int, 2> hash_0 = calc(p0, len);
			array<int, 2> hash_1 = calc(p1, len);
			return hash_0==hash_1;
		};

		int ans_p = 0;

		for(int i = 0; i < n; i++){

			int l = 1;
			int r = n;

			int bs_ans = 0;

			while(l <= r){

				int mid = (l+r)/2;

				if(comp(ans_p, i, mid)){
					bs_ans = mid;
					l = mid+1;
				}
				else{
					r = mid-1;
				}
			}

			if(bs_ans == n){
				continue;
			}

			char c0 = get_ch(ans_p, bs_ans+1);
			char c1 = get_ch(i, bs_ans+1);

			if(c0 > c1){
				ans_p = i;
			}
		}

		int rev_len = n-ans_p;

		reverse(str.begin(), str.end());
		reverse(str.begin(), str.begin() + rev_len);

		cout << ans+str << endl;
    }
}
