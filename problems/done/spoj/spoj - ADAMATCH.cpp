// Problem: Ada and Nucleobase
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/ADAMATCH/
// Memory Limit: 1536 MB
// Time Limit: 6500 ms
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

const int NMAX = 2 * 5e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

complex<double> pre_exp[2][(1 << LOG_MAX) + 1];

void fill_pre(){
    int mx = (1 << LOG_MAX) + 1;
    for(int i = 1; i < mx; i++){
        pre_exp[0][i] = exp(complex<double>(0, 2.0*PI/i));
        pre_exp[1][i] = exp(complex<double>(0, -2.0*PI/i));
    }
}

valarray<complex<double> > fft(const valarray<complex<double> > &x,int sign=-1)
{
    int N = x.size();
    
    if(N == 1){
        return x;
    }
        
    valarray<complex<double> > even = x[slice(0,N/2,2)];
    valarray<complex<double> > odd = x[slice(1,N/2,2)];
    
    even = fft(even, sign);
    odd = fft(odd, sign);
    
    valarray<complex<double> > X(N);
    complex<double> cm1=1, cm2=pre_exp[sign==-1][N];
    
    for(int k=0;k<N/2;k++){
        X[k] = even[k]+cm1*odd[k];
        X[k+N/2] = even[k]-cm1*odd[k];
        cm1 *= cm2;
    }
    
    return X;
}

valarray<complex<double> > inv_fft(const valarray<complex<double> > &x)
{
    complex<double> N=x.size();
    return fft(x,1)/N;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
	
    fill_pre();
    
	string a, b;
	
	while(cin >> a >> b){
		
		int n = a.size();
		int m = b.size();
		
		reverse(b.begin(), b.end());
		
		int deg_a = n-1;
		int deg_b = m-1;
		int deg_res = deg_a + deg_b;
		int res_sz = deg_res+1;
		
		res_sz = 1 << int(ceil(log2(double(res_sz))));
		
		valarray<int> tot(res_sz);
		
		for(auto c : "ACTG"){
			
			valarray<complex<double>> A(res_sz), B(res_sz);
			
			for(int i = 0; i < n; i++){
				A[i] = a[i]==c;
			}	
			for(int i = 0; i < m; i++){
				B[i] = b[i]==c;
			}
			
			A = fft(A);
			B = fft(B);
			A *= B;
			A = inv_fft(A);
			
			for(int i = 0; i < res_sz; i++){
				tot[i] += round(A[i].real());
			}
		}
		
		// cout << res_sz << endl;
		// for(auto i : tot) cout << i << ' ' ; cout << endl;
		
		int ans = 0;
		for(int i = 0; i+m-1 < n; i++){
			ans = max(ans, tot[i+m-1]);
		}
		
		cout << m-ans << endl;
	}
}
