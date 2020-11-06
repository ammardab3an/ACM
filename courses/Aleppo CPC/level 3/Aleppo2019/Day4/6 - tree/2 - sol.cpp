#include <bits/stdc++.h>

using namespace std;


int n , m ;

vector <int> adj[110000];
int cat[110000];
bool vis[110000]={0};

int f(int pos , int sum){

vis[pos]=1;

if(sum > m)return 0;
int s=0;

if( adj[pos].size()==1 && pos!=1 )return 1;

if( cat[pos]==0 )sum=0;

for(int i=0;i<adj[pos].size();i++)
    if( vis[ adj[pos][i] ]==0 )
s+=(f( adj[pos][i] , sum+(int)cat[ adj[pos][i] ] )  );

return s;
}

int main()
{
cin>>n>>m;

for(int i=1;i<=n;i++)
    cin>>cat[i];

    int a,b ;

for(int i=1;i<n;i++)
{

   cin>>a>>b;
   adj[a].push_back(b);
   adj[b].push_back(a);

}
cout<<f(1,cat[1])<<endl;

    return 0;
}