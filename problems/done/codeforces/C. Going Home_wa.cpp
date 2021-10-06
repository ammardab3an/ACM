// because it's was a great idea, it deserves to be submited.

// Problem: C. Going Home
// Contest: Codeforces - Codeforces Round #707 (Div. 2, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1501/problem/C
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
const int SMAX = 250 + 10; // memory limit of nearly 65 gigs for the right size of 2500000

int n;
int arr[NMAX];
bitset<SMAX> bs[NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
        
    sort(arr, arr+n);
    
    for(int i = 0; i < n; i++){
        bs[0].set(arr[i], true);
    }
    
    for(int i = 0; i < n; i++){
        bs[i+1] = bs[0];
        bs[i+1] <<= arr[i];
    }
    
    int found = -1;
    
    bs[n+1] = bs[n];
    
    for(int i = n-1; i > 0; i--){
        
        if((bs[i] & bs[n+1]).any()){
            
            found = i;
            break;
        }
        
        bs[n+1] |= bs[i];
    }
    
    if(found == -1){
        cout << "NO" << endl;
        return 0;
    }
    
    int idx0 = found;
    int idx1 = -1;
    
    // this is just stupid
    for(int i = idx0+1; i <= n; i++){
        if((bs[idx0] & bs[i]).any()){
            
            idx1 = i;
            break;
        }
    }
    
    assert(idx1+1);
    
    int x = 0, y = 0;
    for(int i = 2; i < SMAX; i++){
        
        bool t0 = bs[idx0].test(i);
        bool t1 = bs[idx1].test(i);
        
        x += t0; // freq[i] instead of t0, because it's possible to exists multilple elements with the same value
        y += t1;
            
        if(t0 && t1){
        
            cout << "YES" << endl;
            cout << idx0 << ' ' << x+1 << ' ' << idx1 << ' ' << y+1 << endl;
            return 0;
        }
    }
}
