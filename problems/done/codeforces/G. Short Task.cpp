// Problem: G. Short Task
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/G
// Memory Limit: 512 MB
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


const int N = 1e7 + 10;
int pp[N], prv[N];

vector<int> pr;

lli fast_pow(lli x, lli y, lli p) {
    if(!y) return 1;
    if(y&1) return (x * fast_pow(x, y-1, p)) % p;
    lli tmp = fast_pow(x, y/2, p);
    return (tmp * tmp) %p;
}

lli fast_pow(lli x, lli y) {
    return fast_pow(x, y, INFLL);
}

int main () {

for (int i=2; i<=N; ++i) {
    
    pp[1] = 1;
    
    if (pp[i] == 0) {
        pr.emplace_back(i);
        pp[i] = i;
    }
    
    for (int j=0; j < pr.size() && pr[j]<=pp[i] && i*pr[j]<=N; ++j)
        pp[i * pr[j]] = pr[j];
    }
    
    memset(prv, -1, sizeof prv);
    
    prv[1] =1;
    for (int i=2;i<N;i++){
        
        int s = 1, z = pp[i], zzz = i;
        
        while (zzz != 1) {
            
            int cnt = 0;
            while (zzz % z == 0) cnt++, zzz/=z;
            s *= (fast_pow(z, cnt + 1) - 1) / (z - 1);
            z = pp[zzz];
        }
        if (s < N && s > 0){
            if (prv[s] == -1)
                prv[s] = i;
        }
    }
    
    int t; cin >> t; while (t--){
        int n;
        cin >> n;
        cout << prv[n] << ' ';
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
