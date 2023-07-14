// Problem: A. Almost Origami
// Contest: Codeforces - 2020-2021 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/103185/problem/A
// Memory Limit: 1024 MB
// Time Limit: 250 ms
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

int fac[NMAX], ifac[NMAX];

void init(){
	
	fac[0] = 1;
	for(int i = 1; i < NMAX; i++){
		fac[i] = mul(fac[i-1], i);
	}
	
	ifac[NMAX-1] = inv(fac[NMAX-1]);
	for(int i = NMAX-2; i >= 0; i--){
		ifac[i] = mul(ifac[i+1], i+1);
	}
}

int choose(int n, int c){
	assert(n >= c);
	return mul(fac[n], mul(ifac[c], ifac[n-c]));
}

vi ans[111];
vi tmp = {1};

void dfs(){
	
	if(ans[tmp.back()].empty() || ans[tmp.back()].size() > tmp.size()){
		ans[tmp.back()] = tmp;
	}
	
	if(tmp.size() >= 10){
		return;
	}
	
	for(int i = 0; i < tmp.size(); i++)
	for(int j = tmp.size()-1; j >= i; j--){
		
		if(tmp[i]+tmp[j] < tmp.back()) break;
		
		tmp.push_back(tmp[i]+tmp[j]);
		dfs();
		tmp.pop_back();
	}
}

