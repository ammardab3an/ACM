// Problem: D. Kill Anton
// Contest: Codeforces - Codeforces Round #723 (Div. 2)
// URL: https://codeforces.com/contest/1526/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
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

int count_inv(const vi &vec){
    
    int sz = vec.size() + 10;
    
    vi tree(2 * sz);
    
    int ret = 0;
    
    for(int i = 0; i < vec.size(); i++){
        
        int l = vec[i] + sz;
        int r = sz + sz;
        
        int ans = 0;
            
        for(; l < r; l/=2, r/=2){
            if(l&1) ans += tree[l++];
            if(r&1) ans += tree[--r];
        }
        
        int p = vec[i] + sz;
        for(tree[p] += 1; p > 1; p/=2) tree[p/2] = tree[p] + tree[p^1];
        
        ret += ans;
    }
    
    return ret;
}


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int t; cin >> t; while(t--){

        string str;
        cin >> str;
        
        map<char, int> mp;
        
        for(auto c : str) mp[c]++;
        
        int cur = 0;
        map<char, int> cmp;
        map<int, char> cpm;
        
        for(auto p : mp) {
            cmp[p.first] = cur;
            cpm[cur] = p.first;
            cur++;
        }
        
        vi tmp;
        for(int i = 0; i < mp.size(); i++){
            tmp.push_back(i);
        }
        
        int ans = -1;
        vi vans;
        
        do{
            vi nstr;
            for(int i = 0; i < str.size(); i++){
                nstr.push_back(tmp[cmp[str[i]]]);
            }
            
            int cans = count_inv(nstr);
            
            if(cans > ans){
                ans = cans;
                vans = tmp;
            }
             
        } while(next_permutation(tmp.begin(), tmp.end()));
        
        
        for(int i = 0; i < vans.size(); i++){
            
            for(int j = 0; j < vans.size(); j++) if(vans[j] == i){
                
                int cnt = mp[cpm[j]];
                
                while(cnt--) cout << cpm[j];
            }    
        }
                
        cout << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll]
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    