#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>>v;


void check(int last,int lastlast,int cur){

}


int solve(){
    cin>>n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        v.emplace_back(x,y);
    }
    if(n<3)return cout<<0<<'\n',0;
    sort(v.begin(),v.end());
    vector<int>st;
    st.push_back(0);
    st.push_back(1);
    for(int i=2;i<n;i++){

    }
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
