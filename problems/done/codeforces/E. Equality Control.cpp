// Problem: E. Equality Control
// Contest: Codeforces - 2018-2019 ICPC Northwestern European Regional Programming Contest (NWERC 2018)
// URL: https://codeforces.com/gym/102483/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

pair<vpii, vi> eval(const string &s){
	
	vi vec;
	vpii vec_r;
	
	for(int i = 0; i < (int)s.size(); i++){
		
		if(s[i]==',' || s[i]==')') continue;
		
		if(s[i]=='['){
			int j = i+1;
			string tmp;
			while(s[j] != ']'){
				if(s[j] != ','){				
					tmp.push_back(s[j]);
				}
				else{
					tmp.push_back(' ');
				}
				j++;
			}
			stringstream ss(tmp);
			int e;
			while(ss >> e){
				vec.push_back(e);
			}
			i = j+1;
		}
		else if(s[i]=='c'){
			i += 6;
		}
		else if(s[i]=='s'){
			
			bool is_shuffle = s[i+1]=='h';
			
			int lvl = 0;
			bool b = false;
			
			int j = i+1;
			string tmp;
			while(true){
				
				if(s[j]=='('){
					b = true;
					lvl++;
				}
				else if(s[j]==')'){
					lvl--;
					if(b && lvl==0) break;
				}
				
				if(isdigit(s[j])){				
					tmp.push_back(s[j]);
				}
				else{
					tmp.push_back(' ');
				}
				j++;
			}
			
			stringstream ss(tmp);
			
			int e;
			vi tmp_v;
			while(ss >> e){
				tmp_v.push_back(e);
			}
			
			sort(tmp_v.begin(), tmp_v.end());
			
			if(is_shuffle && tmp_v.front() != tmp_v.back()){
				vec_r.push_back({vec.size(), vec.size()+tmp_v.size()-1});
			}
			
			vec.insert(vec.end(), tmp_v.begin(), tmp_v.end());
			i = j+1;
		}
	}
	
	return {vec_r, vec};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    string s0, s1;
    cin >> s0 >> s1;
    
    auto e0 = eval(s0);
    auto e1 = eval(s1);
    
    cout << (e0==e1 ? "equal" : "not equal") << endl;
}
