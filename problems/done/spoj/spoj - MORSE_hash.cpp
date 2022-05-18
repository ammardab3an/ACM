// Problem: Decoding Morse Sequences
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/MORSE/
// Memory Limit: 1536 MB
// Time Limit: 7000 ms
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
const int NMAX = 1e4 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
string str;
string arr[NMAX];
string conv[26];
int mem[NMAX];
map<pii, int> mp;
vi p, m;

void init_conv(){
	conv['A'-'A'] = ".-";   
	conv['B'-'A'] = "-...";
	conv['C'-'A'] = "-.-."; 
	conv['D'-'A'] = "-..";
	conv['E'-'A'] = ".";    
	conv['F'-'A'] = "..-.";
	conv['G'-'A'] = "--."; 
	conv['H'-'A'] = "....";
	conv['I'-'A'] = "..";   
	conv['J'-'A'] = ".---";
	conv['K'-'A'] = "-.-";  
	conv['L'-'A'] = ".-..";
	conv['M'-'A'] = "--";   
	conv['N'-'A'] = "-.";
	conv['O'-'A'] = "---";  
	conv['P'-'A'] = ".--.";
	conv['Q'-'A'] = "--.-"; 
	conv['R'-'A'] = ".-.";
	conv['S'-'A'] = "..."; 
	conv['T'-'A'] = "-";
	conv['U'-'A'] = "..-";  
	conv['V'-'A'] = "...-";
	conv['W'-'A'] = ".--";  
	conv['X'-'A'] = "-..-";
	conv['Y'-'A'] = "-.--"; 
	conv['Z'-'A'] = "--..";
}

bool is_prime(int x){
	for(int i = 2; i*i <= x; i++) if(x%i==0){
		return false;
	}
	return true;
}

void init(){
	
	p = {rand(1e5, 2e5), rand(1e9, 2e9)};
	m = {rand(30, 50), rand(50, 100)};
	
	for(int j = 0; j < 2; j++){
		while(!is_prime(p[j])) p[j]++;
		while(!is_prime(m[j])) m[j]++;
	}
	
	mp.clear();
	for(int i = 0; i < n; i++){
		
		vi pre(2);
		
		for(auto _c : arr[i])
		for(auto c : conv[_c-'A']){
			for(int k = 0; k < 2; k++){
				pre[k] = ((pre[k]*1ll*m[k])%p[k] + (c=='.' ? 1 : 2))%p[k];
			}
		}
		
		mp[{pre[0], pre[1]}]++;
	}
}

int go(int i){
	
	if(i==(int)str.size()){
		return 1;
	}	
	
	int &ret = mem[i];
	if(ret+1) return ret;
	
	int ans = 0;
	
	vi pre(2);
	for(int j = i; j < str.size(); j++){
		
		char c = str[j];
		
		for(int k = 0; k < 2; k++){
			pre[k] = ((pre[k]*1ll*m[k])%p[k] + (c=='.' ? 1 : 2))%p[k];
		}
		
		auto it = mp.find({pre[0], pre[1]});
		if(it != mp.end()){
			ans += (it->second) * go(j+1);
		}
	}
	
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    init_conv();
    
    int t; cin >> t; while(t--){

		cin >> str;
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		init();
		
		memset(mem, -1, sizeof mem);
		cout << go(0) << endl;
    }	
}
