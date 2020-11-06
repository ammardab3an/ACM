#include <bits/stdc++.h>

using namespace std;

long long Mask[30];
int n , m;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(int j=0;j<n;j++){
        int k;
        cin>>k;
        while(k--){
            int x;
            cin>>x;
            x--;
            Mask[j] |= (1ll<<x);
        }
    }
    vector < int > sol;
    int mxmask=(1<<n) , ans = 1234;
    for(int mask = 0 ; mask < mxmask ; mask++){
        long long curmask = 0;
        for(int bit = 0 ; bit < n ; bit++){
            if( (mask & (1<<bit)))
                curmask |= Mask[bit];
        }
        if(__builtin_popcountll(curmask) == m){
            int sz = __builtin_popcount(mask);
            if(sz < ans){
                ans = sz;
                sol.clear();
                for(int bit = 0 ; bit < n ; bit++)
                    if( (mask & (1<<bit)))
                        sol.push_back(bit + 1);
            }
        }
    //      cout<<endl;
    }
    cout<<sol.size()<<endl;
    for(auto pp : sol) cout<<pp<<' ';
}