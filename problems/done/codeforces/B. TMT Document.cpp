// Problem: B. TMT Document
// Contest: Codeforces - Codeforces Round #715 (Div. 2)
// URL: https://codeforces.com/contest/1509/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n;
        cin >> n;
        
        string str;
        cin >> str;
        
        vi vec_m, vec_t;
        
        int cnt_m = 0, cnt_t = 0;
        
        for(int i = 0; i < n; i++){
            if(str[i] == 'T') cnt_t++;
            else cnt_m++;
        }
        
        if(cnt_t != 2*cnt_m){
            cout << "NO" << endl;
            continue;
        }
        
        int no = false;
        cnt_t = 0, cnt_m = 0;
        
        for(int i= 0; i < n; i++){
            if(str[i] == 'T'){
                cnt_t++;
            }
            else{
                cnt_m++;
                if(cnt_t <= i/2){
                    no = true;
                    break;
                }
            }
        }
        
        cnt_t = 0;
        for(int i = n-1; i >= 0; i--){
            
            if(str[i] == 'T') cnt_t++;
            else {
                if(cnt_t <= (n-i-1)/2){
                    no = true;
                    break;
                }
            }
        }
        
        if(no){
            cout << "NO" << endl;
            continue;
        }
        
        cout << ((cnt_m == n/3) ? "YES" : "NO") << endl;
    }	
    
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
