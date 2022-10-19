// Problem: D. Derivative of polynomial
// Contest: Codeforces - 2021 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/103577/problem/D
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
    
    reverse(str.begin(), str.end());
    
    if(str.back() != '-'){	
	    str.push_back('+');
    }
    
    map<int, int> mp;
    
    while(!str.empty()){
    	
    	string cur;
    	cur.push_back(str.back());
    	str.pop_back();
    	
    	while(!str.empty() && str.back() != '-' && str.back() != '+'){
    		
    		cur.push_back(str.back());
    		str.pop_back();
    		
    		if(cur.back()=='^' && str.back()=='-'){
    			cur.push_back(str.back());
    			str.pop_back();
    		}
    	}
    	
    	int a = 0;
    	int sign_a = cur[0]=='-' ? -1 : 1;
    	
    	int i;
    	for(i = 1; i < cur.size(); i++){
    		if(cur[i]=='x'){
    			break;
    		}
    		a *= 10;
    		a += cur[i]-'0';
    	}
    	
    	if(i==1){
    		a = 1;
    	}
    	
    	int b = 0;
    	int sign_b = 0;
    	
    	if(i != cur.size()){
    		
    		if(i+1==cur.size() || cur[i+1]!='^'){
    			b = 1;
    			sign_b = 1;
    		}
    		else{
	    		i+=2;
	    		b = 0;
	    		sign_b = 1;
	    		
	    		if(cur[i]=='-') sign_b=-1, ++i;
	    		
	    		for(; i < cur.size(); i++){
	    			b *= 10;
	    			b += cur[i]-'0';
	    		}
    		}
    	}
    	
    	
    	mp[sign_b*b-1] += sign_a * sign_b * a*b;
    	
    	// cout << cur << endl;
    	// cout << a << ' ' << b << endl;
    	// cout << sign_b*b-1 << ' ' << sign_a*sign_b*a*b << endl;
    }
    
    bool bo = false;
    bool empty = true;
    
    for(auto [b, a] : mp){
    	
    	if(!a) continue;
    	
		if(a > 0 && bo){
			cout << '+';
		}
    	
    	bo = true;
    	
    	if(!b){
    		cout << a;
    	}
    	else if(a==1 && b==1){
    		cout << 'x';
    	}
    	else if(a==1){
    		cout << "x^" << b;
    	}
    	else if(b==1){
    		cout << a << 'x';
    	}
    	else{
    		cout << a << "x^" << b;
    	}
    	
    	empty = false;
    	// cout << endl;
    }
    
    if(empty){
    	cout << '0';
    }
}
