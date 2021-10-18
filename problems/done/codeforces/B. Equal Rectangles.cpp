// Problem: B. Equal Rectangles
// Contest: Codeforces - Codeforces Round #579 (Div. 3)
// URL: https://codeforces.com/contest/1203/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
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
const int BLOCK = ceil(sqrt(double(NMAX)));

bool go(map<int, int> mp, int area){
    
    for(auto &p : mp) if(p.second){
        
        int l = p.first;
        int c = p.second;
        
        if(area%l!=0) return false;
        
        int cc = mp[area/l];
        
        if(cc != c) return false;
    }   
    
    return true; 
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int t; cin >> t; while(t--){

        int n;
        cin >> n;
        
        map<int, int> mp;
        for(int i = 0; i < 4*n; i++){
            int li;
            cin >> li;
            mp[li]++;
        }
        
        int good = true;
        
        vi vec;
        
        for(auto p : mp){
            
            if(p.second%2==1){
                good = false;
                break;
            }
            else{
                vec.push_back(p.first);
            }
        }
        
        if(!good){
            cout << "NO" << endl;
            continue;
        }
        
        
        int ans = false;
        
        int m = vec.size();
        for(int i = 0; i < m; i++){
            
            int area = vec[i]*vec[0];
                
            if(go(mp, area)){
                ans = true;
                break;
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'
  
  notes : 
  
  
*/    