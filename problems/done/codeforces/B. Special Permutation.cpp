// Problem: B. Special Permutation
// Contest: Codeforces - 2021-2022 ICPC, NERC, Southern and Volga Russian Regional Contest (problems intersect with Educational Codeforces Round 117)
// URL: https://codeforces.com/gym/103430/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include <bits/stdc++.h>

#define vi vector<int>

using namespace std;

int main()
{

    int n, t, a, b;
    cin>>t;
    while(t--)
    {
    	
        cin>>n>>a>>b;
        
        {
        	
        	vi tmp;
        	for(int i = 1; i <= n; i++){
        		if(i==a || i==b){
        			continue;
        		}
        		else{
        			tmp.push_back(i);
        		}
        	}
        	
        	vi va, vb;
        	va.push_back(a);
        	vb.push_back(b);
        	
        	while(!tmp.empty() && tmp.back() > a && va.size() < n/2){
        		va.push_back(tmp.back());
        		tmp.pop_back();
        	}
        	
        	while(!tmp.empty() && tmp.back() < b){
        		vb.push_back(tmp.back());
        		tmp.pop_back();
        	}
        	
        	if(!tmp.empty() || (va.size()!=vb.size())){
        		cout << -1 << endl;
        		continue;
        	}
        	
        	for(auto i : va) cout << i << ' ';
        	for(auto i : vb) cout << i << ' ';
        	cout << endl;
        }
    }


    return 0;
}