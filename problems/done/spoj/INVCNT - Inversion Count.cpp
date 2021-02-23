// Problem: Inversion Count
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/INVCNT/en/
// Memory Limit: 1536 MB
// Time Limit: 3599 ms
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
int arr[NMAX];
int tmp[NMAX];

lli merge(int l, int mid, int r){
    
    int i = l;
    int j = mid+1;
    int k = 0;
    
    lli cnt = 0;
    
    while((i <= mid) && (j <= r)){
        if(arr[i] < arr[j]){ // arr[i] != arr[j]
            tmp[k++] = arr[i++];
        }
        else{
            tmp[k++] = arr[j++];
            cnt += mid - i + 1;
        }
    }
    
    while(i <= mid) tmp[k++] = arr[i++];
    while(j <=  r ) tmp[k++] = arr[j++];
    
    for(int i = l, j = 0; i <= r; i++, j++)
        arr[i] = tmp[j];
        
    return cnt;
}

lli go(int l, int r){
    
    if(l >= r) return 0;
    
    lli cnt = 0;
    
    int mid = (l+r)/2;
    
    cnt += go(l, mid);
    cnt += go(mid+1, r);    
    
    cnt += merge(l, mid, r);
    
    return cnt;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        cout << go(0, n-1) << endl;
    }	
}
