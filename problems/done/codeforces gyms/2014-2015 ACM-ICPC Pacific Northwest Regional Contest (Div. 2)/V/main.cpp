#include <bits/stdc++.h>

using namespace std;

#define ll long long

int dp[205][205][8];
int vec[2][2];

int DP(int a,int b,int msk){
    if(!a)return msk&1;
    if(dp[a][b][msk]+1)return dp[a][b][msk];
    bool res=!(msk&1);
    if(msk&1){
        if(b)res|=DP(a,b-1,msk^1);
        if((msk&6) == 6)res|=DP(a-1,b,msk^1);
        if(!(msk&6))res|=(DP(a-1,b+vec[0][0],msk^3)|DP(a-1,b+vec[0][1],msk^5));
        if((msk&6)==2){
            res|=DP(a-1,b+vec[0][1],msk^5);
            if(a>vec[1][1])res|=DP(a-1,b,msk^1);
        }
        if((msk&6)==4){
            res|=DP(a-1,b+vec[0][0],msk^3);
            if(a>vec[1][0])res|=DP(a-1,b,msk^1);
        }
    }else{
        if(b)res&=DP(a,b-1,msk^1);
        if((msk&6) == 6)res&=DP(a-1,b,msk^1);
        if(!(msk&6))res&=(DP(a-1,b+vec[0][0],msk^3)&DP(a-1,b+vec[0][1],msk^5));
        if((msk&6)==2){
            res&=DP(a-1,b+vec[0][1],msk^5);
            if(a>vec[1][1])res&=DP(a-1,b,msk^1);
        }
        if((msk&6)==4){
            res&=DP(a-1,b+vec[0][0],msk^3);
            if(a>vec[1][0])res&=DP(a-1,b,msk^1);
        }
    }
    return dp[a][b][msk]=res;
}

int solve(){

    int n;cin>>n;
    vector<ll>v(n);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            vec[i][j]=0;
        }
    }
    int idx=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==1)idx=i;
    }
    bool f=1;
    int b=n-1;
    for(int i=idx+1;i<n;i++){
        if(f&&v[i]<v[i-1]){
            f=0;
        }
        if(!f&&v[i]>v[i-1]){
            break;
        }
        b--;
        vec[f][1]++;
    }
    f=1;
    for(int i=idx-1;i>=0;i--){
        if(f&&v[i]<v[i+1]){
            f=0;
        }
        if(!f&&v[i]>v[i+1]){
            break;
        }
        b--;
        vec[f][0]++;
    }

    memset(dp,-1,sizeof(dp));

    int a=vec[1][0]+vec[1][1];
    if(DP(a,b,1))cout<<"Alice\n";
    else cout<<"Bob\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
