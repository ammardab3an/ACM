// Problem: G. Maximum Product
// Contest: Codeforces - 2015-2016 Petrozavodsk Winter Training Camp, Saratov SU Contest
// URL: https://codeforces.com/gym/100886/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s[2];
ll dp[25][2][2][2];

ll solve(int pos, int f1, int f2, int f3){
	
    if(pos == s[0].length()){
        if(f3 == 0) return 0;
        return 1;
    }
    
    ll &ret = dp[pos][f1][f2][f3];
    if(ret+1) return ret;
    
    ll res = 0;

    int l = s[0][pos] - '0', r = s[1][pos] - '0';
    
    for(int i = 0; i <= 9; i++){

        if(i < l && f2 == 0) continue;
        if(i > r && f1 == 0) continue;

        ll i1 = i;
        
        if(f3 == 0 && i1 == 0) i1 = 1;
        
        ll cur = i1 * solve(pos+1, 
        					i < r ? 1 : f1, 
        					i > l ? 1 : f2, 
        					i == 0 ? f3 : 1);
        
        res = max(res, cur);
    }

    return ret = res;
}

string build(int pos, int f1, int f2, int f3){
	
    if(pos == s[0].length()) return "";

    ll ans = solve(pos, f1, f2, f3);
    
    int l = s[0][pos] - '0', r = s[1][pos] - '0';
    
    for(int i = 0; i <= 9; i++){
    	
        if(i < l && f2 == 0) continue;
        if(i > r && f1 == 0) continue;

        ll i1 = i;
        if(f3 == 0 && i1 == 0) i1 = 1;
        ll cur = i1 * solve(pos+1, i < r ? 1 : f1, i > l ? 1 : f2, i == 0 ? f3 : 1);

        if(cur == ans){
            string res(1, i+'0');
            return res + build(pos+1, i < r ? 1 : f1, i > l ? 1 : f2, i == 0 ? f3 : 1);
        }

    }

    assert(false);
}

int main()
{

	cin >> s[0] >> s[1];

	reverse(s[0].begin(), s[0].end());
	while(s[0].size() < s[1].size()) s[0].push_back('0');
	reverse(s[0].begin(), s[0].end());
	
    memset(dp, -1, sizeof dp);
    
    string res = build(0, 0, 0, 0);

	reverse(res.begin(), res.end());
	while(res.size() && res.back()=='0') res.pop_back();
	reverse(res.begin(), res.end());

    cout << res << endl;
}