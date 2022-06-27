#include<bits/stdc++.h>

#define int int64_t
#define endl '\n'

using namespace std;

typedef long double dt;

int32_t main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    dt d;
    cin >> n >> d;

    vector<int> vec(n);
    for(auto &i : vec) cin >> i;

    auto calc = [&](dt x)->bool{

        bool st_path = true;
        bool nd_path = true;

        {
            dt l = -1e30;
            dt r = +1e30;
            for(auto i : vec){
                dt nl = dt(i)-x;
                dt nr = dt(i)+x;
                l = max(l+d, nl);
                r = min(r+d, nr);
                if(l > r){
                    st_path = false;
                    break;
                }
            }
        }
        {
            dt l = -1e30;
            dt r = +1e30;
            for(int _i = n-1; _i >= 0; _i--){
                int i = vec[_i];
                dt nl = dt(i)-x;
                dt nr = dt(i)+x;
                l = max(l+d, nl);
                r = min(r+d, nr);
                if(l > r){
                    nd_path = false;
                    break;
                }
            }
        }

        return st_path || nd_path;
    };

    dt l = 0;
    dt r = 1e30;

    dt ans = r;

    for(int k = 0; k < 110; k++){

        dt mid = (l+r)/2.0;

        if(calc(mid)){
            ans = mid;
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout << fixed << setprecision(1) << ans << endl;
}
