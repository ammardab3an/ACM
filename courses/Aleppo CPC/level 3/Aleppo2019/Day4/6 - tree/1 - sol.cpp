#include <bits/stdc++.h>

using namespace std;

vector< int > vec[3000];
int ans=-1;
int n ;
int p[3000];
int dis[3000];

void dfs(int x,int par=0,int dep=1){
dis[x]=dep;	

for(auto y:adj[x])
		if( y != par )
				dfs(y,x,dep+1);
}


int main(){

    cin>>n;

    for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        vec[p[i]].push_back(i);
        }


    int ans=-1;

    for(int i=1;i<=n;i++)
        if( p[i]==-1 )
           dfs(i);


    for(int i=1;i<=n;i++)
		ans=max(ans,dis[i]);

    cout<<ans<<endl;

    return 0;
}