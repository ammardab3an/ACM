// Problem: J. Joining the KAK
// Contest: Codeforces - 2022 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/103940/problem/J
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

const int NMAX = 1e6 + 10;

int frq[33];
int suf[33];
vector<string> vec;
string res;

void go(int i, int rm){
	
	if(i==26){
		assert(rm==0);
		vec.push_back(res);
		return;
	}
	
	if(!rm || (i+1<26 && suf[i+1] >= rm)){
		go(i+1, rm);
	}
	
	int mn = min(frq[i], rm);
	for(int f = 1; f <= mn; f++){
		res.push_back('a'+i);
		if(rm==f || (i+1<26 && suf[i+1]>=(rm-f))){
			go(i+1, rm-f);
		}
	}
	for(int f = 1; f <= mn; f++){
		res.pop_back();
	}
}

int mem[1010][22][22];
int cho[55][55];

void init_cho(){
	
	for(int i = 0; i < 55; i++)
	for(int j = 0; j <= i; j++){
		if(!j || i==j){
			cho[i][j] = 1;
		}
		else{
			cho[i][j] = cho[i-1][j] + cho[i-1][j-1];
		}
	}	
}

int calc(int i, int rm, int k){
	
	if(i==26){
		return 1;
	}
	
	int &ret = mem[i][rm][k];
	if(ret+1) return ret;
		
	int ans = 0;
	
	if(!rm || (i+1<26 && suf[i+1] >= rm)){
		ans += calc(i+1, rm, k);
	}
	
	int mn = min(frq[i], rm);
	for(int f = 1; f <= mn; f++){
		if(rm==f || (i+1<26 && suf[i+1]>=(rm-f))){
			ans += calc(i+1, rm-f, k+f) * cho[k+1+f-1][f];
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
    
    init_cho();
    
    int n, m;
    cin >> n >> m;
    
    string str;
    cin >> str;
    
    n = str.size();
    
    for(auto c : str){
    	frq[c-'a']++;
    }
    
    suf[25] = frq[25];
    for(int i = 24; i >= 0; i--){
    	suf[i] = suf[i+1] + frq[i];
    }
    
    memset(mem, -1, sizeof mem);
    
    int len = 1;
    while(true){
    	int tt = calc(0, len, 0);
    	if(m <= tt) break;
    	m -= tt;
    	len++;
    }
    
    go(0, len);
    
    set<pair<string, bool>> st;
    for(auto s : vec){
    	st.insert({s, s.back()==s.front()});
    }
    
    while(--m){
    	auto p = *st.begin();
    	st.erase(st.begin());
    	if(next_permutation(p.first.begin(), p.first.end()) || !p.second){
    		p.second = 1;
    		st.insert(p);
    	}
    }
    
    cout << (st.begin()->first) << endl;
}
