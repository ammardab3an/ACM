#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    map<int, int> mp;
    for(int i = 0; i <= 13; i++){
        mp[i] = 4;
    }

    int a, b;
    cin >> a >> b;
    mp[a]--, mp[b]--;
    a = min(a, 10);
    b = min(b, 10);
    int sm0 = a+b;

    int c, d;
    cin >> c >> d;
    mp[c]--, mp[d]--;
    c = min(c, 10);
    d = min(d, 10);
    int sm1 = c+d;

    vector<int> vec(n);
    for(auto &i : vec) cin >> i;

    for(auto i : vec){
        mp[i]--;
        i = min(i, 10);
        sm0 += i;
        sm1 += i;
    }

    int ans = -1;

    for(auto [v, f] : mp) if(f){

        int nsm0 = sm0 + min(v, 10);
        int nsm1 = sm1 + min(v, 10);

        if(nsm1==23){
            ans = v;
            break;
        }
        else if(nsm1 < 23 && nsm0 > 23){
            ans = v;
            break;
        }
    }

    cout << ans << endl;
}
