#include<bits/stdc++.h>
using namespace std;

int c[26];
int main(){
    int n,l,x,r;

    cin>>n>>l>>r>>x;

    for(int i = 0 ; i < n ; i ++){
        cin>>c[i];
    }
    int sm , mn , mx , cnt;
    int ans = 0;
    for(int msk = 0 ; msk < (1<<n) ; msk++){

		sm = mx = cnt  = 0;
        mn = 10000000;
        for(int j = 0 ; j < n ; j++){
            if( msk&(1<<j) ){
                sm+=c[j];
				cnt++;
                mx = max(mx,c[j]);
                mn = min(mn,c[j]);
            }
        }

        if(sm<=r && sm>=l && mx-mn >=x){
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}