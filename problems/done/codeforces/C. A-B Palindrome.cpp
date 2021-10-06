// Problem: C. A-B Palindrome
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/C#
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int a, b, n;
char str[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> a >> b >> str;
        n = strlen(str);
        
        bool bad = false;
        for(int i = 0, j = n - 1; i < j; i++, j--) {
            if(str[i] != '?' && str[j] != '?')
                if(str[i] != str[j]) {
                    bad = true;
                    break;
                }
        }

        if(bad) {
            cout << -1 << endl;
            continue;
        }
        
        for(int l = 0, r = n-1; l < r; l++, r--){
            
            bool b0 = str[l] == '?';
            bool b1 = str[r] == '?';
            
            if(str[l] == '0') a--;
            if(str[l] == '1') b--;
            if(str[r] == '1') b--;
            if(str[r] == '0') a--;
            
            if(b0 && b1) continue;
            
            if(b0 && !b1){
                
                if(str[r] == '0'){
                    str[l] = '0';
                    a--;
                }
                else{
                    str[l] = '1';
                    b--;
                }
            }
            
            if(b1 && !b0){
                
                if(str[l] == '0'){
                    str[r] = '0';
                    a--;
                }
                else{
                    str[r] = '1';
                    b--;
                }
            }
        }
        
        int l, r;
        for(l = 0, r = n-1; l < r; l++, r--){

            bool b0 = str[l] == '?';
            bool b1 = str[r] == '?';
            
            if(b0 && b1){
                
                if(a > b){
                    str[r] = str[l] = '0';
                    a-=2;
                }
                else{
                    str[r] = str[l] = '1';
                    b-=2;
                }
            }
        }
        
        if(l==r){
            if(str[l] == '?'){
                if(a > b){
                    str[l] = '0';
                    a--;
                }
                else{
                    str[l] = '1';
                    b--;
                }
            }
            else{
                if(str[l] == '0') a--;
                else b--;
            }
        }
        
        if(a != 0 || b != 0){
            cout << -1 << endl;
        }
        else{
            cout << str << endl;
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
