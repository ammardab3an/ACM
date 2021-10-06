// Problem: D. Number into Sequence
// Contest: Codeforces - Codeforces Round #686 (Div. 3)
// URL: https://codeforces.com/contest/1454/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

vector<pair<int, int> > primeFactors(int n) 
{ 

	vector<pair<int, int> > ret;
	ret.push_back({1, 1});

    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    
    for (int i = 2; (double)i <= (double)n/(double)i; i++) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
        	if(ret.back().first == i) ret.back().second++;
			else ret.push_back({i, 1});
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 1) 
		ret.push_back({n, 1});
		
	return ret;
} 


int32_t main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
				
		int n; cin >> n;
		vector<pair<int, int> > fac = primeFactors(n);
		fac.erase(fac.begin());
		
		auto comp = [](pair<int, int> p0, pair<int, int> p1){
			return p0.second > p1.second;	
		};
		
		sort(fac.begin(), fac.end(), comp);
		
//		for(auto i : fac) cout << i.first << ' ' << i.second << endl;; 
//		cout << '-' << endl;
		
		int l = 1;
		int r = fac.front().second;
		
		vector<int> ans = {n};
		
		while(l <= r){
			
			int m = (l+r)/2;
			
			if(fac.front().second < m){
				r = m-1;
				break;
			}	
			
			vector<int> tmp(m, 1);
			
			for(auto p : fac){
				
				int f = p.first;
				int c = p.second;
				
				while(c) 
				for(int i = m-1; i >= 0 && c; i--){
					tmp[i] *= f;
					c--;
				}
			}
			
			ans = tmp;
			
			l = m+1;
		}
		
		cout << ans.size() << endl;
		for(auto i : ans) cout << i << ' '; cout << endl;
    }	
}
