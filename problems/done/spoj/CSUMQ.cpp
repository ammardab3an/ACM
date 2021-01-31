// Problem: Cumulative Sum Query
// Contest: SPOJ - Tutorial
// URL: https://www.spoj.com/problems/CSUMQ/
// Memory Limit: 1536 MB
// Time Limit: 7000 ms
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

    int n;
    cin >> n;
    
    vector<int> vec(n);
    for(int &i : vec) cin >> i;
    
    int block = ceil(sqrt(double(n)));

    vector<int> pAns(block, 0);
    for(int i = 0; i < n; i++){
    	pAns[i/block] += vec[i];
    }
    
    int q; cin >> q; while(q--){
    	
    	int l, r;
    	cin >> l >> r;
    	
    	int cans = 0;
    	
    	for(int i = l; i <= r; i++){
    		
    		if(i%block == 0 && (i+block) <= r){
    			cans += pAns[i/block];
    			i += block-1;
    		}
    		else{
				cans += vec[i];
    		}
    	}
    	
    	cout << cans << endl;
    }	
}
