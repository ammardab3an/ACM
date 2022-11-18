#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

typedef long double dt;

signed main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


    vector<string> cur = {"N", "E", "S","W"};

    while(true){

        vector<string> nxt;
        for(int i = 0; i < cur.size(); i++){
            nxt.push_back(cur[i]);
            nxt.push_back(cur[i] + cur[(i+1)%cur.size()]);
        }

        swap(cur, nxt);

        if(cur.back().size() >= 1000) break;
        cout << cur.size() << ' ' << cur.back().size() << endl << flush;
    }

    cout << cur.size() << endl;

    string str_frm, str_to;
    cin >> str_frm >> str_to;

}
