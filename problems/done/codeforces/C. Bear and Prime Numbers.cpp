// Problem: C. Bear and Prime Numbers
// Contest: Codeforces - Codeforces Round #226 (Div. 2)
// URL: https://codeforces.com/contest/385/problem/C?outsideGroup=true
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

const int NMAX = 1e7 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n;
    cin >> n;
    
    vi cnt(NMAX);
    for(int i = 0; i < n; i++){
        int ai; cin >> ai; cnt[ai]++;
    }
    
    vi primes, f;
    bitset<NMAX> bs;
    bs.reset(); bs.flip();
    for(lli i = 2; i < 1e7 + 10; i++) if(bs.test(i)){
        primes.push_back(i);
        int cans = 0;
        for(lli j = i; j < 1e7 + 10; j += i){
            bs.set(j, 0);
            cans += cnt[j];
        }
        f.push_back(cans);
    }
    
    vi pre(primes.size());
    
    pre[0] = f[0];
    for(int i = 1; i < primes.size(); i++){
        pre[i] = pre[i-1] + f[i];
    }
    
    int m; cin >> m; while(m--){
        
        int l, r;
        cin >> l >> r;
        
        r = min(r, (int)10000000);
        
        auto it_l = lower_bound(primes.begin(), primes.end(), l);
        auto it_r = upper_bound(primes.begin(), primes.end(), r);
        
        if(it_r != primes.begin()){
            
            it_r--;
            
            int cans = pre[it_r - primes.begin()];
            if(it_l != primes.begin())
                cans -= pre[--it_l - primes.begin()];
                
            cout << cans << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
