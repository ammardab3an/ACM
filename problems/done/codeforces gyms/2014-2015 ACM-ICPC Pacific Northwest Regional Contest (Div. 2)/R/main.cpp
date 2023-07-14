#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

string num;
int mem[111][2][11];

int go(int i, bool b, int lst){

    if(i==num.size()){
        return 1;
    }

    int &ret = mem[i][b][lst];
    if(ret+1) return ret;

    int ans = 0;
    int mn = lst;
    int mx = b ? 9 : (num[i]-'0');

    for(int j = mn; j <= mx; j++){
        int cans = go(i+1, b || (j < mx), j);
        ans += cans;
    }

    return ret = ans;
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t; while(t--){

        cin >> num;

        bool good = true;
        for(int i = 1; i < num.size(); i++){
            if(num[i] < num[i-1]){
                good = false;
                break;
            }
        }

        if(!good){
            cout << -1 << endl;
            continue;
        }

        memset(mem, -1, sizeof mem);

        int ans = go(0, 0, 0)-1;
        cout << ans << endl;
    }
}
