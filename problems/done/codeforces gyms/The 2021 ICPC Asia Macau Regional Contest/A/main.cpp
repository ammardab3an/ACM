#include <bits/stdc++.h>

using namespace std;

int a[100][100];

int solve(){
    int n;cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++){
        vector<int>vv;
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            vv.emplace_back(a[i][j]);
        }
        if(i%2)reverse(vv.begin(),vv.end());
        for(auto x:vv)res.emplace_back(x);
    }
    int cnt1=0,cnt2=0;
    for(int i=1;i<res.size();i++){
        if(res[i]>res[i-1])cnt1++;
        else cnt2++;
    }
    if(cnt1>cnt2){
            reverse(res.begin(),res.end());
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i+1<res.size())cout<<" ";
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;cin>>t;
    while(t--){
            solve();
        if(t)cout<<'\n';
    }
    return 0;
}
