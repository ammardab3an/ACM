#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t; while(t--){

        long long int a, b, c, d, rem, rep;
        cin >> a >> b >> c >> d;

        if(b >= a){
            cout << b << endl;
            continue;
        }
        if(c <= d){
            cout << -1 << endl;
            continue;
        }

        rem = a-b;
        rep = (rem + c - d -1) / (c-d);
        cout << b + rep * c << endl;
    }
}
