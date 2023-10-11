// Problem: H. Heximal
// Contest: Codeforces - 2022 ICPC Asia Taiwan Online Programming Contest
// URL: https://codeforces.com/gym/103990/problem/H
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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

int inv(int x){
	return pow_exp(x, MOD-2);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

typedef complex<double> cd;

void fft(vector<cd> & a, bool invert) {
	
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vi mul_fft(const vi &a, const vi &b){
	
	int sz = a.size() + b.size() -1;
	sz = 1 << int(ceil(log2(sz)));
	
	vector<cd> A(a.rbegin(), a.rend());
	vector<cd> B(b.rbegin(), b.rend());
	
	A.resize(sz, 0);
	B.resize(sz, 0);
	
	fft(A, false);
	fft(B, false);
	
	for(int i = 0; i < sz; i++){
		A[i] *= B[i];
	}	
	
	fft(A, true);
	
	vi res(sz);
	res.push_back(0);
	
	for(int i = 0; i < sz; i++){
		int d = round(A[i].real()) + res[i];
		res[i] = d%10;
		res[i+1] += d/10;
	}
	
	while(res.size() > 1 && res.back()==0){
		res.pop_back();
	}
	
	reverse(res.begin(), res.end());
	
	return res;
}

bool comp(const vi &a, const vi &b){
	
	if(a.size() != b.size()){
		return a.size() < b.size();
	}	
	
	return a < b;
}

int32_t main(){
    
    fastIO;
	
	// vi tmp = mul_fft({1, 2, 3}, {3, 3});
	// for(auto e : tmp) cout << e << ' '; cout << endl;
	
	string str_num;
	cin >> str_num;
	
	vi num(str_num.size());
	for(int i = 0; i < str_num.size(); i++){
		num[i] = str_num[i]-'0';
	}
	
	vector<vi> tmp;
	tmp.push_back({6});
	
	while(comp(tmp.back(), num)){
		tmp.push_back(mul_fft(tmp.back(), tmp.back()));
	}
	
	// for(auto e : tmp.back()) cout << e << ' '; cout << endl;
	
	vi cur = {1};
	int ans = 0;
	for(int i = tmp.size()-1; i >= 0; i--){
		vi ncur = mul_fft(cur, tmp[i]);
		if(!comp(num, ncur)){
			ans += 1 << i;
			cur = ncur;
		}
	}
	
	ans++;
	// if(cur != num) ans++;
	// for(auto e : cur) cout << e << ' '; cout << endl;
	cout << ans << endl;
}
