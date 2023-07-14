#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t; while(t--){

        string str;
        cin >> str;

        double d = stod(str);

        int i = int(d);
        d = d-i;

        if(d<1e-7){
            cout << i << '"' << endl;
            continue;
        }

        int len = 0;

        {
            bool b = 0;
            for(auto c : str){
                if(c=='.'){
                    b = true;
                }
                else if(b){
                    len++;
                }
            }
        }

//        cout << i << ' ' << d << ' ' << len << endl;

        int p10 = 1;
        while(len--){
            p10 *= 10;
        }

        auto check = [&](int a, int b){

            double nd = double(a) / double(b);

            int dd = round(d*p10);
            int ndd0 = int(floor(nd*p10));
            int ndd1 = int(ceil(nd*p10));
            int ndd2 = int(round(nd*p10));

//            cout << d << ' ' << dd << endl;
//            cout << a << ' ' << b << ' ' << dd << ' ' << ndd0 << ' ' << ndd1 << ' ' << ndd2 << endl;

            return dd==ndd0 || dd==ndd1 || dd==ndd2;
        };

        int b = 1;
        int a = -1;

        while(a==-1){

            b *= 2;

            int a0 = ceil(d*double(b));
            int a1 = floor(d*double(b));

            if(check(a0, b)){
                a = a0;
                break;
            }

            if(check(a1, b)){
                a = a1;
                break;
            }
        }

        if(i){
            cout << i << ' ';
        }
        cout << a << '/' << b << '"' << endl;
    }
}
