#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

vector<int> factorize(int x){

    vector<int> ret;
    for(int i = 1; i*i <= x; i++) if(x%i==0){
        ret.push_back(i);
        if(x/i != i) ret.push_back(x/i);
    }

    return ret;
}

vector<int> common(vector<int> &v0, vector<int> &v1){

    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());

    vector<int> ret;

    int i = 0, j = 0;
    while(i < v0.size() && j < v1.size()){
        if(v0[i]==v1[j]){
            ret.push_back(v0[i]);
            i++, j++;
        }
        else if(v0[i] < v1[j]){
            i++;
        }
        else{
            j++;
        }
    }

    return ret;
}

signed main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t; while(t--){

        int w, h;
        cin >> w >> h;

        vector<int> fac_w = factorize(w);
        vector<int> fac_w1 = factorize(w-1);
        vector<int> fac_w2 = factorize(w-2);
        vector<int> fac_h = factorize(h);
        vector<int> fac_h1 = factorize(h-1);
        vector<int> fac_h2 = factorize(h-2);

        set<int> st;

        for(auto i : common(fac_w1, fac_h1)) st.insert(i);
        for(auto i : common(fac_w, fac_h2)) st.insert(i);
        for(auto i : common(fac_w2, fac_h)) st.insert(i);
        if(((w+h)*2-4)%2 == 0) st.insert(2);

        cout << st.size() << ' ';
        for(auto i : st) cout << i << ' ';
        cout << endl;
    }
}
