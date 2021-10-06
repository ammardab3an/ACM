// Problem: E. Holes
// Contest: Codeforces - Codeforces Beta Round #13
// URL: https://codeforces.com/contest/13/problem/E
// Memory Limit: 64 MB
// Time Limit: 1000 ms
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

int n, m, blockSz;
int arr[NMAX];
int nxt[NMAX];
int cnt[NMAX];
int fst[NMAX];

pii go(int idx, int blockIdx){
	
	if(fst[idx] != blockIdx) return {idx, 0};
	
	if(idx + arr[idx] >= n) return {idx, 0};
	
	if(cnt[idx]){
		return {nxt[idx], cnt[idx]};
	}
	
	pii tmp = go(idx + arr[idx], blockIdx);
	
	return {tmp.first, tmp.second + 1};
}

pii get(int idx){
	
	if(nxt[idx] == idx) return {idx, cnt[idx]};
	
	pii tmp = get(nxt[idx]);
	
	return {tmp.first, tmp.second + cnt[idx]};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    blockSz = sqrt(n);
	for(int i = 0; i < n+10; i++) fst[i] = i/blockSz;
    
    for(int i = n-1; i >= 0; i--) {
    	auto tmp = go(i, fst[i]);
    	nxt[i] = tmp.first;
    	cnt[i] = tmp.second;
    }
    
   // for(int i = 0; i < n; i++) cout << nxt[i] << ' ' << cnt[i] << endl;

	for(int i = 0; i < m; i++){
		
		int k, a, b;
		cin >> k >> a; a--;
		if(!k) cin >> b;
		
		if(k){
			auto tmp = get(a);
			cout << tmp.first+1 << ' ' << tmp.second+1 << endl;
		}
		else{
			arr[a] = b;
			
			int blockIdx = fst[a];
			
			for(int i = a; (i >= 0) && (fst[i] == blockIdx); i--){
				cnt[i] = 0;
				auto tmp = go(i, blockIdx);
				nxt[i] = tmp.first;
				cnt[i] = tmp.second;
			}
		}
	}
}