void ans_init(){
	
	ans[1] = {1};
	ans[2] = {1, 2};
	ans[3] = {1, 2, 3};
	ans[4] = {1, 2, 4};
	ans[5] = {1, 2, 3, 5};
	ans[6] = {1, 2, 3, 6};
	ans[7] = {1, 2, 3, 4, 7};
	ans[8] = {1, 2, 4, 8};
	ans[9] = {1, 2, 3, 6, 9};
	ans[10] = {1, 2, 3, 5, 10};
	ans[11] = {1, 2, 3, 4, 7, 11};
	ans[12] = {1, 2, 3, 6, 12};
	ans[13] = {1, 2, 3, 5, 8, 13};
	ans[14] = {1, 2, 3, 4, 7, 14};
	ans[15] = {1, 2, 3, 5, 10, 15};
	ans[16] = {1, 2, 4, 8, 16};
	ans[17] = {1, 2, 4, 8, 9, 17};
	ans[18] = {1, 2, 3, 6, 9, 18};
	ans[19] = {1, 2, 3, 4, 8, 11, 19};
	ans[20] = {1, 2, 3, 5, 10, 20};
	ans[21] = {1, 2, 3, 4, 7, 14, 21};
	ans[22] = {1, 2, 3, 4, 7, 11, 22};
	ans[23] = {1, 2, 3, 5, 10, 13, 23};
	ans[24] = {1, 2, 3, 6, 12, 24};
	ans[25] = {1, 2, 3, 5, 10, 15, 25};
	ans[26] = {1, 2, 3, 5, 8, 13, 26};
	ans[27] = {1, 2, 3, 6, 9, 18, 27};
	ans[28] = {1, 2, 3, 4, 7, 14, 28};
	ans[29] = {1, 2, 3, 4, 7, 11, 18, 29};
	ans[30] = {1, 2, 3, 5, 10, 15, 30};
	ans[31] = {1, 2, 3, 4, 7, 14, 17, 31};
	ans[32] = {1, 2, 4, 8, 16, 32};
	ans[33] = {1, 2, 4, 8, 16, 17, 33};
	ans[34] = {1, 2, 4, 8, 9, 17, 34};
	ans[35] = {1, 2, 3, 4, 7, 14, 21, 35};
	ans[36] = {1, 2, 3, 6, 9, 18, 36};
	ans[37] = {1, 2, 3, 5, 8, 16, 21, 37};
	ans[38] = {1, 2, 3, 4, 8, 11, 19, 38};
	ans[39] = {1, 2, 3, 5, 8, 13, 26, 39};
	ans[40] = {1, 2, 3, 5, 10, 20, 40};
	ans[41] = {1, 2, 3, 5, 10, 20, 21, 41};
	ans[42] = {1, 2, 3, 4, 7, 14, 21, 42};
	ans[43] = {1, 2, 3, 5, 10, 20, 23, 43};
	ans[44] = {1, 2, 3, 4, 7, 11, 22, 44};
	ans[45] = {1, 2, 3, 5, 10, 15, 30, 45};
	ans[46] = {1, 2, 3, 5, 10, 13, 23, 46};
	ans[47] = {1, 2, 3, 4, 7, 10, 20, 27, 47};
	ans[48] = {1, 2, 3, 6, 12, 24, 48};
	ans[49] = {1, 2, 3, 6, 12, 24, 25, 49};
	ans[50] = {1, 2, 3, 5, 10, 15, 25, 50};
	ans[51] = {1, 2, 3, 6, 12, 24, 27, 51};
	ans[52] = {1, 2, 3, 5, 8, 13, 26, 52};
	ans[53] = {1, 2, 3, 5, 6, 12, 24, 29, 53};
	ans[54] = {1, 2, 3, 6, 9, 18, 27, 54};
	ans[55] = {1, 2, 3, 4, 7, 11, 22, 33, 55};
	ans[56] = {1, 2, 3, 4, 7, 14, 28, 56};
	ans[57] = {1, 2, 3, 4, 7, 14, 28, 29, 57};
	ans[58] = {1, 2, 3, 4, 7, 11, 18, 29, 58};
	ans[59] = {1, 2, 3, 4, 7, 14, 28, 31, 59};
	ans[60] = {1, 2, 3, 5, 10, 15, 30, 60};
	ans[61] = {1, 2, 3, 5, 7, 14, 28, 33, 61};
	ans[62] = {1, 2, 3, 4, 7, 14, 17, 31, 62};
	ans[63] = {1, 2, 3, 4, 7, 14, 21, 42, 63};
	ans[64] = {1, 2, 4, 8, 16, 32, 64};
	ans[65] = {1, 2, 4, 8, 16, 32, 33, 65};
	ans[66] = {1, 2, 4, 8, 16, 17, 33, 66};
	ans[67] = {1, 2, 3, 4, 8, 16, 32, 35, 67};
	ans[68] = {1, 2, 4, 8, 9, 17, 34, 68};
	ans[69] = {1, 2, 3, 5, 8, 16, 32, 37, 69};
	ans[70] = {1, 2, 3, 4, 7, 14, 21, 35, 70};
	ans[71] = {1, 2, 3, 4, 7, 8, 16, 32, 39, 71};
	ans[72] = {1, 2, 3, 6, 9, 18, 36, 72};
	ans[73] = {1, 2, 3, 6, 9, 18, 36, 37, 73};
	ans[74] = {1, 2, 3, 5, 8, 16, 21, 37, 74};
	ans[75] = {1, 2, 3, 5, 10, 15, 25, 50, 75};
	ans[76] = {1, 2, 3, 4, 8, 11, 19, 38, 76};
	ans[77] = {1, 2, 4, 5, 9, 18, 36, 41, 77};
	ans[78] = {1, 2, 3, 5, 8, 13, 26, 39, 78};
	ans[79] = {1, 2, 3, 4, 7, 9, 18, 36, 43, 79};
	ans[80] = {1, 2, 3, 5, 10, 20, 40, 80};
	ans[81] = {1, 2, 3, 5, 10, 20, 40, 41, 81};
	ans[82] = {1, 2, 3, 5, 10, 20, 21, 41, 82};
	ans[83] = {1, 2, 3, 5, 10, 20, 40, 43, 83};
	ans[84] = {1, 2, 3, 4, 7, 14, 21, 42, 84};
	ans[85] = {1, 2, 3, 5, 10, 20, 40, 45, 85};
	ans[86] = {1, 2, 3, 5, 10, 20, 23, 43, 86};
	ans[87] = {1, 2, 3, 4, 7, 10, 20, 40, 47, 87};
	ans[88] = {1, 2, 3, 4, 7, 11, 22, 44, 88};
	ans[89] = {1, 2, 3, 4, 7, 11, 22, 44, 45, 89};
	ans[90] = {1, 2, 3, 5, 10, 15, 30, 45, 90};
	ans[91] = {1, 2, 3, 4, 7, 11, 22, 44, 47, 91};
	ans[92] = {1, 2, 3, 5, 10, 13, 23, 46, 92};
	ans[93] = {1, 2, 3, 4, 7, 14, 17, 31, 62, 93};
	ans[94] = {1, 2, 3, 4, 7, 10, 20, 27, 47, 94};
	ans[95] = {1, 2, 3, 4, 7, 11, 22, 44, 51, 95};
	ans[96] = {1, 2, 3, 6, 12, 24, 48, 96};
	ans[97] = {1, 2, 3, 6, 12, 24, 48, 49, 97};
	ans[98] = {1, 2, 3, 6, 12, 24, 25, 49, 98};
	ans[99] = {1, 2, 3, 6, 12, 24, 48, 51, 99};
	ans[100] = {1, 2, 3, 5, 10, 15, 25, 50, 100};

}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
	// init();
	
	int A, B;
	cin >> A >> B;

	int g = __gcd(A, B);
	A /= g, B /= g;	
	
	if(A != 1){
		cout << '*' << endl;
		return 0;
	}
	
	// dfs();
	// for(int i = 1; i <= 100; i++){
		// cout << "ans[" << i << "] = ";
		// cout << "{";
		// bool b = false;
		// for(auto e : ans[i]){
			// if(b) cout << ", ";
			// cout << e;
			// b = true;
		// }
		// cout << "};" << endl;
	// }
	
	ans_init();
	vi ans = ::ans[B];
	
	for(int i = 1; i < ans.size(); i++){
		
		bool found = false;
		
		for(int a = 0; a < i && !found; a++)
		for(int b = 0; b <= a; b++){
			
			if(ans[a]+ans[b]==ans[i]){
				found = true;
				cout << 1 << ' ' << ans[a] << endl;
				cout << 1 << ' ' << ans[b] << endl;
				break;
			}
		}
	}
}
