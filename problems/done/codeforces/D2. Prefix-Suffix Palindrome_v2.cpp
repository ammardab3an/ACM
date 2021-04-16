// Problem: D2. Prefix-Suffix Palindrome (Hard version)
// Contest: Codeforces - Codeforces Global Round 7
// URL: https://codeforces.com/contest/1326/problem/D2
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

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        string str;
        cin >> str;
        
        int n = str.size();
        
        string beg;
        
        int i = 0;
        int j = n-1;
        while((i < j) && (str[i] == str[j])){
            beg.push_back(str[i]);
            i++, j--;
        }
        
        string nstr;
        while(i <= j){
            nstr.push_back(str[i++]);
        }
        
        // cout << beg << endl;
        // cout << nstr << endl;
        
        string tans;
        int m = nstr.size();
        
        for(int i = 0; i < 2; i++)
        {
            int cans = 0;
            
            int pre0 = 0;
            int pre1 = 0;
            int suf0 = 0;
            int suf1 = 0;
            
            lli p0 = 31;
            lli p1 = 53;
            lli np0 = 1;
            lli np1 = 1;
            
            lli mod0 = 1e9 + 9;
            lli mod1 = 1e9 + 7;
            
            for(int i = 0; i < m; i++){
                
                pre0 = (pre0 * p0) % mod0;
                pre0 = (pre0 + (nstr[i] - 'a' +1)) % mod0;
                suf0 = (suf0 + np0 * (nstr[i] - 'a' +1)) % mod0;
                np0 = (np0 * p0) % mod0;
                
                pre1 = (pre1 * p1) % mod1;
                pre1 = (pre1 + (nstr[i] - 'a' +1)) % mod1;
                suf1 = (suf1 + np1 * (nstr[i] - 'a' +1)) % mod1;
                np1 = (np1 * p1) % mod1;
                
                if(pre0 == suf0 && pre1 == suf1){
                    cans = max(cans, i+1);
                }
            }
            
            if(cans > tans.size())
                tans = nstr.substr(0, cans);
                
            if(!i) reverse(nstr.begin(), nstr.end());
        }
        
        string tot;
        tot += beg;
        tot += tans;
        reverse(beg.begin(), beg.end());
        tot += beg;
        
        cout << tot << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    