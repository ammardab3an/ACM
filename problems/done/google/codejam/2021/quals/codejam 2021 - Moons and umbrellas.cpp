// Problem: Moons and umbrellas
// Contest: Google Coding Competitions - Qualification Round 2021 - Code Jam 2021
// URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
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

int n, x, y;
char str[1010];
int mem[1010][26];

int calc(char a, char b){
    if(a == 'C' && b == 'J') return x;
    if(a == 'J' && b == 'C') return y;
    return 0;
}

int go(int pos, char lst){
    
    if(pos == n) return 0;
    
    int &ret = mem[pos][lst-'A'];
    if(ret + 1) return ret;
    
    if(str[pos] == 'X'){
        
        int ans = INF;
        
        ans = go(pos+1, 'C') + calc(lst, 'C');
        ans = min(ans, go(pos+1, 'J') + calc(lst, 'J'));
        
        return ret = ans;
    }
    else{
        int ans = go(pos+1, str[pos]) + calc(lst, str[pos]);
        return ret = ans;
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
        
        cin >> x >> y >> str;
        
        n = strlen(str);
        
        for(int i = 0; i < n; i++) if(str[i] == '?') str[i] = 'X';
        
        memset(mem, -1, sizeof mem);
        
        int ans = go(0, 'X');
        
        cout << "Case #" << tt++ << ": ";
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
