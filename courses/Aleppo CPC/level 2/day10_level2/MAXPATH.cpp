#include<bits/stdc++.h>
using namespace std;

const int N=1000;

int n,m;
int a[N][N];
long long mem[N][N];

int dp(int i,int j){
    if(i == n-1 && j == m-1)
        return a[i][j];

    if(mem[i][j] != -1)
        return mem[i][j];

    int path1=0 , path2=0;

    if(i < n-1) path1=a[i][j]+dp(i+1,j);
    if(j < m-1) path2=a[i][j]+dp(i,j+1);

    return mem[i][j]=max(path1,path2);
}

int main()
{

    cin>>n>>m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>a[i][j];
        }
    }

    memset(mem,-1,sizeof mem);
    long long ans=dp(0,0);
    cout<<ans<<endl;
}
