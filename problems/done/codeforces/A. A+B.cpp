// Problem: A. A+B
// Contest: Codeforces - day 5 (difficulty 1300-1500)
// URL: https://codeforces.com/group/dnGSMfvuuN/contest/294593/problem/A
// Memory Limit: 64 MB
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

    string a, b;
    cin >> a >> b;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    string sum;
    
    int rem = 0;
    
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()){
        rem += a[i++] - '0' + b[j++] - '0';
        sum.push_back('0' + rem%10);
        rem /= 10;
    }
    
    while(i < a.size()){
        rem += a[i++] - '0';
        sum.push_back('0' + rem%10);
        rem /= 10;
    }
    
    while(j < b.size()){
        rem += b[j++] - '0';
        sum.push_back('0' + rem%10);
        rem /= 10;
    }
    
    if(rem) sum.push_back('0' + rem);
    
    while(sum.back() == '0') sum.pop_back();
    
    reverse(sum.begin(), sum.end());
    
    cout << sum << endl;
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
