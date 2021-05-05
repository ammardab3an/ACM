// Problem: Roaring Years
// Contest: Google Coding Competitions - Round 1C 2021 - Code Jam 2021
// URL: https://codingcompetitions.withgoogle.com/codejam/round/00000000004362d7/00000000007c0f01
// Memory Limit: 1024 MB
// Time Limit: 30000 ms
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

bool mul_of_nine(int n){
    
    bool ret = true;
    while(n) ret &= n%10==9, n/=10;
    return ret;    
}

int to_long(string n){
    
    int ret = 0;
    for(int i = 0; i < n.size(); i++){
        ret *= 10;
        ret += n[i]-'0';
    }    
    return ret;
}

int nnt(int n){
    
    int cnt = 0;
    while(n) cnt++, n/=10;
    return cnt;    
}

int gen(int i, int cnt){
    
    int ret = 0;
    
    while(cnt > 0){
        int nnt_i = nnt(i);
        ret *= pow(10, nnt_i);
        cnt -= nnt_i;
        ret += i++;
    }
    
    if(cnt < 0) return -1;
    
    return ret;
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int tt = 1;
    int t; cin >> t; while(t--){

        cout << "Case #" << tt++ << ": ";
        
        int num;
        cin >> num;
        
        int ans = INFLL;
        int cnt = nnt(num);
        bool b = false;
        
        while(ans == INFLL){        
        
            for(int i = 1; nnt(i) <= cnt/2; i++){
                
                int nans = gen(i, cnt);
                
                if((nans != -1)){
                    if(b || (nans > num)){
                        ans = min(ans, nans);
                    }
                }
            }
            
            b = true;
            cnt++;
        }
        
        cout << ans << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
