// Problem: Increasing Substring
// Contest: Google Coding Competitions - Round B 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a882
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

lli nxt(lli num){
    
    lli cur = num;
    for(; ; cur++){
        
        bool isPrime = true;
        
        for(lli i = 2; i*i <= cur; i++) if(cur%i==0){
            isPrime = false;
            break;
        }
        
        if(isPrime) return cur;
    }    
}

lli get(lli num){
    
    lli cur = num;
    for(; ; cur--){
        
        bool isPrime = true;
        
        for(lli i = 2; i*i <= cur; i++) if(cur%i==0){
            isPrime = false;
            break;
        }
        
        if(isPrime) return cur;
    }    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int tt = 1;
    int t; cin >> t; while(t--){

        lli num;
        cin >> num;
        
        lli p0 = nxt(2*sqrt(num));
        lli p1 = get(p0-1);
        
        while(p0 * p1 > num){
            p0 = p1;
            p1 = get(p0-1);
        }
        
        // cout << p0 << ' ' << p1 << endl;
        
        cout << "Case #" << tt++ << ": ";
        cout << p0 * p1 << endl;        
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
