// Problem: A. Tokitsukaze and Strange Inequality
// Contest: Codeforces - Codeforces Round 789 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1677/A
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int t; cin >> t; while(t--){
        
        int n;
        cin >> n;
        
        vector<int> vec(n);
        for(auto &i : vec) cin >> i, --i;
        
        vector<vector<int>> pre(n, vector<int>(n));
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            
            if(j){
                pre[i][j] = pre[i][j-1];
            }
            
            if(vec[j]==i){
                pre[i][j] += 1;
            }
        }
        
        for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++){
            pre[i][j] += pre[i-1][j];
        }
        
        auto query_pre = [&](int i, int v){
            if(v < 0) return 0;
            return pre[v][i];
        };
        
        
        vector<vector<int>> suf(n, vector<int>(n));
        
        for(int i = 0; i < n; i++)
        for(int j = n-1; j >= 0; j--){
            
            if(j+1 < n){
                suf[i][j] = suf[i][j+1];
            }    
            
            if(vec[j] == i){
                suf[i][j] += 1;
            }
        }
        
        for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++){
            suf[i][j] += suf[i-1][j];
        }
        
        // for(int i = 0; i < n; i++){
            // for(int j = 0; j < n; j++){
//                 
            // }
        // }
        
        auto query_suf = [&](int i, int v){
            if(v < 0) return 0;
            return suf[v][i];
        };
        
        int64_t ans = 0;
        
        for(int i = 1; i < n; i++)
        for(int j = i+1; j+1 < n; j++){
            
            // p > j && vec[p] < vec[i]
            // p < i && vec[p] < vec[j]
            
            int st_path = query_suf(j+1, vec[i]-1);
            int nd_path = query_pre(i-1, vec[j]-1);
            
            ans += st_path *1ll* nd_path;
        }
        
        cout << ans << endl;
    }
}