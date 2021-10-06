// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

// Global Variables

multiset<lli> mst;
vector<lli>   ans;

bool dp(lli cur){

    if(mst.empty())
        return true;

    if(mst.find(cur*2) != mst.end()){

        mst.erase(mst.find(cur*2));

        if(dp(cur*2)){
            ans.push_back(cur*2);
            return true;
        }
        else
            mst.insert(cur*2);
    }

    if(cur % 3 == 0)
    if(mst.find(cur/3) != mst.end()){

        mst.erase(mst.find(cur/3));

        if(dp(cur/3)){
            ans.push_back(cur/3);
            return true;
        }
        else
            mst.insert(cur/3);
    }

    return false;
}

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        lli tmp;
        cin >> tmp;
        mst.insert(tmp);
    }


    for(lli nd : mst){

        mst.erase(mst.find(nd));

        if(dp(nd)){
            ans.push_back(nd);
            break;
        }
        else
            mst.insert(nd);
    }

    reverse(ans.begin(), ans.end());
    for(lli i : ans)
        cout << i << ' ';
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
