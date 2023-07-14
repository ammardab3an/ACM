#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;cin>>t;
while(t--){
    int n;cin>>n;
    vector<string>v(n);
    map<string,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        string s;cin>>s;
        mp[s]=i;
    }
    int mx=-1;
    int last=-1;
    for(int i=0;i<n;i++){
        int cur=mp[v[i]];
        mx=max(mx,cur);
        if(mx==i){
            cout<<i-last<<" ";
            last=i;
        }
    }
    cout<<'\n';
}
    return 0;
}
