// Problem: B. The least round way
// Contest: Codeforces - Codeforces Beta Round #2
// URL: https://codeforces.com/contest/2/problem/B?outsideGroup=true
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

int n;
int grid[1010][1010][2];
int mem[1010][1010][2];

int go(int i, int j, int mod){
    
    if(i == n-1 && j == n-1) 
        return grid[i][j][mod];
    
    int &ret = mem[i][j][mod];
    if(ret + 1) return ret;
    
    int ans = INF;
    
    if(i+1 < n) ans = min(ans, go(i+1, j, mod) + grid[i][j][mod]);
    if(j+1 < n) ans = min(ans, go(i, j+1, mod) + grid[i][j][mod]);
    
    return ret = ans;
}

string calc(int i, int j, int mod){
    
    if(i == n-1 && j == n-1) return "";
    
    int ans = go(i, j, mod);
    
    int stPath = INF, ndPath = INF;
    
    if(i+1 < n) stPath = go(i+1, j, mod);
    if(j+1 < n) ndPath = go(i, j+1, mod);
    
    if(stPath < ndPath) return "D" + calc(i+1, j, mod);
    else return "R" + calc(i, j+1, mod);
}
    
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int ZERO = 0;
    int z_i, z_j;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        int aij;
        cin >> aij;
        if(!aij){
            ZERO = 1, z_i = i, z_j = j;
            grid[i][j][0] = grid[i][j][1] = 1;
        }
        else{
            while(aij%2==0) grid[i][j][0]++, aij/=2;
            while(aij%5==0) grid[i][j][1]++, aij/=5;
        }
    }
    
    memset(mem, -1, sizeof mem);
    
    int stAns = go(0, 0, 0);
    int ndAns = go(0, 0, 1);
    
    if(!stAns){
        string stPath = calc(0, 0, 0);
        cout << stAns << endl << stPath << endl;
    }
    else if(!ndAns){
        string ndPath = calc(0, 0, 1);
        cout << ndAns << endl << ndPath << endl;
    }
    else if(ZERO){
        int ans = 1;
        string path;
        int r_i = n - z_i -1;
        int r_j = n - z_j -1;
        while(z_i--) path += "D";
        while(z_j--) path += "R";
        while(r_i--) path += "D";
        while(r_j--) path += "R";
        cout << ans << endl << path << endl;
    }
    else if(stAns < ndAns){
        string stPath = calc(0, 0, 0);
        cout << stAns << endl << stPath << endl;
    }
    else{
        string ndPath = calc(0, 0, 1);
        cout << ndAns << endl << ndPath << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
