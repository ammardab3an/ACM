// x_factor double
// Problem: E. Gosha is hunting

#include "bits/stdc++.h"

pair<double, int> merge(const pair<double, int> &a, const pair<double, int> &b){
	if(abs(a.first-b.first) < 1e-6){
		return a.second < b.second ? a : b;
	}	
	else{
		return a.first > b.first ? a : b;
	}
}

int32_t main(){
  
	int n, a, b;
	cin >> n >> a >> b;
	
	vector<vector<double>> vec(2, vector<double>(n));
	for(auto &v : vec) for(auto &i : v) cin >> i;
	
	auto calc = [&](double x_factor){
		
		vector<pair<double, int>> dp(a+1);
		
		for(int i = 0; i < n; i++){
			
			vector<pair<double, int>> ndp(a+1, {-1e18, INF});
			
			double p = vec[0][i];
			double q = vec[1][i];
			double pq = 1.0 - (1.0-p)*(1.0-q);
			
			for(int j = 0; j <= a; j++){
				
				// dp[i][a] = max(
					// dp[i-1][a],
					// dp[i-1][a-1] + vec[0][i]
					// dp[i-1][a] + vec[1][i] - x_factor
					// dp[i-1][a-1] + (1 - (1-vec[0][i])*(1-vec[1][i])) - x_factor
				// )
				
				auto &cans = ndp[j];
				
				auto st_path = dp[j];
				auto nd_path = dp[j];
				nd_path.first += q - x_factor;
				nd_path.second += 1;
				
				cans = merge(cans, merge(st_path, nd_path));
				
				if(j){
					auto rd_path = dp[j-1];
					rd_path.first += p;
					auto th_path = dp[j-1];
					th_path.first += pq - x_factor;
					th_path.second += 1;
					cans = merge(cans, merge(rd_path, th_path));
				}
			}
			
			dp = ndp;
		}
		
		return dp.back();
	};
	
	double l = 0;
	double r = 1e9;
	
	double bs_ans = -1;
	
	int cnt = 100;
	while(cnt--){
		
		double mid = (l+r)/2;
		auto cans = calc(mid);
		
		if(cans.second <= b){
			bs_ans = mid;
			r = mid;
		}
		else{
			l = mid;
		}
	}
	
	double ans = calc(bs_ans).first + b*bs_ans;
	
	cout << fixed << setprecision(6) << ans << endl;
}
