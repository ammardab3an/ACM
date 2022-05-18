#include<bits/stdc++.h>

using namespace std;

pair<int, int> dfs(int u, int p, vector<vector<int> > &adj){
    
    pair<int, int> ret = {0, u};
    
    for(auto v : adj[u]) if(v != p){
        pair<int, int> tmp = dfs(v, u, adj);
        tmp.first += 1;
        if(tmp.first > ret.first){
            ret = tmp;
        }
    }
	
	return ret;    
}

int maxWalk(vector<int> parent, int k){
    
    int n = parent.size()+1;
    vector<vector<int> > adj(n);
    for(int i = 0; i < parent.size(); i++){
        adj[i+1].push_back(parent[i]);
        adj[parent[i]].push_back(i+1);
    }
    
    pair<int, int> node_0 = dfs(0, -1, adj);
    pair<int, int> node_1 = dfs(node_0.second, -1, adj);
    
    int di = node_1.first;
    
    int ans = 0;
    
    if(k <= di){
		ans = k+1;
	}
	else{
		ans = di+1;
		int rem_k = k-di;
		int rem_e = (n-1) - di;
		ans += min(rem_e, rem_k/2);
	}
    
    return ans;
}

int main(){
    int M;
    cin>>M;
    vector<int> parent(M);
    for(int j = 0;j < M;j++){
        cin>>parent[j];
    }
    int K;
    cin>>K;
    int result;
    result = maxWalk(parent,K);
    cout<<result;
    return 0;
}