// Contest: Codeforces - Codeforces Beta Round #98 (Div. 2)
// Problem: D. Palindromes
// URL: https://codeforces.com/problemset/problem/137/D
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

int n, kk;
char str[555];
int good[555][555];
int mem[555][555];

int go(int i, int k){
    
    if(i == n) return 0;
    if(!k) return INF;
    
    int &ret = mem[i][k];
    if(ret+1) return ret;
    
    int ans = INF;
    
    for(int j = i; j < n; j++){
        ans = min(ans, go(j+1, k-1)+good[i][j]);
    }
    
    return ret = ans;
}

void calc(int i, int k){
    
    if(i == n){
        cout << endl;
        return;
    }
    
    int ans = go(i, k);
    
    for(int j = i; j < n; j++){
        
        if(ans == go(j+1, k-1)+good[i][j]){
            
            int l = i;
            int r = j;
            
            string tmp;
            while(l < r){
                tmp.push_back(str[l]);
                l++, r--;
            }
            
            string rev = tmp;
            reverse(rev.begin(), rev.end());
            
            if(l!=r) tmp = tmp + rev;
            else tmp = tmp + string(1, str[l]) + rev;
            
            if(k!=kk) cout << '+';
            cout << tmp;
            
            calc(j+1, k-1);
            return;
        }
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> str;
    n = strlen(str);
    
    int k;
    cin >> k;
    
    kk = k;
    
    for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++){
        
        int l = i;
        int r = j;
        
        int cnt = 0;
        
        while(l < r){
            cnt += str[l] != str[r];
            l++, r--;
        }    
        
        good[i][j] = cnt;
    }
    
    memset(mem, -1, sizeof mem);
    
    cout << go(0, k) << endl;
    calc(0, k);
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
