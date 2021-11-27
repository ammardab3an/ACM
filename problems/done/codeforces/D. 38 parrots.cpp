// Problem: D. 38 parrots
// Contest: Codeforces - 2017-2018 ICPC Central Quarter Final of Northeastern European Regional Collegiate Programming Contest
// URL: https://codeforces.com/gym/102788/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

struct monoQueue{
    
    stack<pii> s1, s2;
    
    int size(){
        return s1.size() + s2.size();
    }    
    
    int empty(){
        return !size();
    }
    
    void clear(){
        while(!empty()) pop();
    }
    
    int get_gcd(){
        
        if(empty()){
            return 0;
        }
        if(!s1.empty() && !s2.empty()){
            return __gcd(s1.top().second, s2.top().second);
        }
        if(!s2.empty()){
            return s2.top().second;
        }
        return s1.top().second;
    }
    
    void push(int val){
        
        if(s2.empty()){
            s2.push({val, val});
        }
        else{
            s2.push({val, __gcd(s2.top().second, val)});
        }
    }
    
    int pop(){
        
        if(s1.empty()){
            while(!s2.empty()){
                
                if(s1.empty()){
                    s1.push({s2.top().first, s2.top().first});
                }
                else{
                    s1.push({s2.top().first, __gcd(s2.top().first, s1.top().second)});
                }
                
                s2.pop();
            }
        }
        assert(!s1.empty());
        int ret = s1.top().first;
        s1.pop();
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
    
    monoQueue que;
    multiset<int> mst;
    
    int t; cin >> t; while(t--){
        
        char c;
        cin >> c;
        
        if(c=='?'){
            int g = que.get_gcd();
            if(mst.count(g)){
                cout << "Y" << g << endl;
            }        
            else{
                cout << "N" << endl;
            }
        }
        else if(c=='+'){
            int v;
            cin >> v;
            que.push(v);
            mst.insert(v);
        }
        else{
            mst.erase(mst.find(que.pop()));
        }
    }	
}
