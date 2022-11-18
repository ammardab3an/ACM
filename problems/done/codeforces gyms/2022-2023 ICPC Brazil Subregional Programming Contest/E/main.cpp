#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> vec(n);
    for(auto &i : vec) cin >> i;

    int ans = 0;

    multiset<int> st;
    for(auto i : vec){

        auto it = st.find(i+1);
        if(it != st.end()){
            st.erase(it);
            st.insert(i);
        }
        else{
            ans++;
            st.insert(i);
        }
    }

    cout << ans << endl;
}
