// dp_schoelace
// B. Bars
// https://qoj.ac/problem/5500

// By AmmarDab3an 

#include "bits/stdc++.h"

int32_t main(){

    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		vi vec(n);
		for(auto &i : vec) cin >> i;
		
		vpii tmp;
		tmp.push_back({0, 0});
		
		// dp[i] = max(dp[j] + (pi+pj)*(i-j))
		// dp[i] = max(dp[j] + pi*i + pj*j - pi*j - pj*j)
		// dp[i] = pi*i + max((dp[j]-pj*j) + pj*i - pi*j )
		
		// ans = sum((pi+pj) * (i-j))
		// Shoelace Formula
		
		auto calc = [&](const pii &a, const pii &b){
			return a.first*b.second - b.first*a.second;
		};
		
		for(int i = 0; i <= n; i++){
			
			pii cur = i < n ? (pii){vec[i], i} : (pii){0, n-1};
			
			while(tmp.size() >= 2){
				
				pii a = tmp[tmp.size()-2];
				pii b = tmp[tmp.size()-1];
				pii c = cur;
				
				if(calc(a, b) + calc(b, c) <= calc(a, c)){
					tmp.pop_back();
				}
				else{
					break;
				}
			}
			
			tmp.push_back(cur);
		}
		
		int ans = 0;
		for(int i = 1; i < tmp.size(); i++){
			ans += calc(tmp[i-1], tmp[i]);
		}
		
		cout << ans << endl;
    }	
}
