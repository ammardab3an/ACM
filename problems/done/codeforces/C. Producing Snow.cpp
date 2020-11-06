
// Problem : C. Producing Snow
// Contest : Codeforces - Codeforces Round #470 (rated, Div. 2, based on VK Cup 2018 Round 1)
// URL : https://codeforces.com/contest/948/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef unsigned int		uint;
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

//#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 10;

int n;
int piles[MAX];
int temps[MAX];

lli sma[MAX];
int tmp[MAX];
lli lst[MAX];

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
    
	cin >> n;
	for(int i = 0; i < n; i++) cin >> piles[i];
	for(int i = 0; i < n; i++) cin >> temps[i];
	
	sma[0] = temps[0];
	for(int i = 1; i < n; i++) sma[i] = sma[i-1] + temps[i];
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		
		int pile_v = piles[i];
		
		int l = i;
		int r = n-1;
		int ans = -1;
		
		while(l <= r){
			
			int m = (l+r)/2;
			
			lli sma_t = sma[m];
			if(i) sma_t -= sma[i-1];
			
			if(sma_t >= pile_v){
				ans = m;
				r = m-1;
			}
			else{
				l = m+1;	
			}
		}
		
		if(ans + 1){
			tmp[ans]++;
			lli rem = sma[ans-1];
			if(i) rem -= sma[i-1];
			lst[ans] += pile_v - rem;	
		}
		
		cnt += tmp[i];
		
		cout << (lli)(i+1-cnt) * temps[i] + lst[i] << ' ';
	}
	
}
