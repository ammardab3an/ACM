#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;cin>>n>>a>>b;
    int after=n-a-b,befor=b;
    map<int,int>mp;
    mp[a]++;
    int msk=0;
    if(!mp[after])mp[after]++,msk+=1;
    if(!mp[befor])mp[befor]++,msk+=2;
    if(msk==3)return cout<<0<<'\n',0;
    if(msk==2){
        int mn=after;
        for(int i=1;i<=after;i++){
            if(!mp[i])mn=min(mn,after-i);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(!mp[i]&&!mp[j]){
                    if(after>=i+j)mn=min(mn,after-i-j);
                    if(!mn)break;
                }
            }
        }
        if(!mp[1]&&!mp[2]&&!mp[3]&&after>=6)mn=after-6;
        return cout<<mn<<'\n',0;
    }else if(msk==1){
        int mn=befor;
        for(int i=1;i<=befor;i++){
            if(!mp[i])mn=min(mn,befor-i);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(!mp[i]&&!mp[j]){
                    if(befor>=i+j)mn=min(mn,befor-i-j);
                    if(!mn)break;
                }
            }
        }
        if(!mp[1]&&!mp[2]&&!mp[3]&&befor>=6)n(mn,mn=befor-6);
        return cout<<mn<<'\n',0;
    }else{
        if(a>=5)return cout<<0<<'\n',0;
        if(a==4)return cout<<2<<'\n',0;
        if(a==3)return cout<<3<<'\n',0;
        if(a==2)return cout<<3<<'\n',0;
        if(a==1)return cout<<2<<'\n',0;
    }
    return 0;
}
