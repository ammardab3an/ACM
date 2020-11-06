#include<bits/stdc++.h>

using namespace std;

const int N = 101000;
const int L = 17;
vector<int>v[N];
int fa[N][L], dep[N] , par[N];
int n , m ;

void dfs(int u){
	for(auto x:v[u]){
		fa[x][0]=u;
		dep[x]=1+dep[u];
		dfs(x);
	}
}

int lca(int u, int v){
	if(dep[u] > dep[v])	swap(u, v);
	for(int i=L-1; i>=0; i--){
		if(dep[v]-dep[u] >> i & 1){
			v = fa[v][i];
		}
	}

	if(v == u)	return u;
	for(int i=L-1; i>=0; i--){
		if(fa[u][i] != fa[v][i]){
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}


int main(){

    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){

		for(int i=0;i<N;i++)v[i].clear();
		for(int i=0; i<L; i++)	fa[1][i] = -1;

		cin>>n;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			while( x-- ){
				int d;cin>>d;
				v[i].push_back(d);
				par[d]=i;
			}
		}

		int root = 1;
		while( par[root] )root=par[root];
		fa[root][0]=0;
		dfs(root);
		
		for(int j=1;j<L;j++)
			for(int i=1;i<=n;i++)
					fa[i][j]=fa[ fa[i][j-1] ][j-1];
		
		cout<<"Case "<<tc<<":"<<endl;
		cin>>m;
		while(m--){
			int u , v ;
			cin>>u>>v;
			cout<<lca(u,v)<<endl;
		}

    }
	return 0;
}
